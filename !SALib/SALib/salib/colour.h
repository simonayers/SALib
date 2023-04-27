// Class for Wimp colours

#ifndef SALIB_WIMP_COLOURS_H
#define SALIB_WIMP_COLOURS_H

namespace SALib {

namespace Wimp {

namespace Colour {

enum Colour {

   White         = 0x00u,
   VeryLightGrey = 0x01u,
   LightGrey     = 0x02u,
   MidLightGrey  = 0x03u,
   MidDarkGrey   = 0x04u,
   DarkGrey      = 0x05u,
   VeryDarkGrey  = 0x06u,
   Black         = 0x07u,

   LightBlue     = 0x0Fu,
   DarkBlue      = 0x08u,

   LightGreen    = 0x0Au,
   DarkGreen     = 0x0Du,

   Cream         = 0x0Cu,
   Yellow        = 0x09u,
   Orange        = 0x0Eu,
   Red           = 0x0Bu,

   Transparent   = 0xFFFFFFFFu

};

void SetColour(const Colour colour);

}

}

}

#endif // SALIB_WIMP_COLOURS_H