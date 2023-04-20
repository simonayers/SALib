// Class for handling command patterns

#ifndef COMMAND_H
#define COMMAND_H

namespace SALib {

namespace Wimp {

   class CommandBase {
   public:
      virtual ~CommandBase(void) {}

      virtual void Execute(void) const = 0;
   };

   class MenuSelectionCommandBase : public CommandBase {
   public:                               
      virtual ~MenuSelectionCommandBase(void) {}

      virtual void Execute(void) const = 0;
   };


   class NullCommand : public CommandBase {
   public:
      virtual ~NullCommand(void) {}

      virtual void Execute(void) const {}
   };

   class NullMenuSelectionCommand : public MenuSelectionCommandBase {
   public:                               
      virtual ~NullMenuSelectionCommand(void) {}

      virtual void Execute(void) const {}
   };
}

}


#endif  // COMMAND_H
