// Functions for Pointer manipulation
                    
#include "oslib/wimpspriteop.h"
#include "salib/pointer.h"

namespace SALib {

namespace Wimp {

namespace Pointer {

void SetSprite(const char * spriteName)
{
   wimpspriteop_set_pointer_shape(spriteName, 1, 0, 0, reinterpret_cast<os_factors*>(0),
      reinterpret_cast<osspriteop_trans_tab*>(0));
}

void SetSprite(const char * spriteName, const int xOffset, const int yOffset)
{
   wimpspriteop_set_pointer_shape(spriteName, 1, xOffset, yOffset, reinterpret_cast<os_factors*>(0),
      reinterpret_cast<osspriteop_trans_tab*>(0));
}

void SetScrollLeftRight(void)
{
   SetSprite("ptr_autoscrh", 10, 4);   // Todo - figure this out from the sprite itself
}

void SetScrollUpDown(void)
{
   SetSprite("ptr_autoscrv", 4, 10);   // Todo - figure this out from the sprite itself
}

void SetDefaultSprite(void)
{
   SetSprite("ptr_default");
}


int GetPointerXPosition(void)
{
   wimp_pointer pointer = { 0 };
   wimp_get_pointer_info(&pointer);
   return pointer.pos.x;
}

int GetPointerYPosition(void)
{
   wimp_pointer pointer = { 0 };
   wimp_get_pointer_info(&pointer);
   return pointer.pos.y;
}

}

}

}