// Classes for building Icon definitions

#include "oslib/wimp.h"
#include "salib/font.h"
#include "salib/iconbuilder.h"

namespace SALib {

namespace Wimp {

unsigned IconFlagsBuilder::GetFlags(void) const
{
   unsigned flags = m_buttonType << 12;

   if (m_iconText)              { flags |= wimp_ICON_TEXT; }
   if (m_iconSprite)            { flags |= wimp_ICON_SPRITE; }
   if (m_iconBorder)            { flags |= wimp_ICON_BORDER; }
   if (m_iconHCentred)          { flags |= wimp_ICON_HCENTRED; }
   if (m_iconVCentred)          { flags |= wimp_ICON_VCENTRED; }
   if (m_iconFilled)            { flags |= wimp_ICON_FILLED; }

   if (m_iconAntiAliased) {
      if (m_iconFont) {
         if (m_iconFont->IsLoaded()) {
            flags |= static_cast<unsigned>(m_iconFont->GetHandle()) << wimp_ICON_FONT_HANDLE_SHIFT;
            flags |= wimp_ICON_ANTI_ALIASED;
         }
      } 
   } else {
      flags |= m_iconFGColour << wimp_ICON_FG_COLOUR_SHIFT;
      flags |= m_iconBGColour << wimp_ICON_BG_COLOUR_SHIFT;
   }

   if (m_iconNeedsHelp)         { flags |= wimp_ICON_NEEDS_HELP; }
   if (m_iconIndirected)        { flags |= wimp_ICON_INDIRECTED; }
   if (m_iconRJustified)        { flags |= wimp_ICON_RJUSTIFIED; }
   if (m_iconAllowAdjust)       { flags |= wimp_ICON_ALLOW_ADJUST; }
   if (m_iconHalfSize)          { flags |= wimp_ICON_HALF_SIZE; }
   if (m_iconButtonType)        { flags |= wimp_ICON_BUTTON_TYPE; }
   if (m_iconESG)               { flags |= wimp_ICON_ESG; }
   if (m_iconSelected)          { flags |= wimp_ICON_SELECTED; }
   if (m_iconShaded)            { flags |= wimp_ICON_SHADED; }
   if (m_iconDeleted)           { flags |= wimp_ICON_DELETED; }

   return flags;
}

}

}