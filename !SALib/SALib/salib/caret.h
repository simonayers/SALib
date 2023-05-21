// Functions for manipulating the Caret

#ifndef SALIB_WIMP_CARET_H
#define SALIB_WIMP_CARET_H

#include "window.h"
#include "icon.h"

namespace SALib {

namespace Wimp {

namespace Caret {

void SetPositionIcon(const Window& window, const Icon& icon, const int stringIndex);
void SetPositionNoIcon(const Window& window, const int xOffset, const int yOffset, const bool caretVisible);

}

}

}

#endif // SALIB_WIMP_CARET_H