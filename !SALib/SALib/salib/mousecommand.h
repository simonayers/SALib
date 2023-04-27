// Class for handling mouse click commands

#ifndef SALIB_WIMP_MOUSECOMMAND_H
#define SALIB_WIMP_MOUSECOMMAND_H

namespace SALib {

namespace Wimp {

   class MouseClickCommandBase {
   public:
      virtual ~MouseClickCommandBase(void) {}

      virtual void ProcessClick(const int screenXPos, const int screenYPos,
                                const int button, const int iconHandle) const = 0;
   };
}

}


#endif  // SALIB_WIMP_MOUSECOMMAND_H

