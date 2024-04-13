// Classes for managing fonts

#include <list>
#include <string>

#include "oslib/colourtrans.h"
#include "oslib/font.h"
#include "oslib/wimp.h"
#include "salib/font.h"

namespace SALib {

namespace OS {

Font::~Font(void)
{
   Unload();
}

void Font::Load(const int fontSize)
{
   if (IsLoaded()) { Unload(); }

   m_handle = static_cast<unsigned char>(font_find_font(m_fontName.c_str(), fontSize * 16, fontSize * 16, 0, 0, NULL, NULL));
}

void Font::Unload(void)
{
   if (!IsLoaded()) { return; }

   font_lose_font(static_cast<font_f>(m_handle));

   m_handle = 0xFF;
}

void Font::Paint(const std::string& text, const int xPos, const int yPos, const Wimp::Colour::Colour foreground, const Wimp::Colour::Colour background) const
{
   if (!IsLoaded()) { return; }

   wimp_set_font_colours(static_cast<wimp_colour>(background), static_cast<wimp_colour>(foreground));

   const font_string_flags flags = font_OS_UNITS | font_GIVEN_FONT;
   font_paint(static_cast<font_f>(m_handle), text.c_str(), flags, xPos, yPos, NULL, NULL, text.length());
}

void Font::Paint(const std::string& text, const int xPos, const int yPos, const Wimp::Colour::RGBColour foreground, const Wimp::Colour::RGBColour background) const
{
   if (!IsLoaded()) { return; }

   const int maxColourOffset = 14;
   colourtrans_set_font_colours(static_cast<font_f>(m_handle), static_cast<os_colour>(background.GetBGRAValue()), static_cast<os_colour>(foreground.GetBGRAValue()), maxColourOffset, NULL, NULL, NULL);

   const font_string_flags flags = font_OS_UNITS | font_GIVEN_FONT;
   font_paint(static_cast<font_f>(m_handle), text.c_str(), flags, xPos, yPos, NULL, NULL, text.length());
}

/*************************************************************************/


void FontManager::Enumerate(void)
{
   // This enumeration is destructive so may invalidate font handles.
   m_fontList.clear();

   int newContext = 0;
   char identifierBuffer[256];

   while (newContext != -1) {

      int identifierBufferSize = 0;
      identifierBuffer[0] = '\0';

      const font_list_context context = static_cast<int>(m_fontList.size()) | font_RETURN_FONT_NAME;

      newContext = font_list_fonts(NULL, context, 0, NULL, 0, NULL, &identifierBufferSize, NULL);

      if (newContext == -1) return;

      newContext = font_list_fonts(reinterpret_cast<byte*>(identifierBuffer), context,
                               identifierBufferSize, NULL, 0, NULL, &identifierBufferSize, NULL);

      m_fontList.push_back(Font(identifierBuffer));
   }
}

bool FontManager::DoesFontExist(const std::string& fontName) const
{
   if (m_fontList.size() > 0) {
      for (std::list<Font>::const_iterator it = m_fontList.begin(); it != m_fontList.end(); ++it) {
         if ((*it).GetName() == fontName) {
            return true;
         }
      }
   }
   return false;
}

Font& FontManager::GetFontFromName(const std::string& fontName)
{
   if (m_fontList.size() == 0) {
      Enumerate();
   }

   for (std::list<Font>::iterator it = m_fontList.begin(); it != m_fontList.end(); ++it) {
      if ((*it).GetName() == fontName) {
         return (*it);
      }
   }

   // If no match found then return first font in the list. List should never be empty.
   return m_fontList.front();
}

}

}
