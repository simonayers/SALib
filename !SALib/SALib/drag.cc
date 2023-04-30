// Wimp Dragging operations

#include "oslib/wimp.h"
#include "salib/drag.h"

namespace SALib {

namespace Wimp {

void DragWindowPosition(const Window& window, const Rectangle initialDragbox)
{
   wimp_drag wimpDrag = { 0 };

   wimpDrag.w = reinterpret_cast<wimp_w>(window.GetWindowHandle());
   wimpDrag.type = wimp_DRAG_SYSTEM_POSITION;

   wimpDrag.initial.x0 = initialDragbox.xPos0;
   wimpDrag.initial.y0 = initialDragbox.yPos0;
   wimpDrag.initial.x1 = initialDragbox.xPos1;
   wimpDrag.initial.y1 = initialDragbox.yPos1;

   wimp_drag_box(&wimpDrag);
}

void DragFixedSizeBox(const Window& window, const Rectangle initialDragbox, const Rectangle parentBox)
{
   wimp_drag wimpDrag = { 0 };

   wimpDrag.w = reinterpret_cast<wimp_w>(window.GetWindowHandle());
   wimpDrag.type = wimp_DRAG_USER_FIXED;

   wimpDrag.initial.x0 = initialDragbox.xPos0;
   wimpDrag.initial.y0 = initialDragbox.yPos0;
   wimpDrag.initial.x1 = initialDragbox.xPos1;
   wimpDrag.initial.y1 = initialDragbox.yPos1;

   wimpDrag.bbox.x0 = parentBox.xPos0;
   wimpDrag.bbox.y0 = parentBox.yPos0;
   wimpDrag.bbox.x1 = parentBox.xPos1;
   wimpDrag.bbox.y1 = parentBox.yPos1;

   wimp_drag_box(&wimpDrag);
}

void DragUserPoint(const Window& window, const Rectangle boundingBox)
{

   wimp_drag wimpDrag = { 0 };

   wimpDrag.w = reinterpret_cast<wimp_w>(window.GetWindowHandle());
   wimpDrag.type = wimp_DRAG_USER_POINT;

   wimpDrag.initial.x0 = 0;
   wimpDrag.initial.y0 = 0;
   wimpDrag.initial.x1 = 0;
   wimpDrag.initial.y1 = 0;

   wimpDrag.bbox.x0 = boundingBox.xPos0;
   wimpDrag.bbox.y0 = boundingBox.yPos0;
   wimpDrag.bbox.x1 = boundingBox.xPos1;
   wimpDrag.bbox.y1 = boundingBox.yPos1;

   wimp_drag_box(&wimpDrag);
}

void DragEnd(void)
{
   wimp_drag wimpDrag = { 0 };
   wimp_drag_box(&wimpDrag);
}

}

}
