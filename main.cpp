/*******************************************************************************
 * File: main.cpp
 * Author:
 * Date:
 * Description:
*******************************************************************************/

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Grid.hpp"
#include "helperFunctions.hpp"
#include <time.h>
#include <cstddef>


//additional function headers
void getSetupFromUser(int&,int&,int&,int&);
void displayWelcome();
int getNumCycles();
bool userWantsToContinue();

int main()
{
	srand(time(0));
	clearTheScreen();
	displayWelcome();
	//initialize variables for size of array, number of bugs
	int numRows, numCols, numAnts, numDoodlebugs;

	//get input from user necessary to instantiate the board
	//size of grid, number of critters
	getSetupFromUser(numRows,numCols,numAnts,numDoodlebugs);

	//instantiate the grid
	Grid theField(numRows,numCols,numAnts,numDoodlebugs);

	do
	{
		int numCycles = getNumCycles();
		for(int i = 0; i < numCycles; i ++) 
		{

			theField.printGrid();
			theField.resolveDoodlebugs();
			theField.resolveAnts();
		}
	}while(userWantsToContinue());
	
	return 0;
}

/*******************************************************************************
 *				void getSetupFromUser(int&,int&,int&,int&)
 * Description: Takes 4 references to ints as variables. Gets input from the
 * for how many rows and columns they would like to make the Field. Then
 * gets how many ants and how many doodlebugs they would like to place on the
 * Field at start. Sets argument variables to the input values.
*******************************************************************************/
void getSetupFromUser(int &numRows, int &numCols, int &numAnts, 
				int &numDoodlebugs)
{
	std::string inputString = "";
	bool gotAGoodInt = false;		//flag variable to use for validation
	int convertedString = 0;
	//maxAnts and maxDoodlebugs must be determined at runtime. It depends on
	//size of the grid.
	int maxAnts = 0;
	int maxDoodlebugs = 0;

	int minAnts = 1;
	int minDoodlebugs = 1;

	const int MAX_ROWS = 100,
			MAX_COLS = 140,
			MIN_ROWS = 2,
			MIN_COLS = 2;


	//get number of rows
	do
	{

		clearTheScreen();
		std::cout << "How many rows will there be on this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << MIN_ROWS;  
		std::cout << " and " << MAX_ROWS << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,MIN_ROWS,MAX_ROWS))
		{
			numRows = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);

	//get number of columns
	do
	{

		clearTheScreen();
		std::cout << "How many columns will there be on this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << MIN_COLS;  
		std::cout << " and " << MAX_COLS << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,MIN_COLS,MAX_COLS))
		{
			numCols = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);
	
	//get number of Ants. Note number of ants may not exceed number of
	//total spaces.
	maxAnts = numCols * numRows - 1;
	
	do
	{
		clearTheScreen();
		std::cout << "How many ants will there be in this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << minAnts;  
		std::cout << " and " << maxAnts << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,minAnts,maxAnts))
		{
			numAnts = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);

	//get number of Ants. Note number of ants may not exceed number of
	//total spaces minus the number of Ants.
	maxDoodlebugs = numCols * numRows - numAnts;
	
	do
	{

		clearTheScreen();
		std::cout << "How many doodlebugs will there be in this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << minDoodlebugs;  
		std::cout << " and " << maxDoodlebugs << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,minDoodlebugs,maxDoodlebugs))
		{
			numDoodlebugs = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);
}

/*******************************************************************************
 *				void displayWelcome
 * Description: Displays a welcome message to begin the program. Claims this
 * program will seek the extra credit points
*******************************************************************************/
void displayWelcome()
{
	clearTheScreen();

	std::cout << "\tThis is the PredatorPrey program\n\nthis program runs " <<
			"a simulation of a predator-prey relationship\nbetween " <<
			"\"ants\" and \"doodlebugs\".\n\nThis program allows the " <<
			"user to choose the number of rows,\ncolumns, ants, and " <<
			"doodlebugs the program will begin with\nper the extra " <<
			"credit requirements." << std::endl;
	pause();
			
}

/*******************************************************************************
 *				int getNumCycles
 * Description: gets an int from the user and returns it. Int will be used to
 * run the correct amount of day cycles in the program
*******************************************************************************/
int getNumCycles()
{
	const int MIN_CYCLES = 1;
	const int MAX_CYCLES  = 50;
	std::cout << "How many days would you like to simulate?" << std::endl;
	return getIntFromUser(MIN_CYCLES,MAX_CYCLES);
}

/*******************************************************************************
 *				bool userWantsToContinue
 * Description: prompts the user to ask if they want to continue or not. If 
 * they want to continue, function returns true. If they choose to quit, 
 * function returns false.
*******************************************************************************/
bool userWantsToContinue()
{
	std::cout << "Do you wish to continue the simulation?" << std::endl;
	return getYesOrNo();
}
