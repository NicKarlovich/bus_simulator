# CSCI3081 lab09 makefile

# Directories
BUILDDIR = ../build
BINDIR = $(BUILDDIR)/bin

# Compiler flags
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -I.. $(DEBUG)
LFLAGS = -Wall $(DEBUG)

.PHONY : clean all passenger_test stop_test

all : passenger_test stop_test

passenger.o : passenger.h passenger.cc
	$(CC) $(CFLAGS) passenger.cc

passenger_driver.o : passenger.h passenger_driver.cc
	$(CC) $(CFLAGS) passenger_driver.cc

passenger_test : passenger.o passenger_driver.o | $(BINDIR)
	$(CC) $(LFLAGS) passenger.o passenger_driver.o -o $(BINDIR)/PassengerTest.exe

stop.o : stop.h stop.cc
	$(CC) $(CFLAGS) stop.cc
	
stop_driver.o : stop.h stop_driver.cc
	$(CC) $(CFLAGS) stop_driver.cc
	
stop_test : stop.o bus.o passenger.o stop_driver.o | $(BINDIR)
	$(CC) $(LFLAGS) passenger.o bus.o stop.o stop_driver.o -o $(BINDIR)/StopTest.exe
	
bus.o : bus.h bus.cc
	$(CC) $(CFLAGS) bus.cc

# And, this rule provides a recipe for creating the bindir, where the exe will be output.
$(BINDIR):
	@mkdir -p $@
	
clean : cleanobj cleantest
	
cleanobj :
	\rm *.o
	
cleantest :
	\rm $(BINDIR)/*Test.exe
