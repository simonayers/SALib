// Implementation of class handling Mouse Clicks

#include "mouseclickobserver.h"
#include "oslib/os.h"
#include "oslib/wimp.h"

namespace SALib {

namespace Wimp {

void SALib::Wimp::MouseClickObserver::Update(const unsigned* blockPtr) const
{
   m_windowToOpen.Open();
}

void SALib::Wimp::IconBarMouseClickObserver::Update(const unsigned* blockPtr) const
{      
   const wimp_pointer* pointer = reinterpret_cast<const wimp_pointer*>(blockPtr);

   if (pointer->buttons == wimp_CLICK_MENU) {
      int yPos = 96 + (m_iconBarMenu.GetNumEntries() * (wimp_MENU_ITEM_HEIGHT + wimp_MENU_ITEM_GAP));
      m_iconBarMenu.GenerateMenu(pointer->pos.x - 64, yPos);
   } else {
      // Perform some sort of callback to user code
      //os_cli("Filer_OpenDir SCSI::HardDisc4.$");
   }
}

}

}