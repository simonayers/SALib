// Class for handling Window Requests

#ifndef WINDOWOBSERVER_H
#define WINDOWOBSERVER_H

#include "observer.h"
#include "window.h"

namespace SALib {

namespace Wimp {

class OpenWindowRequestObserver : public ObserverBase {
public:
   OpenWindowRequestObserver(Window& windowToOpen) : m_windowToOpen(windowToOpen) {}
   virtual ~OpenWindowRequestObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   Window& m_windowToOpen;

   OpenWindowRequestObserver(const OpenWindowRequestObserver&);
   OpenWindowRequestObserver& operator=(const OpenWindowRequestObserver&);
};


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

#endif // WINDOWOBSERVER_H