// Class for handling Mouse Clicks

#ifndef MOUSE_CLICK_OBSERVER_H
#define MOUSE_CLICK_OBSERVER_H
                     
#include "command.h"
#include "menu.h"
#include "observer.h"
#include "window.h"

namespace SALib {

namespace Wimp {

class MouseClickObserver : public ObserverBase {
public:
   MouseClickObserver(Window& windowToOpen) : m_windowToOpen(windowToOpen) {}
   virtual ~MouseClickObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   Window& m_windowToOpen;

   MouseClickObserver(const MouseClickObserver&);
   MouseClickObserver& operator=(const MouseClickObserver&);
};

class IconBarMouseClickObserver : public ObserverBase {
public:
   IconBarMouseClickObserver(CommandBase& selectClickCommand, CommandBase& adjustClickCommand, Menu& iconBarMenu)
      : m_selectClickCommand(selectClickCommand), m_adjustClickCommand(adjustClickCommand), m_iconBarMenu(iconBarMenu) {}   // Make some set of command-pattern objects
   virtual ~IconBarMouseClickObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   CommandBase& m_selectClickCommand;
   CommandBase& m_adjustClickCommand;
   Menu& m_iconBarMenu; 

   IconBarMouseClickObserver(const IconBarMouseClickObserver&);
   IconBarMouseClickObserver& operator=(const IconBarMouseClickObserver&);
};

} // namespace Wimp

} // namespace SALib

#endif // MOUSE_CLICK_OBSERVER_H