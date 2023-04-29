// Implementation of class handling Window Requests

#include <cstdio>              
#include "oslib/wimp.h"
#include "salib/rectangle.h"
#include "salib/windowobserver.h"

namespace SALib {

namespace Wimp {

void SALib::Wimp::OpenWindowRequestObserver::Update(const unsigned* blockPtr) const
{
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(*blockPtr);

   if (m_windowToOpen.IsMessageForMe(requestedWindowHandle)) {
      m_windowToOpen.OpenRequest(blockPtr);
   }
}


void SALib::Wimp::CloseWindowRequestObserver::Update(const unsigned* blockPtr) const
{
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(*blockPtr);

   if (m_windowToClose.IsMessageForMe(requestedWindowHandle)) {
      m_windowToClose.Close();
   }
}


void SALib::Wimp::RedrawWindowRequestObserver::Update(const unsigned* blockPtr) const
{
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(*blockPtr);

   if (m_windowToRedraw.IsMessageForMe(requestedWindowHandle)) {
      wimp_draw redrawResponse = { 0 };
      redrawResponse.w = reinterpret_cast<wimp_w>(requestedWindowHandle);
      osbool moreToDraw = wimp_redraw_window(&redrawResponse);

      while (moreToDraw) {
         const Rectangle visibleArea = *reinterpret_cast<Rectangle*>(&redrawResponse.box);
         const int scrollXOffset = redrawResponse.xscroll;
         const int scrollYOffset = redrawResponse.yscroll;
         const Rectangle currentGraphicsWindow = *reinterpret_cast<Rectangle*>(&redrawResponse.clip);

         m_windowToRedraw.RedrawRectangle(visibleArea, scrollXOffset, scrollYOffset, currentGraphicsWindow);
         moreToDraw = wimp_get_rectangle(&redrawResponse);
      }
   }
}


void SALib::Wimp::PointerActionWindowObserver::Update(const unsigned* blockPtr) const
{
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(*blockPtr);

   if (m_window.IsMessageForMe(requestedWindowHandle)) {
      m_actionCommand.Execute();
   }
}

}

}