#file: makefile
#author: Jordan K Bartos
#date: May 4, 2018
#description: makefile for the PredatorPrey Group Project

CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors

OBJS = main.o 
OBJS += helperFunctions.o
OBJS += Grid.o
OBJS += Critter.o
OBJS += Ant.o
OBJS += Doodlebug.o

CPPS = main.cpp
CPPS += helperFunctions.cpp
CPPS += Grid.cpp
CPPS += Critter.cpp
CPPS += Ant.cpp
CPPS += Doodlebug.cpp

HPPS = helperFunctions.hpp
HPPS += Grid.hpp
HPPS += Critter.hpp
HPPS += Ant.hpp
HPPS += Doodlebug.hpp

PredatorPrey : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o PredatorPrey 

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm $(OBJS) PredatorPrey

debug :
	valgrind -v --leak-check=full ./PredatorPrey

zip :
	zip -D GroupProject_Group_15.zip $(CPPS) $(HPPS) makefile Group_Project_Reflection.pdf
