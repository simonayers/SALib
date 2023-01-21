// Implementation of class handling menu item selections

#include <cstddef>
#include "oslib/wimp.h"
#include "menuselectionobserver.h"

namespace SALib {

namespace Wimp {

void SALib::Wimp::MenuSelectionObserver::Update(const unsigned* blockPtr) const
{
   if (m_menu.IsMessageForMe()) {
      // Handle selection
      const wimp_selection* selectionBlock = reinterpret_cast<const wimp_selection*>(blockPtr);
      
      std::size_t element = 0;
      Menu* currentMenu = &m_menu;
                                                     
      wimp_pointer pointer = { 0 };
      wimp_get_pointer_info(&pointer);

      if (pointer.buttons == wimp_CLICK_ADJUST) {
         currentMenu->GetEntry(static_cast<unsigned>(selectionBlock->items[element])).ExecuteAdjustClickedCommand();
         currentMenu->Reopen();
      } else {
         currentMenu->GetEntry(static_cast<unsigned>(selectionBlock->items[element])).ExecuteSelectClickedCommand();
      }
   }
}


}

}