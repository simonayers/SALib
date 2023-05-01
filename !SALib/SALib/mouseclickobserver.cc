// Implementation of class handling Mouse Clicks

#include "salib/mouseclickobserver.h"
#include "salib/mousecommand.h"
#include "oslib/os.h"
#include "oslib/wimp.h"

namespace SALib {

namespace Wimp {

void SALib::Wimp::MouseClickObserver::Update(const unsigned* blockPtr) const
{
   const wimp_pointer* pointer = reinterpret_cast<const wimp_pointer*>(blockPtr);
   const unsigned requestedWindowHandle = reinterpret_cast<unsigned>(pointer->w);

   if (m_window.IsMessageForMe(requestedWindowHandle)) {
      const int screenXPos = pointer->pos.x;
      const int screenYPos = pointer->pos.y;
      const int button     = static_cast<int>(pointer->buttons);
      const int iconHandle = static_cast<int>(pointer->i);
      m_command.ProcessClick(screenXPos, screenYPos, button, iconHandle);
   }
}

void SALib::Wimp::IconBarMouseClickObserver::Update(const unsigned* blockPtr) const
{                                                                                
   const wimp_pointer* pointer = reinterpret_cast<const wimp_pointer*>(blockPtr);
   
   if (pointer->w != wimp_ICON_BAR) {
      return;  // Only deal with Icon Bar click events in this handler.
   }
   
   switch (pointer->buttons) {
      case wimp_CLICK_SELECT:
         m_selectClickCommand.Execute();
         break;

      case wimp_CLICK_ADJUST:
         m_adjustClickCommand.Execute();
         break;

      case wimp_CLICK_MENU:
      {
         // Style Guide suggests only one operation which is to bring up menu.
         int yPos = 96 + (m_iconBarMenu.GetNumEntries() * (wimp_MENU_ITEM_HEIGHT + wimp_MENU_ITEM_GAP));
         m_iconBarMenu.GenerateMenu(pointer->pos.x - 64, yPos);
         break;
      }

      default:
         // Throw some exception here?
         break;
   }
}

void SALib::Wimp::DraggingEndedObserver::Update(const unsigned* blockPtr) const
{
   const Rectangle dragBox = *reinterpret_cast<const Rectangle*>(blockPtr);
   m_command.Process(dragBox);
}

}

}