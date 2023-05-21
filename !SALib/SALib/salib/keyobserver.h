// Class for handling Key Presses

#ifndef SALIB_WIMP_KEY_OBSERVER_H
#define SALIB_WIMP_KEY_OBSERVER_H
                     
#include "keycommand.h"
#include "observer.h"
#include "window.h"

namespace SALib {

namespace Wimp {

class KeyPressObserver : public ObserverBase {
public:
   KeyPressObserver(const Window& window, const KeyPressCommandBase& command) : m_window(window), m_command(command) {}
   virtual ~KeyPressObserver(void) {}

   virtual void Update(const unsigned* blockPtr) const;

private:
   const Window& m_window;
   const KeyPressCommandBase& m_command;

   KeyPressObserver(const KeyPressObserver&);
   KeyPressObserver& operator=(const KeyPressObserver&);
};

} // namespace Wimp

} // namespace SALib

#endif // SALIB_WIMP_KEY_OBSERVER_H
