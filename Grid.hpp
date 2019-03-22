/*******************************************************************************
 * File: Grid.hpp
 * Author:
 * Date: May 4, 2018
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef GRID_HPP 
#define GRID_HPP 

#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>

class Grid
{
	private:
		Critter*** Field;
		int numberCyclesToRun;
		int cyclesAlreadyRan;
		int numAnts;
		int numDoodlebugs;
		int antSteps;
		int doodleSteps;
		//numRows and numCols are static so the values may be acquired from
		//user and initialized before a Grid object is instantiated.
		//The static getRowsandCols() function does this.
		int numRows;
		int numCols;

	public:
		//constructors and destructor
		Grid();
		Grid(int,int,int,int);
		~Grid();
		
		int getNumberCyclesToRun() const;
		int getCyclesAlreadyRan() const;
		int getNumAnts() const;
		int getNumDoodlebugs() const;
		int getNumRows() const;
		int getNumCols() const;
		void setNumberCyclesToRun(int);
		void setCyclesAlreadyRan(int);
		void setNumAnts(int);
		void setNumDoodlebugs(int);
		void setNumRows(int);
		void setNumCols(int);

		//other functions
		void printGrid() const;
		void resolveDoodlebugs();
		void resolveAnts();


};



#endif



