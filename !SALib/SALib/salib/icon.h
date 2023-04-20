// Class for handling icons

#ifndef ICON_H
#define ICON_H

#include <string>

namespace SALib {

namespace Wimp {

   class Icon {
   public:
      Icon(const std::string spriteName);
      virtual ~Icon(void);


   private:
      unsigned m_iconNumber;
      std::string m_spriteName;
   };

}

}


#endif  // ICON_H
