// Class for handling icons

#ifndef ICON_H
#define ICON_H

#include <string>
#include "iconbuilder.h"
#include "window.h"

namespace SALib {

namespace Wimp {

   class Icon {
   public:
      Icon(const IconBuilder& iconBuilder, const Window& window, const unsigned maxTextSize = 24U);
      virtual ~Icon(void);

      void Redraw(void) const;

      std::string& GetRawTextString(void) { return m_text; }
      std::string& GetRawValidationString(void) { return m_validationString; }

      int GetIconHandle(void) const { return m_iconHandle; }

   private:
      const Window& m_window;
      const int m_iconHandle;

      std::string m_spriteName;
      std::string m_text;
      std::string m_validationString;
   };


}

}


#endif  // ICON_H
