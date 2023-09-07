// Debug function that use Reporter module

#include <cstdio>
#include "oslib/os.h"
#include "salib/reporter.h"
#include "salib/utilities.h"

namespace SALib {

namespace Reporter {

void Report(const char * message)
{
   if (SALib::Wimp::Utilities::ModuleExistsInMemory("Reporter")) {
      char command[256] = {'\0'};
      snprintf(command, sizeof(command), "Report %s\n", message);
      os_cli(command);
   }
}

}

}