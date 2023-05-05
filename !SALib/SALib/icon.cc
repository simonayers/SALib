// Class for handling icons

#include <cstring>
#include "oslib/wimp.h"
#include "salib/icon.h"
#include "salib/iconbuilder.h"
#include "salib/rectangle.h"
#include "salib/window.h"

namespace SALib {

namespace Wimp {

static int Icon_CreateIcon(const IconBuilder& iconBuilder, const Window& window)
{
   wimp_icon_create iconBlock;

   iconBlock.w = reinterpret_cast<wimp_w>(window.GetWindowHandle());

   iconBlock.icon.extent.x0 = iconBuilder.GetExtent().xPos0;
   iconBlock.icon.extent.y0 = iconBuilder.GetExtent().yPos0;
   iconBlock.icon.extent.x1 = iconBuilder.GetExtent().xPos1;
   iconBlock.icon.extent.y1 = iconBuilder.GetExtent().yPos1;

// Just going to worry about sprite icons for the moment.
   iconBlock.icon.flags = static_cast<wimp_icon_flags>(iconBuilder.GetIconFlags());

   if (iconBuilder.GetIconDataBuilder().GetSpriteName().size() > 0) {   // Icon has a sprite
      if (iconBuilder.GetIconDataBuilder().GetSpriteName().size() <= osspriteop_NAME_LIMIT) {
         std::strncpy(iconBlock.icon.data.sprite, iconBuilder.GetIconDataBuilder().GetSpriteName().c_str(), osspriteop_NAME_LIMIT);
      } else {
         // Indirect
      }
   }

   return wimp_create_icon(&iconBlock);
}

Icon::Icon(const IconBuilder& iconBuilder, const Window& window)
   : m_window(window),
     m_iconHandle(Icon_CreateIcon(iconBuilder, window))
{

}

Icon::~Icon(void)
{
   wimp_delete_icon(reinterpret_cast<wimp_w>(m_window.GetWindowHandle()), static_cast<wimp_i>(m_iconHandle)); 
}

}

}