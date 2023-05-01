// Implementation of task handling class.
//
// Can use OSLib here but don't want it in the class
// definitions, hence opaque class definition for
// task handle for now.

#include "oslib/wimp.h"
#include "salib/task.h"

namespace SALib {

namespace Wimp {

class Task::TaskHandle {
public:
   wimp_t handle;
};

Task::Task(const char* const taskName, const Task::WimpVersionNumber wimpVersionNumber)
      : m_taskName(taskName), m_taskHandle(new TaskHandle),
        m_requestToQuitReceived(false), m_enableNullEvents(false)
{
   wimp_message_list* wimpMessageList = reinterpret_cast<wimp_message_list*>(0);
   wimp_version_no    wimpVersionNumberReceived = static_cast<wimp_version_no>(0);

   m_taskHandle->handle = wimp_initialise(static_cast<wimp_version_no>(wimpVersionNumber),
                                          m_taskName.c_str(), wimpMessageList,
                                          &wimpVersionNumberReceived);

   // Currently no handling of error conditions.  TODO - Add exception throwing if Wimp_Initialise fails.
}

Task::~Task(void)
{
   wimp_close_down(m_taskHandle->handle);
}


void Task::ProcessMessages(void)
{
   // Temporary implementation of a message handling loop.
   // Later versions will pass messages on to registered event handlers.
   wimp_block block;
   const wimp_event_no reason = wimp_poll((m_enableNullEvents ? 0 : wimp_MASK_NULL)
                                        | wimp_MASK_GAIN
                                        | wimp_MASK_LOSE
                                        | wimp_MASK_POLLWORD,
                                          &block, NULL);
   const unsigned* blockPtr = reinterpret_cast<unsigned*>(&block);

   switch (reason) {
      case wimp_NULL_REASON_CODE:
         GetEventDispatcher().GetNullReasonCodeHandlers().Notify(blockPtr);
         break;

      case wimp_REDRAW_WINDOW_REQUEST:
         GetEventDispatcher().GetRedrawWindowRequestHandlers().Notify(blockPtr);
         break;

      case wimp_OPEN_WINDOW_REQUEST:
         GetEventDispatcher().GetOpenWindowRequestHandlers().Notify(blockPtr);
         break;

      case wimp_CLOSE_WINDOW_REQUEST:
         GetEventDispatcher().GetCloseWindowRequestHandlers().Notify(blockPtr);
         break;

      case wimp_POINTER_LEAVING_WINDOW:
         GetEventDispatcher().GetPointerLeavingWindowHandlers().Notify(blockPtr);
         break;

      case wimp_POINTER_ENTERING_WINDOW:
         GetEventDispatcher().GetPointerEnteringWindowHandlers().Notify(blockPtr);
         break;

      case wimp_MOUSE_CLICK:
         GetEventDispatcher().GetMouseClickHandlers().Notify(blockPtr);
         break;

      case wimp_USER_DRAG_BOX:
         GetEventDispatcher().GetUserDragBoxHandlers().Notify(blockPtr);
         break;

      case wimp_KEY_PRESSED:
         GetEventDispatcher().GetKeyPressedHandlers().Notify(blockPtr);
         break;

      case wimp_MENU_SELECTION:
         GetEventDispatcher().GetMenuSelectionHandlers().Notify(blockPtr);
         break;

      case wimp_SCROLL_REQUEST:
         GetEventDispatcher().GetScrollRequestHandlers().Notify(blockPtr);
         break;

      case wimp_LOSE_CARET:
         GetEventDispatcher().GetLoseCaretHandlers().Notify(blockPtr);
         break;

      case wimp_GAIN_CARET:
         GetEventDispatcher().GetGainCaretHandlers().Notify(blockPtr);
         break;

      case wimp_POLLWORD_NON_ZERO:
         GetEventDispatcher().GetPollwordNonZeroHandlers().Notify(blockPtr);
         break;

      case wimp_USER_MESSAGE:
         GetEventDispatcher().GetUserMessageHandlers().Notify(blockPtr);
         if (block.message.action == message_QUIT) {
            m_requestToQuitReceived = true;
         }
         break;

      case wimp_USER_MESSAGE_RECORDED:
         GetEventDispatcher().GetUserMessageRecordedHandlers().Notify(blockPtr);
         if (block.message.action == message_QUIT) {
            m_requestToQuitReceived = true;
         }
         break;

      case wimp_USER_MESSAGE_ACKNOWLEDGE:
         GetEventDispatcher().GetUserMessageAcknowledgeHandlers().Notify(blockPtr);
         break;

      default:
           // throw exception here?
         break;
   }
}


}   // namespace Wimp

}   // namespace SALib