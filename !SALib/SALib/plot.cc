// Raw graphics plotting functions

#include "oslib/os.h"
#include "salib/plot.h"

namespace SALib {

namespace OS {

void PlotRectangle(const SALib::Wimp::Rectangle rectangle)
{
   os_plot(os_MOVE_BY, rectangle.xPos0, rectangle.yPos0);
   os_plot(os_PLOT_RECTANGLE + 1, rectangle.xPos1, rectangle.yPos1);
}

}

}