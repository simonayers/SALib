// Event dispatcher container
//

#ifndef EVENT_DISPATCH_H
#define EVENT_DISPATCH_H

#include "observer.h"

namespace SALib {

namespace Wimp {

class EventDispatcher {
public:
   EventDispatcher(void) {}
   ~EventDispatcher(void) {}

   SubjectBase& GetNullReasonCodeHandlers(        void) { return m_nullReasonCodeHandlers; }
   SubjectBase& GetRedrawWindowRequestHandlers(   void) { return m_getRedrawWindowRequestHandlers; }
   SubjectBase& GetOpenWindowRequestHandlers(     void) { return m_openWindowRequestHandlers; }
   SubjectBase& GetCloseWindowRequestHandlers(    void) { return m_closeWindowRequestHandlers; }
   SubjectBase& GetPointerLeavingWindowHandlers(  void) { return m_pointerLeavingWindowHandlers; }
   SubjectBase& GetPointerEnteringWindowHandlers( void) { return m_pointerEnteringWindowHandlers; }
   SubjectBase& GetMouseClickHandlers(            void) { return m_mouseClickHandlers; }
   SubjectBase& GetUserDragBoxHandlers(           void) { return m_userDragBoxHandlers; }
   SubjectBase& GetKeyPressedHandlers(            void) { return m_keyPressedHandlers; }
   SubjectBase& GetMenuSelectionHandlers(         void) { return m_menuSelectionHandlers; }
   SubjectBase& GetScrollRequestHandlers(         void) { return m_scrollRequestHandlers; }
   SubjectBase& GetLoseCaretHandlers(             void) { return m_loseCaretHandlers; }
   SubjectBase& GetGainCaretHandlers(             void) { return m_gainCaretHandlers; }
   SubjectBase& GetPollwordNonZeroHandlers(       void) { return m_pollwordNonZeroHandlers; }
   SubjectBase& GetUserMessageHandlers(           void) { return m_userMessageHandlers; }
   SubjectBase& GetUserMessageRecordedHandlers(   void) { return m_userMessageRecordedHandlers; }
   SubjectBase& GetUserMessageAcknowledgeHandlers(void) { return m_userMessageAcknowledgeHandlers; }

private:
   SubjectBase m_nullReasonCodeHandlers;
   SubjectBase m_getRedrawWindowRequestHandlers;
   SubjectBase m_openWindowRequestHandlers;
   SubjectBase m_closeWindowRequestHandlers;
   SubjectBase m_pointerLeavingWindowHandlers;
   SubjectBase m_pointerEnteringWindowHandlers;
   SubjectBase m_mouseClickHandlers;
   SubjectBase m_userDragBoxHandlers;
   SubjectBase m_keyPressedHandlers;
   SubjectBase m_menuSelectionHandlers;
   SubjectBase m_scrollRequestHandlers;
   SubjectBase m_loseCaretHandlers;
   SubjectBase m_gainCaretHandlers;
   SubjectBase m_pollwordNonZeroHandlers;
   SubjectBase m_userMessageHandlers;
   SubjectBase m_userMessageRecordedHandlers;
   SubjectBase m_userMessageAcknowledgeHandlers;

   EventDispatcher(const EventDispatcher&);
   EventDispatcher& operator=(const EventDispatcher);
};

}

}

#endif
