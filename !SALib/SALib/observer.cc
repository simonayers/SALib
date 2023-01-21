// Observer pattern for Wimp_Poll events

#include "observer.h"

namespace SALib {

namespace Wimp {

void SubjectBase::Attach(ObserverBase& observer)
{
   m_observerList.push_back(&observer);
}

void SubjectBase::Detach(ObserverBase& observer)
{
   m_observerList.remove(&observer);
}

void SubjectBase::Notify(const unsigned* blockPtr) const
{
   for (ObserverListIterator iterator = m_observerList.begin(); iterator != m_observerList.end(); ++iterator) {
      (*iterator)->Update(blockPtr);
   }
}

}

}