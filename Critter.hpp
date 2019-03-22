
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <string>
#include "helperFunctions.hpp"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Critter
{
	protected:
		std::string critterType; //will hold the type of criteer (ant or doodlebug)
		int breedSteps; //number of steps a critter needs to take before it can breed
		int stepCounter; //will count the number of steps since the last breeding
		int currentRow; //critters row placement on grid
		int currentColumn; //critters column placement on grid
		bool hasMoved;
	
	public:
		Critter(); //default constructor
		//constructor that will create a critter and place it on board
		Critter(int startRow, int startColumn); 
		virtual ~Critter(); //destructor 
		void setHasMoved(bool);
		bool getHasMoved();
		std::string getType(); //getter function for critter type
		//virtual move function that will be defined in ant and doodlebug classes for their specific move rules
		virtual bool move(Critter***,int,int,int,int) = 0; 
		//virtual breed function that will be defined in ant and doodlebug classes for their specific breeding rules
		virtual void breed(Critter***,int,int,int,int) = 0; 
		virtual char printCritter() const =0;
};
#endif // !CRITTER_HPP


//got breedSteps and critterType
