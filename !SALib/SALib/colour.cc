// Class for Wimp colours
                          
#include "oslib/wimp.h"
#include "salib/colour.h"

namespace SALib {

namespace Wimp {

namespace Colour {

void SetColour(const Colour colour)
{
   wimp_set_colour(static_cast<wimp_colour>(colour));
}

}

}

}
