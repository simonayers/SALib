// Class for handling Window Requests

#ifndef WINDOWOBSERVER_H
#define WINDOWOBSERVER_H

#include "command.h"
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


class RedrawWindowRequestObserver : public ObserverBase {
public:
   RedrawWindowRequestObserver(Window& windowToRedraw) : m_windowToRedraw(windowToRedraw) {}
   virtual ~RedrawWindowRequestObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   Window& m_windowToRedraw;

   RedrawWindowRequestObserver(const RedrawWindowRequestObserver&);
   RedrawWindowRequestObserver& operator=(const RedrawWindowRequestObserver&);
};


class PointerActionWindowObserver : public ObserverBase {
public:
   PointerActionWindowObserver(Window& window, CommandBase& actionCommand)
      : m_window(window), m_actionCommand(actionCommand) {}

   virtual ~PointerActionWindowObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   Window& m_window;
   CommandBase& m_actionCommand;

   PointerActionWindowObserver(const PointerActionWindowObserver&);
   PointerActionWindowObserver& operator=(const PointerActionWindowObserver&);
};

} // namespace Wimp

} // namespace SALib

#endif // WINDOWOBSERVER_H