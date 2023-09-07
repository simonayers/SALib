// Utility functions

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

namespace SALib {
 
namespace Wimp {

namespace Utilities {

int GetScreenHeightOSUnits(void);
int GetScreenWidthOSUnits(void);

void ErrorMessageBox(const char* message);
std::string UnsignedToBinaryString(const unsigned value);

bool ModuleExistsInMemory(const char * const moduleName);

}

}
                
}

#endif // UTILITIES_H