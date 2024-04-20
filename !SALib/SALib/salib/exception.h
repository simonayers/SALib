//
//  Exception heirarchy of types
//

#ifndef SALIB_EXCEPTION_H
#define SALIB_EXCEPTION_H
               
#include <cstdio>

namespace SALib {

class Exception {
public:
   Exception(const char * const message)
   {
      snprintf(m_message, sizeof(m_message), "Exception: %s", message);
   }

protected:
   Exception(const char * const exceptionType, const char * const message)
   {
      snprintf(m_message, sizeof(m_message), "%s: %s", exceptionType, message);
   }

public:
   virtual ~Exception(void) {}
   
   virtual const char * GetMessage(void) { return m_message; }

private:
   char m_message[256];
};


class FatalException : public Exception {
public:
   FatalException(const char * const message) : Exception("FatalException", message) {}

protected:
   FatalException(const char * const exceptionType, const char * const message) : Exception(exceptionType, message) {}

public:
   virtual ~FatalException(void) {}
};


class RecoverableException : public Exception {
public:
   RecoverableException(const char * const message) : Exception("RecoverableException", message) {}

protected:
   RecoverableException(const char * const exceptionType, const char * const message) : Exception(exceptionType, message) {}

public:
   virtual ~RecoverableException(void) {}
};

}

#endif // SALIB_EXCEPTION_H
