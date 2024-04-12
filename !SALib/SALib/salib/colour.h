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

class RGBColour {
public:
   RGBColour(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
      : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

   unsigned char Red(  void) const { return m_red;   }
   unsigned char Green(void) const { return m_green; }
   unsigned char Blue( void) const { return m_blue;  }
   unsigned char Alpha(void) const { return m_alpha; }

   unsigned GetBGRAValue(void) const {
      return (static_cast<unsigned>(m_red  ) <<  8) +
             (static_cast<unsigned>(m_green) << 12) +
             (static_cast<unsigned>(m_blue ) << 24) +
              static_cast<unsigned>(m_alpha);
   }

private:
   const unsigned char m_red;
   const unsigned char m_green;
   const unsigned char m_blue;
   const unsigned char m_alpha;
};

void SetColour(const Colour colour);

RGBColour WimpColourToRGBColour(const Colour colour);

}

}

}

#endif // SALIB_WIMP_COLOURS_H