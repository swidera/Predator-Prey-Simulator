/*******************************************************************************
 * File: Doodlebug.cpp
 * Author:
 * Date:
 * Description: implementation file for the Doodlebug class
*******************************************************************************/

#include "Doodlebug.hpp"

/*******************************************************************************
 *					Doodlebug::Doodlebug()
 * Description:
*******************************************************************************/
Doodlebug::Doodlebug(int row, int col) : Critter(row,col)
{
	this->breedSteps = 8;
	this->critterType = "Doodlebug";
	starvingCounter = 0;
}
/*******************************************************************************
 *					Doodlebug::~Doodlebug() override
 * Description: override destructor for a Doodlebug object
*******************************************************************************/
Doodlebug::~Doodlebug()
{
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
 *				char Doodlebug::printCritter() const override
 * Description:
*******************************************************************************/
char Doodlebug::printCritter() const
{
	return 'X';
}

/*******************************************************************************
 *					Doodlebug::move(Critter***,int,int,int)
 * Description: moves the doodlebug, checking for edge cases according to the
 * rules for moving a doodlebug
*******************************************************************************/
bool Doodlebug::move(Critter ***fieldArray, int row, int col, 
				int numRows, int numCols)
{
	bool antNotEaten = true;
	int randomDirection;

	//if ant above, eats it and moves
	for (int i = 0; i < 30 && antNotEaten; i++)
	{
		//get a random direction
		randomDirection = randomIntGenerator(0,3);
		switch(randomDirection)
		{
			case UP:
				if(row != 0 && fieldArray[row - 1][col] != NULL && 
					fieldArray[row - 1][col]->getType() != "Doodlebug")
				{
					
					this->stepCounter++;
					//delete the ant object that was eaten
					delete fieldArray[row -1][col];
					//copy the pointer to the new spot
					fieldArray[row - 1][col] = fieldArray[row][col];
		
					//remove the pointer from the old spot
					fieldArray[row][col] = NULL;
					
					antNotEaten = false;
					starvingCounter = 0;
				
				}
				break;
			case LEFT:
				//if ant to left, eats it and moves
				if (col != 0 && fieldArray[row][col - 1] != NULL && 
					fieldArray[row][col - 1]->getType() != "Doodlebug")
				{
					this->stepCounter++;
					//delete the ant object that was eaten
					delete fieldArray[row][col-1];

					//copy the pointer to the new spot
					fieldArray[row][col - 1] = fieldArray[row][col];
	
					//remove the pointer from the old spot
					fieldArray[row][col] = NULL;

					antNotEaten = false;
	
					starvingCounter = 0;
				}
				break;
			case DOWN:
				//if ant below, eats it and moves
				if (row != numRows - 1 && 
					fieldArray[row + 1][col] != NULL && 
					fieldArray[row + 1][col]->getType() != "Doodlebug")
				{
					this->stepCounter++;
					//delete the ant object that was eaten
					delete fieldArray[row+1][col];

					//copy the pointer to the new spot
					fieldArray[row + 1][col] = fieldArray[row][col];

					//remove the pointer from the old spot
					fieldArray[row][col] = NULL;
					
					antNotEaten = false;
					starvingCounter = 0;
				}
				break;
			case RIGHT:
				//if ant to right, eats it and moves
				if (col != numCols - 1 && 
					fieldArray[row][col + 1] != NULL && 
					fieldArray[row][col + 1]->getType() != "Doodlebug")
				{
					this->stepCounter++;
					//delete the ant object that was eaten
					delete fieldArray[row][col +1];
					//copy the pointer to the new spot
					fieldArray[row][col + 1] = fieldArray[row][col];

					//remove the pointer from the old spot
					fieldArray[row][col] = NULL;

					starvingCounter = 0;
					antNotEaten = false;
				}
				break;

		};
	}
	
	//if no ant is found, moves and adds 1 to starving counter
	if(antNotEaten && starvingCounter == 3)	
	{
		delete fieldArray[row][col];
		fieldArray[row][col] = NULL;
	}
	else if(antNotEaten)
	{
		//will need srand(time(0)) in main for this to work
		Direction moveDirection;

		//cycle through each spot in the fieldArray
		//if the object at [i][j] is an ant, attempt to move it

		//increment the stepCounter for every ant
		this->stepCounter++;

		//get a random direction for each ant to attempt to move
		int directionChoice = randomIntGenerator(0,3);
		if (directionChoice == 0)
		{
			moveDirection = UP;
		}
		else if (directionChoice == 1)
		{
			moveDirection = DOWN;
		}
		else if (directionChoice == 2)
		{
			moveDirection = LEFT;
		}
		else
		{
			moveDirection = RIGHT;
		}

		//if the direction to move is up, do not attempt to move
		//if the ant is in the top row
		if (moveDirection == UP)
		{
			if (row != 0 && fieldArray[row - 1][col] == NULL)
			{
				//copy the pointer to the new spot
				fieldArray[row - 1][col] = fieldArray[row][col];

				//remove the pointer from the old spot
				fieldArray[row][col] = NULL;
			}

			starvingCounter++;
		}
		//if the direction to move is left, do not attempt to move
		//if the ant is in the first column
		else if (moveDirection == LEFT)
		{
			if (col != 0 && fieldArray[row][col - 1] == NULL)
			{
				//copy the pointer to the new spot
				fieldArray[row][col - 1] = fieldArray[row][col];

				//remove the pointer from the old spot
				fieldArray[row][col-1] = NULL;
			}

			starvingCounter++;
		}
		//if the direction to move is down, do not attempt to move
		//if the ant is in the bottom row
		else if (moveDirection == DOWN)
		{
			if (row != numRows - 1 && fieldArray[row + 1][col] == NULL)
			{
				//copy the pointer to the new spot
				fieldArray[row + 1][col] = fieldArray[row][col];

				//remove the pointer from the old spot
				fieldArray[row+1][col] = NULL;
			}

			starvingCounter++;

		}
		//else the direction is RIGHT. do not attempt to move if
		//the ant is in the rightmost column
		else
		{
			if (col != numCols - 1 && fieldArray[row][col + 1] == NULL)
			{
				//copy the pointer to the new spot
				fieldArray[row][col + 1] = fieldArray[row][col];

				//remove the pointer from the old spot
				fieldArray[row][col+1] = NULL;
			}

			starvingCounter++;
		}

		

	}
	//need a return statement in the function that is a catch-all
	return true;
}

/*******************************************************************************
 *					Doodlebug::breed(Critter***,int,int,int)
 * Description: breeds a doodlebug, checking for edge cases according to the
 * rules for brreding a doodlebug
*******************************************************************************/
void Doodlebug::breed(Critter ***fieldArray, int row, int col, 
				int numRows, int numCols)
{
	if (stepCounter > 0 && stepCounter % 8 == 0)
	{
		//if ant direction is up and remains on grid
		if (row != 0 && fieldArray[row - 1][col] == NULL)
		{
			fieldArray[row - 1][col] = new Doodlebug(row - 1, col);
			stepCounter = 0;
		}

		//if ant direction is down, remain on grid
		else if (row != numRows - 1 && fieldArray[row + 1][col] == NULL)
		{
			fieldArray[row + 1][col] = new Doodlebug(row + 1, col);
			stepCounter = 0;
		}

		//if ant direction is left, remain on grid
		else if (col != 0 && fieldArray[row][col - 1] == NULL)
		{
			fieldArray[row][col - 1] = new Doodlebug(row, col - 1);
			stepCounter = 0;
		}

		//if ant direction is right, remain on grid
		else if (col != numCols - 1 && fieldArray[row][col + 1] == NULL)
		{
			fieldArray[row][col + 1] = new Doodlebug(row, col + 1);
			stepCounter = 0;
		}

	}
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
