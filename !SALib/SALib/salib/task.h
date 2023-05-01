// Simple class for RAII management of a Wimp task
// Only a single instance of task can be created per application, but
// this will not be implemented as a singleton for now.

#ifndef TASK_H   // Might need to refine this name
#define TASK_H

#include <string>
#include <memory>
#include "event_dispatch.h"

namespace SALib {

namespace Wimp {

   class Task {
   public:
      enum WimpVersionNumber { WIMP_VERSION_310 = 310, WIMP_VERSION_380 = 380 };

      Task(const char* const taskName, const WimpVersionNumber wimpVersionNumber = WIMP_VERSION_380);
      ~Task(void);

      bool RequestToQuitReceived(void) const { return m_requestToQuitReceived; }
      EventDispatcher& GetEventDispatcher(void) { return m_eventDispatcher; }

      void ProcessMessages(void);

      void  EnableNullEvents(void) { m_enableNullEvents =  true; }
      void DisableNullEvents(void) { m_enableNullEvents = false; }

   private:
      class TaskHandle;                // opaque class in header file

      const std::string m_taskName;
      std::auto_ptr<TaskHandle> m_taskHandle;

      EventDispatcher m_eventDispatcher;
      bool m_requestToQuitReceived;
      bool m_enableNullEvents;

      Task(const Task&);
      Task& operator=(const Task&);
   };

} // namespace Wimp

} // namespace SALib

#endif // TASK_H