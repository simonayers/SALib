// Class for handling icons
                  
#include <cstdio>
#include <cstring>     

#include "oslib/os.h"
#include "oslib/wimp.h"
#include "salib/exception.h"
#include "salib/icon.h"
#include "salib/iconbuilder.h"
#include "salib/reporter.h"
#include "salib/rectangle.h"
#include "salib/window.h"

namespace SALib {

namespace Wimp {

Icon::Icon(const IconBuilder& iconBuilder, const Window& window, const unsigned maxTextSize)
   : m_window(window),
     m_iconHandle(0),
     m_spriteName(iconBuilder.GetIconDataBuilder().GetSpriteName()),
     m_text(iconBuilder.GetIconDataBuilder().GetText()),
     m_iconHidden(false)
{
   wimp_icon_create iconBlock;

   iconBlock.w = reinterpret_cast<wimp_w>(window.GetWindowHandle());

   iconBlock.icon.extent.x0 = iconBuilder.GetExtent().xPos0;
   iconBlock.icon.extent.y0 = iconBuilder.GetExtent().yPos0;
   iconBlock.icon.extent.x1 = iconBuilder.GetExtent().xPos1;
   iconBlock.icon.extent.y1 = iconBuilder.GetExtent().yPos1;

// Just going to worry about sprite icons and text icons for the moment.
   iconBlock.icon.flags = static_cast<wimp_icon_flags>(iconBuilder.GetIconFlags());

   m_validationString = iconBuilder.GetIconDataBuilder().GetValidation();

   if (m_spriteName.size() > 0) {   // Icon has a sprite
      if (m_spriteName.size() <= osspriteop_NAME_LIMIT) {   
         std::strncpy(iconBlock.icon.data.sprite, m_spriteName.c_str(), osspriteop_NAME_LIMIT);
      } else {
         // Indirect
      }
   } else {   // Icon is text only
      m_text.reserve(maxTextSize);

      iconBlock.icon.flags |= wimp_ICON_INDIRECTED;  // Force using indirected text

      if (iconBuilder.GetIconFlagsBuilder().GetAntiAliased()) {

         char tempValidationString[50] = {'\0'};

         snprintf(tempValidationString, sizeof(tempValidationString), "F%x%x",
                  iconBuilder.GetIconFlagsBuilder().GetIconBGColour() & 0xF,
                  iconBuilder.GetIconFlagsBuilder().GetIconFGColour() & 0xF);

         m_validationString = tempValidationString;
      }     

      iconBlock.icon.data.indirected_text.text = reinterpret_cast<char*>(&m_text[0]);
      iconBlock.icon.data.indirected_text.size = m_text.size() + 1;
      iconBlock.icon.data.indirected_text.validation = reinterpret_cast<char*>(&m_validationString[0]);
   }

   *const_cast<int*>(reinterpret_cast<const int*>(&m_iconHandle)) = wimp_create_icon(&iconBlock);
}

Icon::~Icon(void)
{
   wimp_delete_icon(reinterpret_cast<wimp_w>(m_window.GetWindowHandle()), static_cast<wimp_i>(m_iconHandle)); 
}


void Icon::Hide(void) const
{
   if (m_iconHidden) { return; }

   wimp_icon_flags eorBits   = wimp_ICON_DELETED | wimp_ICON_NEEDS_HELP;
   wimp_icon_flags clearBits = wimp_ICON_DELETED | wimp_ICON_NEEDS_HELP;

   os_error* err = xwimp_set_icon_state(reinterpret_cast<wimp_w>(m_window.GetWindowHandle()),
                                        static_cast<wimp_i>(m_iconHandle), eorBits, clearBits);
   if (err) {
      throw FatalException(err->errmess);
   }
   m_iconHidden = true;
}

void Icon::Unhide(void) const
{
   if (!m_iconHidden) { return; }

   wimp_icon_flags eorBits   = 0;
   wimp_icon_flags clearBits = wimp_ICON_DELETED | wimp_ICON_NEEDS_HELP;

   os_error* err = xwimp_set_icon_state(reinterpret_cast<wimp_w>(m_window.GetWindowHandle()),
                                        static_cast<wimp_i>(m_iconHandle), eorBits, clearBits);
   if (err) {
      throw FatalException(err->errmess);
   }
   m_iconHidden = false;
}


void Icon::Redraw(void) const
{
   wimp_set_icon_state(reinterpret_cast<wimp_w>(m_window.GetWindowHandle()), static_cast<wimp_i>(m_iconHandle),
                       static_cast<wimp_icon_flags>(0), static_cast<wimp_icon_flags>(0));
}

}

}