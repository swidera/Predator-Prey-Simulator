/*******************************************************************************
 * File: Ant.cpp
 * Author:
 * Date:
 * Description: implementation file for the Ant class
*******************************************************************************/

#include "Ant.hpp"

/*******************************************************************************
 *				Ant::Ant()
 * constructor for ant object
*******************************************************************************/
Ant::Ant(int row, int col) : Critter(row, col)
{
	this->breedSteps = 3;
	this->critterType = "Ant";
	stepCounter = 0;
}



/*******************************************************************************
 *				Ant::~Ant() override
 * Description: override destructor for ant object
*******************************************************************************/
Ant::~Ant()
{
}
/*******************************************************************************
 *
 * Description: Ant move function, takes in dynamic field array as a Critter
 * member along with the size of rows and columns. This calculates the random
 * directional movement of an ant and increments step counter after every move.
*******************************************************************************/
bool Ant::move(Critter*** fieldArray, int row, int col, int numRows, int numCols)
{
	//will need srand(time(0)) in main for this to work
	Direction moveDirection;

	//cycle through each spot in the fieldArray
	//if the object at [i][j] is an ant, attempt to move it
	
	//increment the stepCounter for every ant
	this->stepCounter++;

	//get a random direction for each ant to attempt to move
	int directionChoice = rand()%4;
	if(directionChoice == 0)
	{
		moveDirection = UP;
	}
	else if(directionChoice == 1)
	{
		moveDirection = DOWN;
	}
	else if(directionChoice == 2)
	{
		moveDirection = LEFT;
	}
	else
	{
		moveDirection = RIGHT;
	}

	//if the direction to move is up, do not attempt to move
	//if the ant is in the top row
	if(moveDirection == UP)
	{
		if(row != 0 && fieldArray[row-1][col] == NULL)
		{
			//copy the pointer to the new spot
			fieldArray[row-1][col] = fieldArray[row][col];
			
			//remove the pointer from the old spot
			fieldArray[row][col] = NULL;
		}
	}
	//if the direction to move is left, do not attempt to move
	//if the ant is in the first column
	else if(moveDirection == LEFT)
	{
		if(col != 0 && fieldArray[row][col-1] == NULL)
		{
			//copy the pointer to the new spot
			fieldArray[row][col-1] = fieldArray[row][col];
			
			//remove the pointer from the old spot
			fieldArray[row][col] = NULL;
		}
	}
	//if the direction to move is down, do not attempt to move
	//if the ant is in the bottom row
	else if(moveDirection == DOWN)
	{
		if(row != numRows -1 && fieldArray[row+1][col] == NULL)
		{
			//copy the pointer to the new spot
			fieldArray[row+1][col] = fieldArray[row][col];
			
			//remove the pointer from the old spot
			fieldArray[row][col] = NULL;
		}
	}
	//else the direction is RIGHT. do not attempt to move if
	//the ant is in the rightmost column
	else
	{
		if(col != numCols-1 && fieldArray[row][col+1] == NULL)
		{
			//copy the pointer to the new spot
			fieldArray[row][col+1] = fieldArray[row][col];
			
			//remove the pointer from the old spot
			fieldArray[row][col] = NULL;
		}
	}
	//need a return statement in the function that is a catch-all
	return true;
}



/*******************************************************************************
 *
 * Description: breed function, takes field array, rows, columns and step counter
 * to put a new ant 'O' on the grid depending on direction of travel and number 
 * of steps.
*******************************************************************************/

void Ant::breed(Critter ***fieldArray, int row, int col, int numRows, int numCols)
{

    //if ant makes 3 steps, breed. Can't be equal to 3 steps
    //because ant can survive 3 more making 6, etc. therefore must
    //be modulus 3 and greater than 0 or less than row/column length.
    if (stepCounter > 0 && stepCounter % 3 == 0)
    {
        //if ant direction is up and remains on grid
        if (row != 0 && fieldArray[row - 1][col] == NULL)
        {
            fieldArray[row-1][col] = new Ant(row-1,col);
			stepCounter = 0;
        }

        //if ant direction is down, remain on grid
        else if (row != numRows - 1 && fieldArray[row + 1][col] == NULL)
        {
            fieldArray[row+1][col] = new Ant(row+1,col);
			stepCounter = 0;
        }

        //if ant direction is left, remain on grid
        else if (col != 0 && fieldArray[row][col - 1] == NULL)
        {
            fieldArray[row][col-1] = new Ant(row,col-1);
			stepCounter = 0;
        }

        //if ant direction is right, remain on grid
        else if(col != numCols - 1 && fieldArray[row][col + 1] == NULL)
        {
            fieldArray[row][col+1] = new Ant(row,col+1);
			stepCounter = 0;
        }
		
		
		
	
		
		
    }
	
	stepCounter++;
	
}

/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *					char Ant::printCritter() const override
 * Description: overrides the Critter printCritter function. Returns an O to 
 * indicate an ant object when the Grid function is printing the grid
*******************************************************************************/
char Ant::printCritter() const
{
	return 'O';
}
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
