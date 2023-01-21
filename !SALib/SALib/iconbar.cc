// Class for handling icons on the iconbar

#include <cstring>
#include "iconbar.h"
#include "oslib/wimp.h"


static unsigned IconBar_CreateIconbarIcon(wimp_w iconPosition, const std::string& spriteName, const std::string& iconText, std::string& validationString)
{
   wimp_icon_create iconBarIconCreate;

   iconBarIconCreate.w = iconPosition;

   iconBarIconCreate.icon.flags = wimp_ICON_SPRITE | (wimp_BUTTON_CLICK << wimp_ICON_BUTTON_TYPE_SHIFT);

   if (iconText.size() == 0) {
      std::strncpy(iconBarIconCreate.icon.data.sprite, spriteName.c_str(), osspriteop_NAME_LIMIT);

      iconBarIconCreate.icon.extent.x0 =  0;
      iconBarIconCreate.icon.extent.y0 =  0;
      iconBarIconCreate.icon.extent.x1 = 68;
      iconBarIconCreate.icon.extent.y1 = 68;
   } else {
      iconBarIconCreate.icon.flags |= wimp_ICON_TEXT
                                   |  wimp_ICON_INDIRECTED
                                   |  wimp_ICON_HCENTRED
                                   | (wimp_COLOUR_BLACK           << wimp_ICON_FG_COLOUR_SHIFT)
                                   | (wimp_COLOUR_VERY_LIGHT_GREY << wimp_ICON_BG_COLOUR_SHIFT);

      validationString = "S" + spriteName;
      iconBarIconCreate.icon.data.indirected_text_and_sprite.text       = const_cast<char*>(iconText.c_str());
      iconBarIconCreate.icon.data.indirected_text_and_sprite.validation = &validationString[0];
      iconBarIconCreate.icon.data.indirected_text_and_sprite.size       = iconText.size();

      iconBarIconCreate.icon.extent.x0 =   0;
      iconBarIconCreate.icon.extent.y0 = -16;
      iconBarIconCreate.icon.extent.x1 = 100;
      iconBarIconCreate.icon.extent.y1 =  88;
   }

   return wimp_create_icon(&iconBarIconCreate);
}


namespace SALib {

namespace Wimp {

IconBar::IconBar(const IconPosition iconPosition, const std::string& spriteName)
      : m_iconPosition(iconPosition), m_spriteName(spriteName), m_iconHandle(0)
{
   m_iconHandle = IconBar_CreateIconbarIcon(reinterpret_cast<wimp_w>(m_iconPosition), m_spriteName, m_iconText, m_validationString);
}


IconBar::IconBar(const IconPosition iconPosition, const std::string& spriteName, const std::string& iconText)
      : m_iconPosition(iconPosition), m_spriteName(spriteName), m_iconText(iconText), m_iconHandle(0)
{
   m_iconHandle = IconBar_CreateIconbarIcon(reinterpret_cast<wimp_w>(m_iconPosition), m_spriteName, m_iconText, m_validationString);
}

IconBar::~IconBar(void)
{

}

}  // namespace Wimp

}  // namespace SALib

