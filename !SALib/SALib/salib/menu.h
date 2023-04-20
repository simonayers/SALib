// Class for handling menus

#ifndef MENU_H
#define MENU_H

#include <list>
#include <string>
#include <vector>

#include "command.h"
#include "iconbuilder.h"

namespace SALib {

namespace Wimp {

   class Menu;

   class MenuEntry {
   public:

      class MenuFlagsBuilder {
      public:
         MenuFlagsBuilder(void) :
            m_ticked(           false),
            m_separate(         false),
            m_writable(         false),
            m_giveWarning(      false),
            m_subMenuWhenShaded(false),
            m_last(             false),
            m_titleIndirected(  false)
            {}


         MenuFlagsBuilder& SetTicked(           void) { m_ticked            = true; return *this; }
         MenuFlagsBuilder& SetSeparate(         void) { m_separate          = true; return *this; }
         MenuFlagsBuilder& SetWritable(         void) { m_writable          = true; return *this; }
         MenuFlagsBuilder& SetGiveWarning(      void) { m_giveWarning       = true; return *this; }
         MenuFlagsBuilder& SetSubMenuWhenShaded(void) { m_subMenuWhenShaded = true; return *this; }
         MenuFlagsBuilder& SetLast(             void) { m_last              = true; return *this; }
         MenuFlagsBuilder& SetTitleIndirected(  void) { m_titleIndirected   = true; return *this; }

         unsigned GetFlags(void) const;

      private:
         bool m_ticked;
         bool m_separate;
         bool m_writable;
         bool m_giveWarning;
         bool m_subMenuWhenShaded;
         bool m_last;
         bool m_titleIndirected;
      };

      MenuEntry(const MenuFlagsBuilder& menuFlags, const Menu* subMenu, const IconFlagsBuilder& iconFlags, const IconDataBuilder& iconData, const MenuSelectionCommandBase& menuSelectClickedCommand, const MenuSelectionCommandBase& menuAdjustClickedCommand);
      virtual ~MenuEntry(void);

      const MenuFlagsBuilder& GetMenuFlags(void) const { return m_menuFlags; }
      const Menu*             GetSubMenu(  void) const { return m_subMenu; }
      const IconFlagsBuilder& GetIconFlags(void) const { return m_iconFlags; }
      const IconDataBuilder&  GetIconData( void) const { return m_iconData; }

      void ExecuteSelectClickedCommand(void) const { m_menuSelectClickedCommand->Execute(); }
      void ExecuteAdjustClickedCommand(void) const { m_menuAdjustClickedCommand->Execute(); }

   private:
      MenuFlagsBuilder m_menuFlags;
      const Menu* m_subMenu;
      IconFlagsBuilder m_iconFlags;
      IconDataBuilder m_iconData;

      const MenuSelectionCommandBase* m_menuSelectClickedCommand;
      const MenuSelectionCommandBase* m_menuAdjustClickedCommand;
   };

   class Menu {
   public:
      Menu(const std::string& menuTitle);
      virtual ~Menu(void);

      bool IsMessageForMe(void) const { return s_lastOpenedMenu == this; }

      void AddEntry(const MenuEntry& menuEntry);
      int GetNumEntries(void) const { return static_cast<int>(m_menuEntries.size()); }
      const MenuEntry& GetEntry(const unsigned entryNumber) const { return m_menuEntries[entryNumber]; }  // Throw out of bounds exception if needed

      void GenerateMenu(const int xPos, const int yPos);
      void Reopen(void) { GenerateMenu(m_lastXPos, m_lastYPos); } 

   private:
      std::vector<unsigned char> m_dataBuffer;

      std::string m_menuTitle;
      unsigned m_handle;
      std::vector<MenuEntry> m_menuEntries;    // This was a list but changed due to GetEntry(). Performance eval needed

      mutable int m_lastXPos;
      mutable int m_lastYPos;

      static Menu* s_lastOpenedMenu;
   };

}

}


#endif  // MENU_H
