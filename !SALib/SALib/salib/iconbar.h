// Class for handling icons on the iconbar

#ifndef ICONBAR_H
#define ICONBAR_H

#include <string>

namespace SALib {

namespace Wimp {

   class IconBar {
   public:
      enum IconPosition {
         RIGHT               = -1,
         LEFT                = -2,
         LEFT_RELATIVE       = -3,
         RIGHT_RELATIVE      = -4,
         LEFT_HIGH_PRIORITY  = -5,
         LEFT_LOW_PRIORITY   = -6,
         RIGHT_LOW_PRIORITY  = -7,
         RIGHT_HIGH_PRIORITY = -8
      };

      IconBar(const IconPosition iconPosition, const std::string& spriteName);
      IconBar(const IconPosition iconPosition, const std::string& spriteName, const std::string& iconText);
      ~IconBar(void);                                                                                      

   private:
      IconPosition m_iconPosition;
      std::string m_spriteName;
      std::string m_iconText;
      std::string m_validationString;
      unsigned m_iconHandle;
   };

}

}


#endif

