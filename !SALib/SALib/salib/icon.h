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
      Icon(const IconBuilder& iconBuilder, const Window& window);
      virtual ~Icon(void);


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
