// Class for handling Close Window Requests

#ifndef CLOSE_WINDOW_OBSERVER_H
#define CLOSE_WINDOW_OBSERVER_H

#include "observer.h"
#include "window.h"

namespace SALib {

namespace Wimp {

class CloseWindowRequestObserver : public ObserverBase {
public:
   CloseWindowRequestObserver(Window& windowToClose) : m_windowToClose(windowToClose) {}
   virtual ~CloseWindowRequestObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   Window& m_windowToClose;

   CloseWindowRequestObserver(const CloseWindowRequestObserver&);
   CloseWindowRequestObserver& operator=(const CloseWindowRequestObserver&);
};

} // namespace Wimp

} // namespace SALib

#endif // CLOSE_WINDOW_OBSERVER_H