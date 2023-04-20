// Implementation of class handling Window Requests

#include <cstdio>
#include "salib/windowobserver.h"
#include "oslib/wimp.h"

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

}

}