// Implementation of class handling Mouse Clicks
                             
#include "oslib/wimp.h"
#include "salib/keyobserver.h"
#include "salib/keycommand.h"
#include "salib/reporter.h"

namespace SALib {

namespace Wimp {

void KeyPressObserver::Update(const unsigned* blockPtr) const
{
   SALib::Reporter::Report("Key pressed");

   const wimp_key* keyBlock = reinterpret_cast<const wimp_key*>(blockPtr);
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(keyBlock->w);

   if (m_window.IsMessageForMe(requestedWindowHandle)) {
      const int iconHandle          = static_cast<int>(keyBlock->i);
      const int caretXOffset        = keyBlock->pos.x;
      const int caretYOffset        = keyBlock->pos.y;
      const int caretHeightAndFlags = keyBlock->height;
      const int caretStringIndex    = keyBlock->index;
      const int characterCode       = static_cast<int>(keyBlock->c);

      m_command.ProcessKeyPress(iconHandle, caretXOffset, caretYOffset, caretHeightAndFlags, caretStringIndex, characterCode);
   }
}

}

}