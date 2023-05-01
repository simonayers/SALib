// Class for handling mouse click commands

#ifndef SALIB_WIMP_MOUSECOMMAND_H
#define SALIB_WIMP_MOUSECOMMAND_H

#include "rectangle.h"

namespace SALib {

namespace Wimp {

   class MouseClickCommandBase {
   public:
      virtual ~MouseClickCommandBase(void) {}

      virtual void ProcessClick(const int screenXPos, const int screenYPos,
                                const int button, const int iconHandle) const = 0;
   };

   class DraggingEndedCommandBase {
   public:
      virtual ~DraggingEndedCommandBase(void) {}

      virtual void Process(const Rectangle dragBox) const = 0;
   };

}

}

#endif  // SALIB_WIMP_MOUSECOMMAND_H

