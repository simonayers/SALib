// Class for handling menu item selections

#ifndef MENU_SELECTION_OBSERVER_H
#define MENU_SELECTION_OBSERVER_H

#include "observer.h"
#include "menu.h"

namespace SALib {

namespace Wimp {

class MenuSelectionObserver : public ObserverBase {
public:
   MenuSelectionObserver(Menu& menu) : m_menu(menu) {}
   virtual ~MenuSelectionObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   Menu& m_menu;

   MenuSelectionObserver(const MenuSelectionObserver&);
   MenuSelectionObserver& operator=(const MenuSelectionObserver&);
};

} // namespace Wimp

} // namespace SALib

#endif // MENU_SELECTION_OBSERVER_H