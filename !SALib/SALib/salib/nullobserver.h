// Class for handling Null Poll Requests

#ifndef SALIB_WIMP_NULLOBSERVER_H
#define SALIB_WIMP_NULLOBSERVER_H

#include "command.h"
#include "observer.h"

namespace SALib {

namespace Wimp {

class NullRequestObserver : public ObserverBase {
public:
   NullRequestObserver(const CommandBase& command) : m_command(command) {}
   virtual ~NullRequestObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const { (void)blockPtr; m_command.Execute(); }

private:
   const CommandBase& m_command;

   NullRequestObserver(const NullRequestObserver&);
   NullRequestObserver& operator=(const NullRequestObserver&);
};

}

}

#endif // SALIB_WIMP_NULLOBSERVER_H
