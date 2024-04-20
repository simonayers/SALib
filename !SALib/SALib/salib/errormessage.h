//
// Functions for displaying Wimp Error message boxes
//

#ifndef SALIB_WIMP_ERRORMESSAGE_H
#define SALIB_WIMP_ERRORMESSAGE_H

#include <string>

#include "colour.h"
#include "icon.h"
#include "task.h"
#include "window.h"

namespace SALib {

namespace Wimp {

namespace ErrorMessage {

enum ButtonClicked {
   OK_CLICKED,
   CANCEL_CLICKED,
   CONTINUE_CLICKED
};

//----------------------------------------------------------------------

void ReportFatal(const char * const applicationName, const char * const spriteName, const char * const message);




//----------------------------------------------------------------------

class NonBlockingErrorWindow : public Window {
public:
   NonBlockingErrorWindow(Task& task,
                          const std::string& applicationName,
                          const std::string& spriteName,
                          const Colour::Colour foregroundColour = Colour::Black,
                          const Colour::Colour backgroundColour = Colour::VeryLightGrey);

   ButtonClicked ShowOK(            const std::string& message);
   ButtonClicked ShowContinue(      const std::string& message);
   ButtonClicked ShowCancelContinue(const std::string& message);
   ButtonClicked ShowCancelOK(      const std::string& message);


private:

   const Icon& Show(void);

   Task& m_task;

   const std::string m_applicationName;
   const std::string m_spriteName;

   const Colour::Colour m_foregroundColour;
   const Colour::Colour m_backgroundColour;

   Icon m_applicationIcon;
   Icon m_categoryIcon;
   Icon m_messageIcon;
   Icon m_groupBoxIcon;

   Icon m_defaultActionButtonIcon;
   Icon m_standardActionButtonIcon;

   NonBlockingErrorWindow(const NonBlockingErrorWindow&);
   NonBlockingErrorWindow& operator=(const NonBlockingErrorWindow&);
};


//----------------------------------------------------------------------

}

}

}

#endif // SALIB_WIMP_ERRORMESSAGE_H
