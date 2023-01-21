// Class for handling icons

#include "icon.h"
#include "oslib/wimp.h"

namespace SALib {

namespace Wimp {

Icon::Icon(const std::string spriteName)
      : m_spriteName(spriteName), m_iconNumber(0)
{

}

Icon::~Icon(void)
{

}

}

}