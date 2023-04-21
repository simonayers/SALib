// Utility functions

#include <cstring>

#include "oslib/os.h"
#include "oslib/wimp.h"
#include "oslib/wimpspriteop.h"
#include "salib/utilities.h"

namespace SALib {
 
namespace Wimp {

namespace Utilities {


int GetScreenHeightOSUnits(void)
{
   int height = -1;
   int shift = -1;

   os_read_mode_variable(os_CURRENT_MODE, os_MODEVAR_YWIND_LIMIT, &height);
   os_read_mode_variable(os_CURRENT_MODE, os_MODEVAR_YEIG_FACTOR, &shift);

   return height << shift;
}

int GetScreenWidthOSUnits(void)
{
   int width = -1;
   int shift = -1;

   // Prefer X-SWI but don't understand the additional parameter.
   os_read_mode_variable(os_CURRENT_MODE, os_MODEVAR_XWIND_LIMIT, &width);
   os_read_mode_variable(os_CURRENT_MODE, os_MODEVAR_XEIG_FACTOR, &shift);

   return width << shift;
}


void ErrorMessageBox(const char* message)
{
   os_error error;

   error.errnum = 255;
   strncpy(error.errmess, message, os_ERROR_LIMIT);
   error.errmess[os_ERROR_LIMIT - 1] = '\0';

   wimp_report_error_by_category(&error, wimp_ERROR_BOX_GIVEN_CATEGORY |
      (wimp_ERROR_BOX_CATEGORY_INFO << wimp_ERROR_BOX_CATEGORY_SHIFT) |
      wimp_ERROR_BOX_OK_ICON,
      "Error Message", "application", wimpspriteop_AREA, NULL);

}

std::string UnsignedToBinaryString(const unsigned value)
{
   std::string binaryString;

   for (int bit = 0; bit < 32; ++bit) {
      if ((value & (1 << (31 - bit))) > 0) {
         binaryString += "1";
      } else { 
         binaryString += "0";
      }
      if ((bit + 1) % 4 == 0) {
         binaryString += " ";
      }
   }
   return binaryString;
}


}

}

}