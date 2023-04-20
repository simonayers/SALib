// Implementation of class handling Close Window Requests

#include <cstdio>
#include "closewindowobserver.h"
#include "oslib/wimp.h"

namespace SALib {

namespace Wimp {

void SALib::Wimp::CloseWindowRequestObserver::Update(const unsigned* blockPtr) const
{
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(*blockPtr);

   if (m_windowToClose.IsMessageForMe(requestedWindowHandle)) {
      m_windowToClose.Close();
   }
}


}

}