// Implementation of class to represent windows

#include <cstring>
#include "oslib/wimp.h"
#include "window.h"

namespace SALib {

namespace Wimp {

Window::Window(const std::string windowTitle)
      : m_windowTitle(windowTitle)
{
   // Default window implementation

   wimp_window windowBlock;

   windowBlock.visible.x0 = 200;
   windowBlock.visible.y0 = 200;
   windowBlock.visible.x1 = 600;
   windowBlock.visible.y1 = 600;

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

Window::~Window(void)
{
   wimp_delete_window(reinterpret_cast<wimp_w>(m_handle));
   m_handle = 0;  // Don't really need to do this but what the hell!
}

void Window::Open(void)
{
   wimp_open wimpOpenBlock;

   wimpOpenBlock.w = reinterpret_cast<wimp_w>(m_handle);
   wimpOpenBlock.visible.x0 = 1200;
   wimpOpenBlock.visible.y0 = 1200;
   wimpOpenBlock.visible.x1 = 1600;
   wimpOpenBlock.visible.y1 = 1600;

   wimpOpenBlock.xscroll = 0;
   wimpOpenBlock.yscroll = 0;

   wimpOpenBlock.next = wimp_TOP;

   wimp_open_window(&wimpOpenBlock);
}

void Window::Close(void)
{
   wimp_close_window(reinterpret_cast<wimp_w>(m_handle));
}


}

}