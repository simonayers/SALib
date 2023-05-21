// Functions for manipulating the Caret
                        
#include "oslib/wimp.h"
#include "salib/caret.h"

namespace SALib {

namespace Wimp {

namespace Caret {

void SetPositionIcon(const Window& window, const Icon& icon, const int stringIndex)
{
   const int xOffset = 0;
   const int yOffset = 0;
   const int height  = -1; // Get Wimp to calculate offsets using icon index

   wimp_set_caret_position(reinterpret_cast<wimp_w>(window.GetWindowHandle()),
                           static_cast<wimp_i>(icon.GetIconHandle()),
                           xOffset, yOffset, height, stringIndex);
}

void SetPositionNoIcon(const Window& window, const int xOffset, const int yOffset, const bool caretVisible)
{
   const int icon = -1;
   const int height = 20 + (caretVisible ? 0 : (1 << 25));
   const int stringIndex = 0;

   wimp_set_caret_position(reinterpret_cast<wimp_w>(window.GetWindowHandle()),
                           icon, xOffset, yOffset, height, stringIndex);
}

}

}

}