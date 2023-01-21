// Observer pattern for Wimp_Poll events

#ifndef POLL_OBSERVER_H
#define POLL_OBSERVER_H

#include <list>

namespace SALib {

namespace Wimp {

   class ObserverBase;

   class SubjectBase {
   public:
      SubjectBase(void) {}
      virtual ~SubjectBase(void) {}

      void Attach(ObserverBase& observer);
      void Detach(ObserverBase& observer);

      void Notify(const unsigned* blockPtr) const;

   private:
      typedef std::list<ObserverBase*> ObserverList;
      typedef std::list<ObserverBase*>::const_iterator ObserverListIterator;
      std::list<ObserverBase*> m_observerList;

      SubjectBase(const SubjectBase&);
      SubjectBase& operator=(const SubjectBase&);
   };

   class ObserverBase {
   public:
      ObserverBase(void) {}
      virtual ~ObserverBase(void) {}

      virtual void Update(const unsigned* blockPtr) const = 0;

   private:
      ObserverBase(const ObserverBase&);
      ObserverBase& operator=(const ObserverBase&);
   };

}

}


#endif // POLL_OBSERVER_H