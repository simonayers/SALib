# Rough makefile for building SALib library with G++

CPP=g++
INCDIRS=-IOSLib\:
OPT=-O0
CPPFLAGS=-Wall -mlibscl $(INCDIRS) $(OPT)
LINKFLAGS=-mlibscl

CPPFILES=caret.cc colour.cc command.cc drag.cc errormessage.cc font.cc icon.cc iconbar.cc iconbuilder.cc keyobserver.cc menu.cc menuselectionobserver.cc mouseclickobserver.cc observer.cc plot.cc pointer.cc reporter.cc task.cc utilities.cc window.cc windowbuilder.cc windowobserver.cc
OBJECTS=caret.o colour.o command.o drag.o errormessage.o font.o icon.o iconbar.o iconbuilder.o keyobserver.o menu.o menuselectionobserver.o mouseclickobserver.o observer.o plot.o pointer.o reporter.o task.o utilities.o window.o windowbuilder.o windowobserver.o

LIBRARY=libSALib.a

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs  $@ $^

%.o: %.cc
	$(CPP) -c $(CPPFLAGS) -o $@ $^

clean:
	IfThere libSALib/a Then X Wipe libSALib/a ~CFR~V
	X Wipe o.* ~CFR~V

