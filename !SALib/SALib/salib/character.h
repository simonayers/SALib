// Character code definitions

#ifndef SALIB_WIMP_CHARACTER_H
#define SALIB_WIMP_CHARACTER_H

namespace SALib {

namespace Wimp {

namespace CharacterCode {

enum CharacterCode {

   Backspace         = 0x0008,
   Enter             = 0x000D,  // Can't use Return as it is a C++ keyword
   Escape            = 0x001B,
   Home              = 0x001E,
   Delete            = 0x007F,

   // Shift and Ctrl can be held with the below.  The value of the base
   // key is OR'd with Shift or Ctrl

   Shift             = 0x0010,
   Ctrl              = 0x0020,

   Print             = 0x0180,
   Insert            = 0x01CD,

   F1                = 0x0181,
   F2                = 0x0182,
   F3                = 0x0183,
   F4                = 0x0184,
   F5                = 0x0185,
   F6                = 0x0186,
   F7                = 0x0187,
   F8                = 0x0188,
   F9                = 0x0189,
   F10               = 0x01CA,
   F11               = 0x01CB,
   F12               = 0x01CC,

   Tab               = 0x018A,
   End               = 0x018B,

   Left              = 0x018C,
   Right             = 0x018D,
   Down              = 0x018E,
   Up                = 0x018F,

// PageDown and PageUp of course do not follow the Shift/Ctrl template so have
// to be addressed individually.  I need to verify this is real.

   PageDown          = 0x019E,
   PageDownShift     = 0x018E,
   PageDownCtrl      = 0x01BE,
   PageDownShiftCtrl = 0x01AE,
   PageUp            = 0x019F,
   PageUpShift       = 0x018F,
   PageUpCtrl        = 0x01BF,
   PageUpShiftCtrl   = 0x01AF,

};

}

}

}

#endif // SALIB_WIMP_CHARACTER_H
