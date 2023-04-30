// Wimp Dragging operations

#ifndef SALIB_WIMP_DRAG_H
#define SALIB_WIMP_DRAG_H

#include "rectangle.h"
#include "window.h"

namespace SALib {

namespace Wimp {

void DragWindowPosition(const Window& window, const Rectangle initialDragbox);
void DragFixedSizeBox(const Window& window, const Rectangle initialDragbox, const Rectangle parentBox);
void DragUserPoint(const Window& window, const Rectangle boundingBox);
void DragEnd(void);

}

}

#endif // SALIB_WIMP_DRAG_H
