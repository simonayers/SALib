// Classes for managing fonts
            
#ifndef SALIB_OS_FONTS_H
#define SALIB_OS_FONTS_H
                 
#include <list>
#include <string>

#include "colour.h"

namespace SALib {

namespace OS {

class Font {
public:
   Font(const std::string& fontName) : m_fontName(fontName), m_handle(0xFFu) {}
   ~Font(void);

   void Load(const int fontSize);
   void Unload(void);

   void Paint(const std::string& text, const int xPos, const int yPos, const Wimp::Colour::Colour foreground, const Wimp::Colour::Colour background) const;
   void Paint(const std::string& text, const int xPos, const int yPos, const Wimp::Colour::RGBColour foreground, const Wimp::Colour::RGBColour background) const;

   bool IsLoaded(void) const { return m_handle != 0xFFu; }

   unsigned char GetHandle(void) const { return m_handle; }
   const std::string& GetName(void) const { return m_fontName; }

private:
   const std::string m_fontName;
   unsigned char m_handle;

// Probably shouldn't be copiable but needed for std::list. Redesign?
};

class FontManager {
public:
   static FontManager& Get(void) { static FontManager singleton; return singleton; }

   void Enumerate(void);

   bool DoesFontExist(const std::string& fontName) const;
   Font& GetFontFromName(const std::string& fontName);

   int NumOfInstalledFonts(void) const { return static_cast<int>(m_fontList.size()); }

   std::list<std::string> GetFontNameList(void) const;

private:
   FontManager(void) {}
   ~FontManager(void) {}

   std::list<Font> m_fontList;

   FontManager(const FontManager&);
   FontManager& operator=(const FontManager&);
};

}

}

#endif // SALIB_OS_FONTS_H
