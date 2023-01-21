// Class to represent and handle Wimp windows

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

namespace SALib {

namespace Wimp {

class Window {
public:
   Window(const std::string windowTitle);
   ~Window(void);

   void Open(void);
   void Close(void);

   bool IsMessageForMe(const unsigned handle) const { return handle == m_handle; }

private:
   std::string m_windowTitle;
   unsigned m_handle;

   Window(const Window&); // Might want to make windows copiable
   Window& operator=(const Window&);
};

}

}

#endif