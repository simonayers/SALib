// Class to help build Wimp Windows

#ifndef WINDOWBUILDER_H
#define WINDOWBUILDER_H

#include <string>

namespace SALib {

namespace Wimp {

class WindowBuilder {
public:

   class WindowFlagsBuilder {
   public:
         WindowFlagsBuilder(void) :
            m_movable(                                     false),
            m_autoRedraw(                                  false),
            m_isPane(                                      false),
            m_canBeOpenedOutsideScreen(                    false),
            m_returnScrollRequestEventWithAutoRepeat(      false),
            m_returnScrollRequestEventWithoutAutoRepeat(   false),
            m_coloursAsGCOLNumbers(                        false),
            m_belongsToBackgroundWindowStacks(             false),
            m_detectKeypresses(                            false),
            m_forceWindowToStayOnScreen(                   false),
            m_ignoreRightExtentAdjustSizeIcon(             false),
            m_ignoreBottomExtentWhenDraggingAdjustSizeIcon(false),
            m_forceWindowToScreenOnNextOpenWindow(         false),
            m_hasBackIcon(                                 false),
            m_hasCloseIcon(                                false),
            m_hasTitleBar(                                 false),
            m_hasToggleSizeIcon(                           false),
            m_hasVertialScrollbar(                         false),
            m_hasAdjustSizeIcon(                           false),
            m_hasHorizontalScrollbar(                      false),
            m_newFormat(                                    true)  // For all cases in this library
            {}


         WindowFlagsBuilder& SetMovable(                                     void) { m_movable                                      = true; return *this; }
         WindowFlagsBuilder& SetAutoRedraw(                                  void) { m_autoRedraw                                   = true; return *this; }
         WindowFlagsBuilder& SetIsPane(                                      void) { m_isPane                                       = true; return *this; }
         WindowFlagsBuilder& SetCanBeOpenedOutsideScreen(                    void) { m_canBeOpenedOutsideScreen                     = true; return *this; }
         WindowFlagsBuilder& SetReturnScrollRequestEventWithAutoRepeat(      void) { m_returnScrollRequestEventWithAutoRepeat       = true; return *this; }
         WindowFlagsBuilder& SetReturnScrollRequestEventWithoutAutoRepeat(   void) { m_returnScrollRequestEventWithoutAutoRepeat    = true; return *this; }
         WindowFlagsBuilder& SetColoursAsGCOLNumbers(                        void) { m_coloursAsGCOLNumbers                         = true; return *this; }
         WindowFlagsBuilder& SetBelongsToBackgroundWindowStacks(             void) { m_belongsToBackgroundWindowStacks              = true; return *this; }
         WindowFlagsBuilder& SetDetectKeypresses(                            void) { m_detectKeypresses                             = true; return *this; }
         WindowFlagsBuilder& SetForceWindowToStayOnScreen(                   void) { m_forceWindowToStayOnScreen                    = true; return *this; }
         WindowFlagsBuilder& SetIgnoreRightExtentAdjustSizeIcon(             void) { m_ignoreRightExtentAdjustSizeIcon              = true; return *this; }
         WindowFlagsBuilder& SetIgnoreBottomExtentWhenDraggingAdjustSizeIcon(void) { m_ignoreBottomExtentWhenDraggingAdjustSizeIcon = true; return *this; }
         WindowFlagsBuilder& SetForceWindowToScreenOnNextOpenWindow(         void) { m_forceWindowToScreenOnNextOpenWindow          = true; return *this; }
         WindowFlagsBuilder& SetHasBackIcon(                                 void) { m_hasBackIcon                                  = true; return *this; }
         WindowFlagsBuilder& SetHasCloseIcon(                                void) { m_hasCloseIcon                                 = true; return *this; }
         WindowFlagsBuilder& SetHasTitleBar(                                 void) { m_hasTitleBar                                  = true; return *this; }
         WindowFlagsBuilder& SetHasToggleSizeIcon(                           void) { m_hasToggleSizeIcon                            = true; return *this; }
         WindowFlagsBuilder& SetHasVertialScrollbar(                         void) { m_hasVertialScrollbar                          = true; return *this; }
         WindowFlagsBuilder& SetHasAdjustSizeIcon(                           void) { m_hasAdjustSizeIcon                            = true; return *this; }
         WindowFlagsBuilder& SetHasHorizontalScrollbar(                      void) { m_hasHorizontalScrollbar                       = true; return *this; }

         unsigned GetFlags(void) const;

      private:
         bool m_movable;
         bool m_autoRedraw;
         bool m_isPane;
         bool m_canBeOpenedOutsideScreen;
         bool m_returnScrollRequestEventWithAutoRepeat;
         bool m_returnScrollRequestEventWithoutAutoRepeat;
         bool m_coloursAsGCOLNumbers;
         bool m_belongsToBackgroundWindowStacks;
         bool m_detectKeypresses;
         bool m_forceWindowToStayOnScreen;
         bool m_ignoreRightExtentAdjustSizeIcon;
         bool m_ignoreBottomExtentWhenDraggingAdjustSizeIcon;
         bool m_forceWindowToScreenOnNextOpenWindow;
         bool m_hasBackIcon;
         bool m_hasCloseIcon;
         bool m_hasTitleBar;
         bool m_hasToggleSizeIcon;
         bool m_hasVertialScrollbar;
         bool m_hasAdjustSizeIcon;
         bool m_hasHorizontalScrollbar;
         bool m_newFormat;
      };

   void SetWindowFlags(const WindowFlagsBuilder& windowFlags) { m_windowFlags = windowFlags; }
   unsigned GetWindowFlags(void) const { return m_windowFlags.GetFlags(); }

   void SetWindowTitle(const std::string& windowTitle) { m_windowTitle = windowTitle; }
   const std::string& GetWindowTitle(void) const { return m_windowTitle; }


   void SetWindowExtentWidth(const int windowExtentWidth) { m_windowExtentWidth = windowExtentWidth; };
   int  GetWindowExtentWidth(void) const { return m_windowExtentWidth; }

   void SetWindowExtentHeight(const int windowExtentHeight) { m_windowExtentHeight = windowExtentHeight; }
   int  GetWindowExtentHeight(void) const { return m_windowExtentHeight; }

   void SetWindowVisibleWidth(const int windowVisibleWidth) { m_windowVisibleWidth = windowVisibleWidth; };
   int  GetWindowVisibleWidth(void) const { return m_windowVisibleWidth; }

   void SetWindowVisibleHeight(const int windowVisibleHeight) { m_windowVisibleHeight = windowVisibleHeight; }
   int  GetWindowVisibleHeight(void) const { return m_windowVisibleHeight; }


   void SetWindowXScrollOffset(const int windowXScrollOffset) { m_windowXScrollOffset = windowXScrollOffset; }
   int  GetWindowXScrollOffset(void) const { return m_windowXScrollOffset; }

   void SetWindowYScrollOffset(const int windowYScrollOffset) { m_windowYScrollOffset = windowYScrollOffset; }
   int  GetWindowYScrollOffset(void) const { return m_windowYScrollOffset; }

private:
   WindowFlagsBuilder m_windowFlags;
   std::string        m_windowTitle;

   int m_windowExtentWidth;
   int m_windowExtentHeight;

   int m_windowVisibleWidth;
   int m_windowVisibleHeight;

   int m_windowXScrollOffset;
   int m_windowYScrollOffset;

};

}

}

#endif // WINDOWBUILDER_H
