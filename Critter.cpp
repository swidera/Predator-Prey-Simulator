#include "Critter.hpp"

#include <string>
#include <cstdlib>
#include <ctime>

/************************************************************************
** Function:	Critter()
** Description:	Default constructor for the Critter class that will set
**				all of the member variables to null
*************************************************************************/

Critter::Critter()
{
}

/************************************************************************
** Function:	Critter(Critter ***gridPtr, int gridSize, int startRow, 
**						int startColumn, int startStep = 0)
**
** Description:	Constructor for the Critter class that will create a
**				type of critter, and place it on the grid that is passed
**				via the ***gridPtr and gridSize parameters along with
**				the parameters for the starting coordinates 
*************************************************************************/

Critter::Critter(int startRow, int startColumn)
{
	currentColumn = startColumn;
	currentRow = startRow;
	stepCounter = 0;
	hasMoved = false;
}

/************************************************************************
** Function:	~Critter()
** Description:	Destructor for the Critter class 
*************************************************************************/

Critter::~Critter()
{
}

/************************************************************************
** Function:	string getType()
** Description:	Returns the type of critter object (Ant or Doodlebug)
*************************************************************************/

std::string Critter::getType()
{
	return critterType;
}

/************************************************************************
** Function:	bool setHasMoved()
** Description:	keeps track of whether a critter object has been moved
** in a round. this prevents critters that move "forwards" in the 
** processing cycle from being moved a second time
*************************************************************************/
void Critter::setHasMoved(bool hasMoved)
{
	this->hasMoved = hasMoved;
}

/************************************************************************
** Function:	bool setHasMoved()
** Description:	keeps track of whether a critter object has been moved
** in a round. this prevents critters that move "forwards" in the 
** processing cycle from being moved a second time
*************************************************************************/
bool Critter::getHasMoved()
{
	return this->hasMoved;
}
	
/***************************************************************************
** Function:	char printCritter()
** Description:	function is overridden by Ant and Doodlebug printCritter
** functions which return either X or O accordingly
****************************************************************************/
char printCritter()
{
	return ' ';
}
