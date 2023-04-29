// Implementation of class to represent windows

#include <cstring>
#include <cstdio> // temp
#include "oslib/wimp.h"
#include "salib/utilities.h"
#include "salib/window.h"


namespace SALib {

namespace Wimp {

Window::Window(const std::string windowTitle, const int width, const int height, const Window* parent)
      : m_windowTitle(windowTitle), m_windowWidth(width), m_windowHeight(height), m_parent(parent)
{
   // Default window implementation

   wimp_window windowBlock;

   windowBlock.visible.x0 = 200;
   windowBlock.visible.y0 = 200;
   windowBlock.visible.x1 = windowBlock.visible.x0 + m_windowWidth;
   windowBlock.visible.y1 = windowBlock.visible.y0 + m_windowHeight;

   windowBlock.xscroll = 0;
   windowBlock.yscroll = 0;

   const wimp_w TOP_OF_WINDOW_STACK = reinterpret_cast<wimp_w>(-1);
   windowBlock.next = TOP_OF_WINDOW_STACK;

   const wimp_window_flags windowFlags = wimp_WINDOW_MOVEABLE
                                       | wimp_WINDOW_AUTO_REDRAW
                                       | wimp_WINDOW_BOUNDED_ONCE
                                       | wimp_WINDOW_SCROLL_REPEAT
                                       | wimp_WINDOW_SCROLL
                                       | wimp_WINDOW_BACK_ICON
                                       | wimp_WINDOW_CLOSE_ICON
                                       | wimp_WINDOW_TITLE_ICON
                                       | wimp_WINDOW_TOGGLE_ICON
                                       | wimp_WINDOW_VSCROLL
                                       | wimp_WINDOW_SIZE_ICON
                                       | wimp_WINDOW_HSCROLL
                                       | wimp_WINDOW_NEW_FORMAT;
   windowBlock.flags = windowFlags;

   windowBlock.title_fg = wimp_COLOUR_BLACK;
   windowBlock.title_bg = wimp_COLOUR_LIGHT_GREY;

   windowBlock.work_fg  = wimp_COLOUR_BLACK;
   windowBlock.work_bg  = wimp_COLOUR_WHITE;

   windowBlock.scroll_outer = wimp_COLOUR_MID_LIGHT_GREY;
   windowBlock.scroll_inner = wimp_COLOUR_VERY_LIGHT_GREY;

   windowBlock.highlight_bg = wimp_COLOUR_CREAM;

   windowBlock.extra_flags = 0;

   windowBlock.extent.x0 = 0;
   windowBlock.extent.y0 = -1000;
   windowBlock.extent.x1 = 1000;
   windowBlock.extent.y1 = 0;

   windowBlock.title_flags = wimp_ICON_TEXT
                           | wimp_ICON_BORDER
                           | wimp_ICON_HCENTRED
                           | wimp_ICON_VCENTRED
                           | wimp_ICON_FILLED;

   windowBlock.work_flags = wimp_BUTTON_NEVER
                         << wimp_ICON_BUTTON_TYPE_SHIFT;

   windowBlock.sprite_area = reinterpret_cast<osspriteop_area*>(1);

   windowBlock.xmin = 0;
   windowBlock.ymin = 0;

   std::strncpy(windowBlock.title_data.text, m_windowTitle.c_str(), 12);
   windowBlock.icon_count = 0;

   m_handle = reinterpret_cast<unsigned>(wimp_create_window(&windowBlock));
}


Window::Window(const WindowBuilder& builder, const Window* parent)
   : m_windowTitle(builder.GetWindowTitle()), m_windowWidth(builder.GetWindowVisibleWidth()),
     m_windowHeight(builder.GetWindowVisibleHeight()), m_parent(parent)
{
   // Default window implementation

   wimp_window windowBlock;

   windowBlock.visible.x0 = builder.GetWindowXScrollOffset();
   windowBlock.visible.y0 = builder.GetWindowYScrollOffset();
   windowBlock.visible.x1 = windowBlock.visible.x0 + builder.GetWindowVisibleWidth();
   windowBlock.visible.y1 = windowBlock.visible.y0 + builder.GetWindowVisibleHeight();

   windowBlock.xscroll = builder.GetWindowXScrollOffset();
   windowBlock.yscroll = builder.GetWindowYScrollOffset();

   const wimp_w TOP_OF_WINDOW_STACK = reinterpret_cast<wimp_w>(-1);
   windowBlock.next = TOP_OF_WINDOW_STACK;

   windowBlock.flags = static_cast<wimp_window_flags>(builder.GetWindowFlags());

   windowBlock.title_fg = static_cast<wimp_colour>(builder.GetWindowTitleForegroundColour());
   windowBlock.title_bg = static_cast<wimp_colour>(builder.GetWindowTitleBackgroundColour());

   windowBlock.work_fg  = static_cast<wimp_colour>(builder.GetWindowWorkAreaForegroundColour());
   windowBlock.work_bg  = static_cast<wimp_colour>(builder.GetWindowWorkBackForegroundColour());

   windowBlock.scroll_outer = static_cast<wimp_colour>(builder.GetWindowScrollOuterColour());
   windowBlock.scroll_inner = static_cast<wimp_colour>(builder.GetWindowScrollInnerColour());

   windowBlock.highlight_bg = static_cast<wimp_colour>(builder.GetWindowHighlightBackgroundColour());

   windowBlock.extra_flags = 0;

   windowBlock.extent.x0 = 0;
   windowBlock.extent.y0 = 0 - builder.GetWindowExtentHeight();
   windowBlock.extent.x1 = builder.GetWindowExtentWidth();
   windowBlock.extent.y1 = 0;

   windowBlock.title_flags = wimp_ICON_TEXT
                           | wimp_ICON_BORDER
                           | wimp_ICON_HCENTRED
                           | wimp_ICON_VCENTRED
                           | wimp_ICON_FILLED;

   windowBlock.work_flags = wimp_BUTTON_NEVER
                         << wimp_ICON_BUTTON_TYPE_SHIFT;

   windowBlock.sprite_area = reinterpret_cast<osspriteop_area*>(1);

   windowBlock.xmin = 0;
   windowBlock.ymin = 0;

   std::strncpy(windowBlock.title_data.text, m_windowTitle.c_str(), 12);
   windowBlock.icon_count = 0;

   m_handle = reinterpret_cast<unsigned>(wimp_create_window(&windowBlock));

}


Window::~Window(void)
{
   wimp_delete_window(reinterpret_cast<wimp_w>(m_handle));
   m_handle = 0;  // Don't really need to do this but what the hell!
}

void Window::Open(void)
{
   int xPos = (Utilities::GetScreenWidthOSUnits() - m_windowWidth) / 2;
   int yPos = (Utilities::GetScreenHeightOSUnits() - m_windowHeight) / 2;
   OpenAt(xPos, yPos);
}

void Window::OpenAt(const int xPos, const int yPos)
{
   wimp_window_state windowState;
   windowState.w = reinterpret_cast<wimp_w>(m_handle);
   wimp_get_window_state(&windowState);

   if (!(windowState.flags & wimp_WINDOW_OPEN)) {
      windowState.visible.x0 = xPos;
      windowState.visible.y0 = yPos;
      windowState.visible.x1 = xPos + m_windowWidth;
      windowState.visible.y1 = yPos + m_windowHeight;

      windowState.xscroll = 0;
      windowState.yscroll = 0;
   } else {
      windowState.visible.x0 = xPos;
      windowState.visible.y0 = yPos;
      windowState.visible.x1 = xPos + m_windowWidth;
      windowState.visible.y1 = yPos + m_windowHeight;
   }

   windowState.next = wimp_TOP;

   //wimp_open_window(reinterpret_cast<wimp_open*>(&windowState));
   wimp_w parentWindow = m_parent ? reinterpret_cast<wimp_w>(m_parent->m_handle) : reinterpret_cast<wimp_w>(-1);
   wimp_open_window_nested(reinterpret_cast<wimp_open*>(&windowState), parentWindow, wimp_CHILD_LINKS_PARENT_WORK_AREA);

   m_windowWidth  = windowState.visible.x1 - windowState.visible.x0;
   m_windowHeight = windowState.visible.y1 - windowState.visible.y0;

   OnOpen();
}

void Window::OpenRequest(const unsigned* blockPtr)
{
   wimp_open* windowState = reinterpret_cast<wimp_open*>(const_cast<unsigned*>(blockPtr));
   //wimp_open_window(windowState);
   wimp_w parentWindow = m_parent ? reinterpret_cast<wimp_w>(m_parent->m_handle) : reinterpret_cast<wimp_w>(-1);
   wimp_open_window_nested(windowState, parentWindow, wimp_CHILD_LINKS_PARENT_WORK_AREA);

   m_windowWidth  = windowState->visible.x1 - windowState->visible.x0;
   m_windowHeight = windowState->visible.y1 - windowState->visible.y0;

   OnOpen();
}

void Window::Close(void)
{
   wimp_close_window(reinterpret_cast<wimp_w>(m_handle));
   OnClose();
}

bool Window::IsWindowOpen(void) const
{
   wimp_window_state windowState;

   windowState.w = reinterpret_cast<wimp_w>(m_handle);
   wimp_get_window_state(&windowState);

   return (windowState.flags & wimp_WINDOW_OPEN) > 0U ? true : false;
}

void Window::SetVisibleWidth(const int width)
{
   m_windowWidth = width;
}

void Window::SetVisibleHeight(const int height)
{
   m_windowHeight = height;
}

int Window::GetVisibleLeftEdge(void) const
{
   wimp_window_state windowState;

   windowState.w = reinterpret_cast<wimp_w>(m_handle);
   wimp_get_window_state(&windowState);

   return windowState.visible.x0;
}

int Window::GetVisibleBottomEdge(void) const
{
   wimp_window_state windowState;

   windowState.w = reinterpret_cast<wimp_w>(m_handle);
   wimp_get_window_state(&windowState);

   return windowState.visible.y0;
}

void Window::RedrawRectangle(const Rectangle visibleArea, const int scrollXOffset, const int scrollYOffset, const Rectangle currentGraphicsWindow) const
{
    (void)visibleArea;
    (void)scrollXOffset;
    (void)scrollYOffset;
    (void)currentGraphicsWindow;
}

void Window::ForceRedraw(void) const
{
   wimp_outline windowOutline;

   windowOutline.w = reinterpret_cast<wimp_w>(m_handle);
   wimp_get_window_outline(&windowOutline);

   wimp_force_redraw(windowOutline.w, windowOutline.outline.x0, windowOutline.outline.y0, windowOutline.outline.x1, windowOutline.outline.y1);
}

void Window::UpdateWindow(void) const
{
   wimp_window_info windowInfo = { 0 };
   windowInfo.w = reinterpret_cast<wimp_w>(m_handle);
   wimp_get_window_info(&windowInfo);

   wimp_draw wimpDraw = { 0 };
   wimpDraw.w = reinterpret_cast<wimp_w>(m_handle);

   wimpDraw.box.x0 = windowInfo.extent.x0;
   wimpDraw.box.y0 = windowInfo.extent.y0;
   wimpDraw.box.x1 = windowInfo.extent.x1;
   wimpDraw.box.y1 = windowInfo.extent.y1;

   osbool moreToDraw = wimp_update_window(&wimpDraw);

   while (moreToDraw) {
      const Rectangle visibleArea = *reinterpret_cast<Rectangle*>(&wimpDraw.box);
      const int scrollXOffset = wimpDraw.xscroll;
      const int scrollYOffset = wimpDraw.yscroll;
      const Rectangle currentGraphicsWindow = *reinterpret_cast<Rectangle*>(&wimpDraw.clip);

      RedrawRectangle(visibleArea, scrollXOffset, scrollYOffset, currentGraphicsWindow);
      moreToDraw = wimp_get_rectangle(&wimpDraw);
   }
}

}

}