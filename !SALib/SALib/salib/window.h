// Class to represent and handle Wimp windows

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "windowbuilder.h"

namespace SALib {

namespace Wimp {

class Window {
public:
   Window(const std::string windowTitle, const int width, const int height, const Window* parent = reinterpret_cast<Window*>(0));
   Window(const WindowBuilder& builder, const Window* parent = reinterpret_cast<Window*>(0));
   virtual ~Window(void);

   void Open(void);
   void OpenAt(const int xPos, const int yPos);
   void OpenRequest(const unsigned* blockPtr);
   void Close(void);

   int GetVisibleLeftEdge(void) const;
   int GetVisibleBottomEdge(void) const;

   int GetVisibleWidth(void)  const { return m_windowWidth; }
   int GetVisibleHeight(void) const { return m_windowHeight; }

   void SetVisibleWidth(const int width);
   void SetVisibleHeight(const int height);

   virtual void OnOpen(void) {}
   virtual void OnClose(void) {}

   bool IsMessageForMe(const unsigned handle) const { return handle == m_handle; }
   bool IsWindowOpen(void) const;

private:
   std::string m_windowTitle;
   unsigned m_handle;

   const Window* m_parent;

   int m_windowWidth;
   int m_windowHeight;

   Window(const Window&); // Might want to make windows copiable
   Window& operator=(const Window&);
};

}

}

#endif