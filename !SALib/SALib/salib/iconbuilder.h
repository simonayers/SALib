// Classes for building Icon definitions

#ifndef ICONBUILDER_H
#define ICONBUILDER_H

#include <string>
#include "colour.h"
#include "font.h"
#include "rectangle.h"

namespace SALib {

namespace Wimp {

class IconFlagsBuilder {
public:

   enum IconButtonTypes {
      IgnoreAllClicks                  =  0,
      NotifyContinually                =  1,
      ClickAutoRepeat                  =  2,
      ClickOnce                        =  3,
      ClickSelectsMoveAwayDeselects    =  4,
      ClickSelectsNotifyDoubleClick    =  5,
      ClickOnceAndDrag                 =  6,
      ClickSelectsNotifyReleaseAndDrag =  7,
      ClickSelectsDoubleClickAndDrag   =  8,
      MenuIcon                         =  9,
      ClickDragDoubleClick             = 10,
      ClickSelectsAndDrag              = 11,
      GainInputFocusAndDrag            = 14,
      GainInputFocus                   = 15
   };

    IconFlagsBuilder(void) :
       m_iconText(            false),
       m_iconSprite(          false),
       m_iconBorder(          false),
       m_iconHCentred(        false),
       m_iconVCentred(        false),
       m_iconFilled(          false),
       m_iconAntiAliased(     false),
       m_iconNeedsHelp(       false),
       m_iconIndirected(      false),
       m_iconRJustified(      false),
       m_iconAllowAdjust(     false),
       m_iconHalfSize(        false),
       m_iconButtonType(      false),
       m_iconESG(             false),
       m_iconSelected(        false),
       m_iconShaded(          false),
       m_iconDeleted(         false),
       m_iconFGColour(Colour::Black),
       m_iconBGColour(Colour::White),
       m_iconFont(NULL),
       m_buttonType(IgnoreAllClicks)
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

   IconFlagsBuilder& SetIconFGColour(Colour::Colour iconFGColour) { m_iconFGColour = iconFGColour; return *this; }
   IconFlagsBuilder& SetIconBGColour(Colour::Colour iconBGColour) { m_iconBGColour = iconBGColour; return *this; }

   IconFlagsBuilder& SetIconFont(const OS::Font& font) { m_iconFont = &font; return *this; }

   IconFlagsBuilder& SetButtonType(const IconButtonTypes& buttonType) { m_buttonType = buttonType; return *this; }

   unsigned GetFlags(void) const;
   bool GetAntiAliased(void) const { return m_iconAntiAliased; }
   Colour::Colour GetIconFGColour(void) const { return m_iconFGColour; }
   Colour::Colour GetIconBGColour(void) const { return m_iconBGColour; }

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
   Wimp::Colour::Colour m_iconFGColour;
   Wimp::Colour::Colour m_iconBGColour;
   const OS::Font* m_iconFont;
   IconButtonTypes m_buttonType;
};


class IconDataBuilder {
public:
   IconDataBuilder(void) {}
   IconDataBuilder(const std::string& text) : m_text(text) {}
   IconDataBuilder(const std::string& text, const std::string& spriteName) : m_text(text), m_spriteName(spriteName) {}

   const std::string& GetText(void) const { return m_text; }
   void SetText(const std::string& text) { m_text = text; }

   const std::string& GetSpriteName(void) const { return m_spriteName; }
   void SetSpriteName(const std::string& spriteName) { m_spriteName = spriteName; }

private:
   std::string m_text;
   std::string m_spriteName;
};



class IconBuilder {
public:
   IconBuilder(void) {}

   void SetExtent(const Rectangle& extent) { m_extent = extent; }
   const Rectangle& GetExtent(void) const { return m_extent; }

   IconFlagsBuilder& GetIconFlagsBuilder(void) { return m_iconFlagsBuilder; }
   IconDataBuilder& GetIconDataBuilder(void)   { return m_iconDataBuilder; }

   const IconFlagsBuilder& GetIconFlagsBuilder(void) const { return m_iconFlagsBuilder; }
   const IconDataBuilder& GetIconDataBuilder(  void) const { return m_iconDataBuilder; }

   unsigned GetIconFlags(void) const { return m_iconFlagsBuilder.GetFlags(); }

private:
   Rectangle m_extent;
   IconFlagsBuilder m_iconFlagsBuilder;
   IconDataBuilder m_iconDataBuilder;
};

}

}

#endif // ICONBUILDER_H
