// Functions for Pointer manipulation
                    
#include "oslib/wimpspriteop.h"
#include "salib/pointer.h"

namespace SALib {

namespace Wimp {

namespace Pointer {

void SetSprite(const char * spriteName)
{
// SYS "Wimp_SpriteOp",36,,"ptr_default",1
   wimpspriteop_set_pointer_shape(spriteName, 1, 0, 0, reinterpret_cast<os_factors*>(0),
      reinterpret_cast<osspriteop_trans_tab*>(0));
}

void SetScrollLeftRight(void)
{
   SetSprite("ptr_autoscrh");
}

void SetScrollUpDown(void)
{
   SetSprite("ptr_autoscrv");
}

void SetDefaultSprite(void)
{
   SetSprite("ptr_default");
}

}

}

}