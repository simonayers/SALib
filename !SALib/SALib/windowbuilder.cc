// Class to help build Wimp windows

#include "oslib/wimp.h"
#include "salib/windowbuilder.h"

namespace SALib {

namespace Wimp {


unsigned WindowBuilder::WindowFlagsBuilder::GetFlags(void) const
{
   unsigned flags = 0;

   if (m_movable)                                        { flags |= wimp_WINDOW_MOVEABLE; }
   if (m_autoRedraw)                                     { flags |= wimp_WINDOW_AUTO_REDRAW; }
   if (m_isPane)                                         { flags |= wimp_WINDOW_PANE; }
   if (m_canBeOpenedOutsideScreen)                       { flags |= wimp_WINDOW_NO_BOUNDS; }
   if (m_returnScrollRequestEventWithAutoRepeat)         { flags |= wimp_WINDOW_SCROLL_REPEAT; }
   if (m_returnScrollRequestEventWithoutAutoRepeat)      { flags |= wimp_WINDOW_SCROLL; }
   if (m_coloursAsGCOLNumbers)                           { flags |= wimp_WINDOW_REAL_COLOURS; }
   if (m_belongsToBackgroundWindowStacks)                { flags |= wimp_WINDOW_BACK; }
   if (m_detectKeypresses)                               { flags |= wimp_WINDOW_HOT_KEYS; }
   if (m_forceWindowToStayOnScreen)                      { flags |= wimp_WINDOW_BOUNDED; }
   if (m_ignoreRightExtentAdjustSizeIcon)                { flags |= wimp_WINDOW_IGNORE_XEXTENT; }
   if (m_ignoreBottomExtentWhenDraggingAdjustSizeIcon)   { flags |= wimp_WINDOW_IGNORE_YEXTENT; }
   if (m_forceWindowToScreenOnNextOpenWindow)            { flags |= wimp_WINDOW_BOUNDED_ONCE; }
   if (m_hasBackIcon)                                    { flags |= wimp_WINDOW_BACK_ICON; }
   if (m_hasCloseIcon)                                   { flags |= wimp_WINDOW_CLOSE_ICON; }
   if (m_hasTitleBar)                                    { flags |= wimp_WINDOW_TITLE_ICON; }
   if (m_hasToggleSizeIcon)                              { flags |= wimp_WINDOW_TOGGLE_ICON; }
   if (m_hasVertialScrollbar)                            { flags |= wimp_WINDOW_VSCROLL; }
   if (m_hasAdjustSizeIcon)                              { flags |= wimp_WINDOW_SIZE_ICON; }
   if (m_hasHorizontalScrollbar)                         { flags |= wimp_WINDOW_HSCROLL; }
   if (m_newFormat)                                      { flags |= wimp_WINDOW_NEW_FORMAT; }

   return flags;
}

static WindowBuilder::WindowFlagsBuilder DefaultWindowFlags(void)
{

}

// Default values build a generic window
WindowBuilder::WindowBuilder(void)
   :  m_windowFlags(DefaultWindowFlags()),
      m_windowTitle(""),

      m_windowExtentWidth(400),
      m_windowExtentHeight(400),

      m_windowVisibleWidth(400),
      m_windowVisibleHeight(400),

      m_windowXScrollOffset(0),
      m_windowYScrollOffset(0),

      m_windowTitleForegroundColour(Colour::Black),
      m_windowTitleBackgroundColour(Colour::LightGrey),

      m_windowWorkAreaForegroundColour(Colour::Black),
      m_windowWorkAreaBackgroundColour(Colour::White),

      m_windowScrollOuterColour(Colour::MidLightGrey),
      m_windowScrollInnerColour(Colour::VeryLightGrey),

      m_windowHighlightBackgroundColour(Colour::Cream),

      m_windowButtonType(IgnoreAllClicks)
{

}


}

}
