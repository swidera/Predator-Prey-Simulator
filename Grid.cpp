/*******************************************************************************
 * File: Grid.cpp
 * Author:
 * Date:
 * Description: implementation file for the Grid class
*******************************************************************************/

#include "Grid.hpp"
#include "helperFunctions.hpp"

#include <cstddef>

/*******************************************************************************
 *					Grid::Grid()
 * Description: default constructor for a grid object.
*******************************************************************************/
Grid::Grid()
{
	//set numAnts and numDoodlebugs to default values specified in assignment
	//instructions.
	this->numAnts = 100;
	this->numDoodlebugs = 5;
	this->cyclesAlreadyRan = 0;
	this->numRows = 20;
	this->numCols = 20;
	antSteps = 0;
	
	//allocate all the memory needed for the theField
	//do not actually instantiate any objects. Just set all pointers to 
	//null
	this->Field = new Critter**[numRows];
	for (int i = 0 ; i < this->numRows ; i ++)
	{
		this->Field[i] = new Critter*[numCols];
		for (int j = 0; j < this->numCols; j++)
		{
			this->Field[i][j] = NULL;
		}
	}

	//randomly place 100 Ants in the array.
	int numAntsPlacedInField = 0;
	while(numAntsPlacedInField < numAnts)
	{
		//generate a random row and column to attempt to place an Ant at
		int row = randomIntGenerator(0,this->numRows-1);
		int column = randomIntGenerator(0,this->numCols-1);
		
		//if randomly chosen spot is empty, place an Ant object there
		if(Field[row][column] == NULL)
		{
			Field[row][column] = new Ant(row,column);
			numAntsPlacedInField++;
		}
	}

	//randomly place 5 Doodlebugs in the array.
	int numDoodlebugsPlacedInField = 0;
	while(numDoodlebugsPlacedInField < numDoodlebugs)
	{
		//generate a random row and column to attempt to place a Doodlebug in
		int row = randomIntGenerator(0,this->numRows-1);
		int column = randomIntGenerator(0,this->numCols-1);
		
		//if randomly chosen spot is empty, place an Doodlebug object there
		if(Field[row][column] == NULL)
		{
			Field[row][column] = new Doodlebug(row,column);
			numDoodlebugsPlacedInField++;
		}
	}
}
/*******************************************************************************
 *					Grid::Grid(int,int,int,int)
 * Description: A constructor that takes four ints as arguments. Sets the
 * number of rows, number of columns, number of ants, and number of doodlebugs
 * that will make up the Field at beginning.
*******************************************************************************/
Grid::Grid(int numRows, int numCols, int numAnts, int numDoodlebugs)
{
	//set numAnts and numDoodlebugs to input values from user
	this->numAnts = numAnts;
	this->numDoodlebugs = numDoodlebugs;
	this->cyclesAlreadyRan = 0;
	this->numRows = numRows;
	this->numCols = numCols;
	antSteps = 0;
	
	
	//allocate all the memory needed for the theField
	//do not actually instantiate any objects. Just set all pointers to NULL
	this->Field = new Critter**[this->numRows];
	for (int i = 0 ; i < this->numRows ; i ++)
	{
		this->Field[i] = new Critter*[this->numCols];
		for (int j = 0; j < this->numCols; j++)
		{
			this->Field[i][j] = NULL;
		}
	}
	
	//if more Critters have been requested than there are available spots,
	//implicit return to end function
	if( (this->numRows * this->numCols) < 
		(this->numAnts + this->numDoodlebugs))
	{
		return;
	}
	else
	{

		//randomly place 100 Ants in the array.
		int numAntsPlacedInField = 0;
		while(numAntsPlacedInField < this->numAnts)
		{
			//generate a random row and column to attempt to place an Ant at
			int row = randomIntGenerator(0,this->numRows-1);
			int column = randomIntGenerator(0,this->numCols-1);
			
			//if randomly chosen spot is empty, place an Ant object there
			if(Field[row][column] == NULL)
			{
				Field[row][column] = new Ant(row,column);
				numAntsPlacedInField++;
			}
		}

		//randomly place 5 Doodlebugs in the array.
		int numDoodlebugsPlacedInField = 0;
		while(numDoodlebugsPlacedInField < this->numDoodlebugs)
		{
			//generate a random row and column to attempt to place a
			//Doodlebug into
			int row = randomIntGenerator(0,this->numRows-1);
			int column = randomIntGenerator(0,this->numCols-1);
			
			//if randomly chosen spot is empty, place an Doodlebug object
			//there
			if(Field[row][column] == NULL)
			{
				Field[row][column] = new Doodlebug(row,column);
				numDoodlebugsPlacedInField++;
			}
		}
	}
}
	

/*******************************************************************************
 *					Grid::~Grid()
 * Description: destructor for a grid object. Deallocates any dynamic memory
 * that is still allocated for Critter objects
*******************************************************************************/
Grid::~Grid()
{
	//cycle through each critter in the field. if the pointer doesn't already
	//point to NULL, the critter must be deallocated.
	for(int i = 0; i < numRows; i ++)
	{
		for (int j = 0; j < numCols; j++)
		{
			delete this->Field[i][j];
			this->Field[i][j] = NULL;
		}
		delete [] this->Field[i];
		this->Field[i] = NULL; 
	}
	delete [] this->Field;
	this->Field = NULL;
}

/*******************************************************************************
 *						int getNumberCyclesToRun() const
 * Description: returns the number of cycles to run
*******************************************************************************/
int Grid::getNumberCyclesToRun() const
{
	return this->numberCyclesToRun;
}

/*******************************************************************************
 *					int getCyclesAlreadyRan() const
 * Description: returns the number of cycles that have already ben ran
*******************************************************************************/
int Grid::getCyclesAlreadyRan() const
{
	return this->cyclesAlreadyRan;
}

/*******************************************************************************
 *					int getNumAnts() const
 * Description: returns the number of ants in the Field
*******************************************************************************/
int Grid::getNumAnts() const 
{
	return this->numAnts;
}

/*******************************************************************************
 *					int getNumDoodlebugs() const
 * Description: returns the number of doodlebugs in the Field
*******************************************************************************/
int Grid::getNumDoodlebugs() const
{
	return this->numDoodlebugs;
}

/*******************************************************************************
 *					int getNumRows() const
 * Description: returns the number of rows in the Field
*******************************************************************************/
int Grid::getNumRows() const
{
	return this->numRows;
}

/*******************************************************************************
 *					int getNumCols() const
 * Description: returns the number of columns in the Field
*******************************************************************************/
int Grid::getNumCols() const
{
	return this->numCols;
}

/*******************************************************************************
 *					void setNumberCyclesToRun(int)
 * Description: sets the numberCyclesToRun member variable of Field object to
 * input value
*******************************************************************************/
void Grid::setNumberCyclesToRun(int numCycles)
{
	this->numberCyclesToRun = numCycles;
}

/*******************************************************************************
 *				void setCyclesAlreadyRan(int)
 * Description: sets teh numberCyclesAlreadyRan membber variable of Field object
 * to input value
*******************************************************************************/
void Grid::setCyclesAlreadyRan(int numCyclesRan)
{
	this->cyclesAlreadyRan = numCyclesRan;
}

/*******************************************************************************
 *				void setNumAnts(int)
 * Description: sets the numAnts member variable to the input value
*******************************************************************************/
void Grid::setNumAnts(int numAnts)
{
	this->numAnts = numAnts;
}

/*******************************************************************************
 *				void setNumDoodlebugs(int)
 * Description: sets the numDoodlebugs member variable to the input value
*******************************************************************************/
void Grid::setNumDoodlebugs(int numDoodles)
{
	this->numDoodlebugs = numDoodles;
}

/*******************************************************************************
 *				void setNumRows(int)
 * Description: sets the numRows member variable to the input value
*******************************************************************************/
void Grid::setNumRows(int numRows)
{
	this->numRows = numRows;
}

/*******************************************************************************
 *				void setNumCols(int)
 * Description:sets the numCols member variable to the input value
*******************************************************************************/
void Grid::setNumCols(int numCols)
{
	this->numCols = numCols;
}

/*******************************************************************************
 *				void printGrid() const
 * Description: prints the grid with locations of all doodlebugs and ants
*******************************************************************************/
void Grid::printGrid() const
{
	std::cout << "\n";
	std::cout << std::string(this->getNumCols()+2,'-') << std::endl;
	
	for (int i = 0; i < this->getNumRows(); i++)
	{
		std::cout << "|";
		for (int j = 0; j < this->getNumCols(); j++)
		{
			if( this->Field[i][j] == NULL)
			{
				std::cout << " ";
			}
			else
			{
				std::cout << this->Field[i][j]->printCritter();
			}
		}
		std::cout << "|\n";
	}

	std::cout << std::string(this->getNumCols()+2,'-') << std::endl;
}

/*******************************************************************************
 *					void resolveDoodlebugs()
 * Description: calls the move() and breed() functions of each doodlebug in the 
 * grid
*******************************************************************************/
void Grid::resolveDoodlebugs()
{
	for (int i = 0; i < this->numRows; i ++)
	{
		for (int j = 0; j < this->numCols; j++)
		{
			if(this->Field[i][j] != NULL)
			{
				if(this->Field[i][j]->getType() == "Doodlebug" && 
					this->Field[i][j]->getHasMoved() == false)
				{
					this->Field[i][j]->setHasMoved(true);
					this->Field[i][j]->move(this->Field, i, j, this->numRows,
						this->numCols);
				}
			}
		}
	}

	//run through the entire field and breed doodlebugs. moving must be completely
	//resolved before breeding
	for (int i = 0; i < this->numRows; i++)
	{
		for (int j = 0; j < this->numCols; j++)
		{
			if (this->Field[i][j] != NULL)
			{
				if (this->Field[i][j]->getType() == "Doodlebug")
				{
					//this will reset all the Ant's hasMoved variables so
					//they will get moved again in the next round of the
					//simulation
					this->Field[i][j]->setHasMoved(false);

					this->Field[i][j]->breed(this->Field, i, j, this->numRows,
						this->numCols);
				}
			}
		}
	}
}

/*******************************************************************************
 *					void resolveAnts()
 * Description: calls the move() and breed() functions of each Ant in the grid
*******************************************************************************/
void Grid::resolveAnts()
{
	//run through the entire field and move ants
	for (int i = 0; i < this->numRows; i ++)
	{
		for (int j = 0; j < this->numCols; j++)
		{
			if(this->Field[i][j] != NULL)
			{
				if(this->Field[i][j]->getType() == "Ant" && 
					this->Field[i][j]->getHasMoved() == false)
				{
					//setting hasMoved to true prevents re-moving Ants
					//that have already been moved in the same round.
					//this is re-set in the breed cycle below
					this->Field[i][j]->setHasMoved(true);
					this->Field[i][j]->move(this->Field,i,j,this->numRows,
										this->numCols);
				}
			}
		}
	}

	//run through the entire field and breed ants. moving must be completely
	//resolved before breeding
	for (int i = 0; i < this->numRows; i ++)
	{
		for (int j = 0; j < this->numCols; j++)
		{
			if(this->Field[i][j] != NULL)
			{
				if(this->Field[i][j]->getType() == "Ant")
				{
					//this will reset all the Ant's hasMoved variables so
					//they will get moved again in the next round of the
					//simulation
					this->Field[i][j]->setHasMoved(false);

					this->Field[i][j]->breed(this->Field,i,j,this->numRows,
										this->numCols);
				}
			}
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
