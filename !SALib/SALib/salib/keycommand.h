// Class for handling Key Press commands

#ifndef SALIB_WIMP_KEYCOMMAND_H
#define SALIB_WIMP_KEYCOMMAND_H

namespace SALib {

namespace Wimp {

   class KeyPressCommandBase {
   public:
      virtual ~KeyPressCommandBase(void) {}

      virtual void ProcessKeyPress(const int iconHandle, const int caretXOffset, const int caretYOffset,
                                   const int caretHeightAndFlags, const int caretStringIndex,
                                   const int characterCode) const = 0;
   };

}

}

#endif  // SALIB_WIMP_KEYCOMMAND_H
