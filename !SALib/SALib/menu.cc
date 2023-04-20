// Class for handling menus

#include <cstddef>
                       
#include "oslib/wimp.h"
#include "salib/menu.h"

namespace SALib {

namespace Wimp {

unsigned MenuEntry::MenuFlagsBuilder::GetFlags(void) const
{
   unsigned flags = 0;

   if (m_ticked)            { flags |= wimp_MENU_TICKED; }
   if (m_separate)          { flags |= wimp_MENU_SEPARATE; }
   if (m_writable)          { flags |= wimp_MENU_WRITABLE; }
   if (m_giveWarning)       { flags |= wimp_MENU_GIVE_WARNING; }
   if (m_subMenuWhenShaded) { flags |= wimp_MENU_SUB_MENU_WHEN_SHADED; }
   if (m_last)              { flags |= wimp_MENU_LAST; }
   if (m_titleIndirected)   { flags |= wimp_MENU_TITLE_INDIRECTED; }

   return flags;
}



MenuEntry::MenuEntry(const MenuFlagsBuilder& menuFlags, const Menu* subMenu, const IconFlagsBuilder& iconFlags, const IconDataBuilder& iconData,
                     const MenuSelectionCommandBase& menuSelectClickedCommand, const MenuSelectionCommandBase& menuAdjustClickedCommand)
   : m_menuFlags(menuFlags), m_subMenu(subMenu), m_iconFlags(iconFlags), m_iconData(iconData), m_menuSelectClickedCommand(&menuSelectClickedCommand), m_menuAdjustClickedCommand(&menuAdjustClickedCommand)
{

}

MenuEntry::~MenuEntry(void)
{

}

Menu* Menu::s_lastOpenedMenu = NULL;

Menu::Menu(const std::string& menuTitle)
      : m_menuTitle(menuTitle), m_lastXPos(-1), m_lastYPos(-1)
{

}

Menu::~Menu(void)
{

}

void Menu::AddEntry(const MenuEntry& menuEntry)
{
   m_menuEntries.push_back(menuEntry);
}


static wimp_icon_data ExtractIconData(const IconDataBuilder& iconDataBuilder)
{
// Just going to implement text for now

   wimp_icon_data iconData = { 0 };

   iconData.indirected_text.text = const_cast<char*>(iconDataBuilder.GetText().c_str());
   iconData.indirected_text.validation = const_cast<char*>("");
   iconData.indirected_text.size = iconDataBuilder.GetText().size();

   return iconData;
}

void Menu::GenerateMenu(const int xPos, const int yPos)
{
   m_dataBuffer.reserve(sizeof(wimp_menu) + m_menuEntries.size() * sizeof(wimp_menu_entry));

   wimp_menu* menu = reinterpret_cast<wimp_menu*>(&m_dataBuffer[0]);

   menu->title_data.indirected_text.text = &m_menuTitle[0];

   menu->title_fg = wimp_COLOUR_BLACK;
   menu->title_bg = wimp_COLOUR_LIGHT_GREY;
   menu->work_fg  = wimp_COLOUR_BLACK;
   menu->work_bg  = wimp_COLOUR_WHITE;

   menu->width  = 16;
   menu->height = wimp_MENU_ITEM_HEIGHT;
   menu->gap    = wimp_MENU_ITEM_GAP;

   for (std::size_t it = 0; it < m_menuEntries.size(); ++it) {

       wimp_menu_entry* menuEntry = &menu->entries[it];

       menuEntry->menu_flags = m_menuEntries[it].GetMenuFlags().GetFlags();

       if (m_menuEntries[it].GetSubMenu()) {
          menuEntry->sub_menu = const_cast<wimp_menu*>(reinterpret_cast<const wimp_menu*>(&m_menuEntries[it].GetSubMenu()->m_dataBuffer[0]));
       } else {
          menuEntry->sub_menu = NULL;
       }

       menuEntry->icon_flags = m_menuEntries[it].GetIconFlags().GetFlags() | (wimp_COLOUR_BLACK << wimp_ICON_FG_COLOUR_SHIFT) | (wimp_COLOUR_WHITE << wimp_ICON_BG_COLOUR_SHIFT);
       menuEntry->data       = ExtractIconData(m_menuEntries[it].GetIconData());

       int entryWidth = (m_menuEntries[it].GetIconData().GetText().size() + 1) * 16;
       if (menu->width < entryWidth) {
          menu->width = entryWidth;
       }

   }

   s_lastOpenedMenu = this;
   wimp_create_menu(menu, xPos, yPos);
   m_lastXPos = xPos;
   m_lastYPos = yPos;
}

}

}