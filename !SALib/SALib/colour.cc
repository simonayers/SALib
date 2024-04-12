// Class for Wimp colours
                          
#include "oslib/wimp.h"
#include "salib/colour.h"

namespace SALib {

namespace Wimp {

namespace Colour {

void SetColour(const Colour colour)
{
   wimp_set_colour(static_cast<wimp_colour>(colour));
}


RGBColour WimpColourToRGBColour(const Colour colour)
{
   switch (colour) {
      case White:          return RGBColour(0xFFu, 0xFFu, 0xFFu, 0x00u);
      case VeryLightGrey:  return RGBColour(0xDDu, 0xDDu, 0xDDu, 0x00u);
      case LightGrey:      return RGBColour(0xBBu, 0xBBu, 0xBBu, 0x00u);
      case MidLightGrey:   return RGBColour(0x99u, 0x99u, 0x99u, 0x00u);
      case MidDarkGrey:    return RGBColour(0x77u, 0x77u, 0x77u, 0x00u);
      case DarkGrey:       return RGBColour(0x55u, 0x55u, 0x55u, 0x00u);
      case VeryDarkGrey:   return RGBColour(0x33u, 0x33u, 0x33u, 0x00u);
      case Black:          return RGBColour(0x00u, 0x00u, 0x00u, 0x00u);

      case LightBlue:      return RGBColour(0x00u, 0xBBu, 0xFFu, 0x00u);
      case DarkBlue:       return RGBColour(0x00u, 0x44u, 0x99u, 0x00u);

      case LightGreen:     return RGBColour(0x00u, 0xCCu, 0x00u, 0x00u);
      case DarkGreen:      return RGBColour(0x55u, 0x88u, 0x00u, 0x00u);

      case Cream:          return RGBColour(0xEEu, 0xEEu, 0xBBu, 0x00u);
      case Yellow:         return RGBColour(0x00u, 0xFFu, 0xFFu, 0x00u);
      case Orange:         return RGBColour(0xFFu, 0xBBu, 0x00u, 0x00u);
      case Red:            return RGBColour(0xFFu, 0x00u, 0x00u, 0x00u);

      case Transparent:    return RGBColour(0xFFu, 0xFFu, 0xFFu, 0xFFu);
   }
   return RGBColour(0x00u, 0x00u, 0x00u, 0x00u);
}

}

}

}
