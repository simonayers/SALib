// Class for handling menus

#ifndef MENU_H
#define MENU_H

#include <list>
#include <string>
#include <vector>

#include "command.h"

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

      class IconFlagsBuilder {
      public:
         IconFlagsBuilder(void) :
            m_iconText(             false),
            m_iconSprite(           false),
            m_iconBorder(           false),
            m_iconHCentred(         false),
            m_iconVCentred(         false),
            m_iconFilled(           false),
            m_iconAntiAliased(      false),
            m_iconNeedsHelp(        false),
            m_iconIndirected(       false),
            m_iconRJustified(       false),
            m_iconAllowAdjust(      false),
            m_iconHalfSize(         false),
            m_iconButtonType(       false),
            m_iconESG(              false),
            m_iconSelected(         false),
            m_iconShaded(           false),
            m_iconDeleted(          false),
            m_iconFGColour(         false),
            m_iconBGColour(         false),
            m_iconFontHandle(       false),
            m_buttonNever(          false),
            m_buttonAlways(         false),
            m_buttonRepeat(         false),
            m_buttonClick(          false),
            m_buttonRelease(        false),
            m_buttonDoubleClick(    false),
            m_buttonClickDrag(      false),
            m_buttonReleaseDrag(    false),
            m_buttonDoubleDrag(     false),
            m_buttonMenuIcon(       false),
            m_buttonDoubleClickDrag(false),
            m_buttonRadio(          false),
            m_buttonWriteClickDrag( false),
            m_buttonWritable(       false)
            {}

         IconFlagsBuilder& SetIconText(             void) { m_iconText              = true; return *this; }
         IconFlagsBuilder& SetIconSprite(           void) { m_iconSprite            = true; return *this; }
         IconFlagsBuilder& SetIconBorder(           void) { m_iconBorder            = true; return *this; }
         IconFlagsBuilder& SetIconHCentred(         void) { m_iconHCentred          = true; return *this; }
         IconFlagsBuilder& SetIconVCentred(         void) { m_iconVCentred          = true; return *this; }
         IconFlagsBuilder& SetIconFilled(           void) { m_iconFilled            = true; return *this; }
         IconFlagsBuilder& SetIconAntiAliased(      void) { m_iconAntiAliased       = true; return *this; }
         IconFlagsBuilder& SetIconNeedsHelp(        void) { m_iconNeedsHelp         = true; return *this; }
         IconFlagsBuilder& SetIconIndirected(       void) { m_iconIndirected        = true; return *this; }
         IconFlagsBuilder& SetIconRJustified(       void) { m_iconRJustified        = true; return *this; }
         IconFlagsBuilder& SetIconAllowAdjust(      void) { m_iconAllowAdjust       = true; return *this; }
         IconFlagsBuilder& SetIconHalfSize(         void) { m_iconHalfSize          = true; return *this; }
         IconFlagsBuilder& SetIconButtonType(       void) { m_iconButtonType        = true; return *this; }
         IconFlagsBuilder& SetIconESG(              void) { m_iconESG               = true; return *this; }
         IconFlagsBuilder& SetIconSelected(         void) { m_iconSelected          = true; return *this; }
         IconFlagsBuilder& SetIconShaded(           void) { m_iconShaded            = true; return *this; }
         IconFlagsBuilder& SetIconDeleted(          void) { m_iconDeleted           = true; return *this; }
         IconFlagsBuilder& SetIconFGColour(         void) { m_iconFGColour          = true; return *this; }
         IconFlagsBuilder& SetIconBGColour(         void) { m_iconBGColour          = true; return *this; }
         IconFlagsBuilder& SetIconFontHandle(       void) { m_iconFontHandle        = true; return *this; }
         IconFlagsBuilder& SetButtonNever(          void) { m_buttonNever           = true; return *this; }
         IconFlagsBuilder& SetButtonAlways(         void) { m_buttonAlways          = true; return *this; }
         IconFlagsBuilder& SetButtonRepeat(         void) { m_buttonRepeat          = true; return *this; }
         IconFlagsBuilder& SetButtonClick(          void) { m_buttonClick           = true; return *this; }
         IconFlagsBuilder& SetButtonRelease(        void) { m_buttonRelease         = true; return *this; }
         IconFlagsBuilder& SetButtonDoubleClick(    void) { m_buttonDoubleClick     = true; return *this; }
         IconFlagsBuilder& SetButtonClickDrag(      void) { m_buttonClickDrag       = true; return *this; }
         IconFlagsBuilder& SetButtonReleaseDrag(    void) { m_buttonReleaseDrag     = true; return *this; }
         IconFlagsBuilder& SetButtonDoubleDrag(     void) { m_buttonDoubleDrag      = true; return *this; }
         IconFlagsBuilder& SetButtonMenuIcon(       void) { m_buttonMenuIcon        = true; return *this; }
         IconFlagsBuilder& SetButtonDoubleClickDrag(void) { m_buttonDoubleClickDrag = true; return *this; }
         IconFlagsBuilder& SetButtonRadio(          void) { m_buttonRadio           = true; return *this; }
         IconFlagsBuilder& SetButtonWriteClickDrag( void) { m_buttonWriteClickDrag  = true; return *this; }
         IconFlagsBuilder& SetButtonWritable(       void) { m_buttonWritable        = true; return *this; }

         unsigned GetFlags(void) const;

      private:
         bool m_iconText;
         bool m_iconSprite;
         bool m_iconBorder;
         bool m_iconHCentred;
         bool m_iconVCentred;
         bool m_iconFilled;
         bool m_iconAntiAliased;
         bool m_iconNeedsHelp;
         bool m_iconIndirected;
         bool m_iconRJustified;
         bool m_iconAllowAdjust;
         bool m_iconHalfSize;
         bool m_iconButtonType;
         bool m_iconESG;
         bool m_iconSelected;
         bool m_iconShaded;
         bool m_iconDeleted;
         bool m_iconFGColour;
         bool m_iconBGColour;
         bool m_iconFontHandle;
         bool m_buttonNever;
         bool m_buttonAlways;
         bool m_buttonRepeat;
         bool m_buttonClick;
         bool m_buttonRelease;
         bool m_buttonDoubleClick;
         bool m_buttonClickDrag;
         bool m_buttonReleaseDrag;
         bool m_buttonDoubleDrag;
         bool m_buttonMenuIcon;
         bool m_buttonDoubleClickDrag;
         bool m_buttonRadio;
         bool m_buttonWriteClickDrag;
         bool m_buttonWritable;

      };

      class IconDataBuilder {
      public:
         IconDataBuilder(const std::string& text) : m_text(text) {}
         IconDataBuilder(const std::string& text, const std::string& spriteName) : m_text(text), m_spriteName(spriteName) {}

         const std::string& GetText(void) const { return m_text; }
         const std::string& GetSpriteName(void) const { return m_spriteName; }

      private:
         std::string m_text;
         std::string m_spriteName;
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


#endif  // ICON_H
