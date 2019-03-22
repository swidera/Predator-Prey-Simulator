/*******************************************************************************
** fileName: helperFunctions.cpp
** Author: Jordan K Bartos
** Date: April 10, 2018
** Description: These are the input validation functions necessary for this
** project
*******************************************************************************/
#include "helperFunctions.hpp"
#include <random>
#include <climits>


/*******************************************************************************
*						bool isAnInt(string&)
* Description: this function takes a reference to a string as input and checks
* if it could be a valid integer. If the string can successfully be converted
* to an int, it retruns true. If the string cannot be successfully converted to
* an int, it returns false.
*******************************************************************************/
bool isAnInt(const std::string &INPUT_STRING)
{

	//If the string contains a hyphen ('-'), it must contain only one hyphen
	//and it must be at the very beginning of the string. If it contains
	//multiple hyphens or it contains one not at the beginning of the string,
	//return false
	
	if(((INPUT_STRING.find_first_of("-") == INPUT_STRING.find_last_of("-")) &&
		(INPUT_STRING.find_last_of("-") == 0) ) ||
		(INPUT_STRING.find_first_of("-") == std::string::npos))
	{
		//The following code was modified from an answer to a question found
		//on stackoverflow
		//reference: https://stackoverflow.com/questions/18728754/checking-
		//input-value-is-an-integer
		return (INPUT_STRING.find_first_not_of("0123456789-") ==
			std::string::npos) && !INPUT_STRING.empty();

	}
	//else, it either contains multiple hyphens or a hyphen at a position
	//other than [0]
	else
	{
		return false;
	}
}

/*******************************************************************************
*						bool isADouble(string&)
* Description: this function takes a reference to a string as input and checks
* if it could be a valid integer. If the string can successfully be converted
* to an int, it retruns true. If the string cannot be successfully converted to
* an int, it returns false.
*******************************************************************************/
bool isADouble(const std::string &INPUT_STRING)
{

	//If the string contains a hyphen ('-'), it must contain only one hyphen
	//and it must be at the very beginning of the string. If it contains
	//multiple hyphens or it contains one not at the beginning of the string,
	//return false
	
	if(((INPUT_STRING.find_first_of("-") == INPUT_STRING.find_last_of("-")) &&
		(INPUT_STRING.find_last_of("-") == 0) ) ||
		(INPUT_STRING.find_first_of("-") == std::string::npos))
	{
		//if the string contains only a hyphen, return false
		if(INPUT_STRING.length() == 1)
		{
			return false;
		}
		//similarily, can only contain one '.'
		if(INPUT_STRING.find_first_of(".") == INPUT_STRING.find_last_of("."))
		{
			//The following code was modified from an answer to a question found
			//on stackoverflow
			//reference: https://stackoverflow.com/questions/18728754/checking-
			//input-value-is-an-integer
			return (INPUT_STRING.find_first_not_of("0123456789-.") ==
				std::string::npos) && !INPUT_STRING.empty();
		}
		else
		{
			return false;
		}

	}
	//else, it either contains multiple hyphens or a hyphen at a position
	//other than [0]
	else
	{
		return false;
	}
}


/*******************************************************************************
**				bool convertStringtoInt(string&,int&,int,int)
** Description: Takes a reference to a string, a reference to an int (this
** will take the value of the converted int), an int for the minimum allowable
** value, and an int for the maximum allowable value. It returns true on a 
** successful conversion and false on an unsuccessful conversion. It uses the
** isAnInt() function also found in this file.
*******************************************************************************/
bool convertStringToInt(const std::string &INPUT_STRING,int &convertedInt,
	 int min, int max)
{
	int tempInt;

	if(isAnInt(INPUT_STRING))	//make sure string can be made an int
	{
		tempInt = std::atoi(INPUT_STRING.c_str());	//convert string to an
											//int
											
		//if the string contained an integer larger than INT_MAX, it will
		//overflow. So, comparing the original string to the tempInt will
		//indicate if the input was too large/too small to be an int
		if((std::to_string(tempInt)).compare(INPUT_STRING) == 0)
		{
			//is int in specified range?
			if(tempInt >= min && tempInt <= max)
			{
				convertedInt = tempInt;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}

/*******************************************************************************
**				bool convertStringToDouble(string&,int&,int,int)
** Description: Takes a reference to a string, a reference to an int (this
** will take the value of the converted int), an int for the minimum allowable
** value, and an int for the maximum allowable value. It returns true on a 
** successful conversion and false on an unsuccessful conversion. It uses the
** isADouble() function also found in this file.
*******************************************************************************/
bool convertStringToDouble(const std::string &INPUT_STRING,double &convertedDouble,
	 double min, double max)
{
	double tempDouble;

	if(isADouble(INPUT_STRING))	//make sure string can be made an int
	{
		//convert string to a double
		tempDouble = std::atof(INPUT_STRING.c_str());
											
		//if the string contained an integer larger than INT_MAX, it will
		//overflow. So, comparing the original string to the tempInt will
		//indicate if the input was too large/too small to be an int
		//is double in specified range?
		if(tempDouble >= min && tempDouble <= max)
		{
			convertedDouble = tempDouble;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


/*******************************************************************************
 * 				int randomIntGenerator(int min, int max)
 * Description: generates a random int between the values of the arguments it 
 * takes, inclusive. srand() must be initialized prior to calling function for
 * proper results
*******************************************************************************/
int randomIntGenerator(int min, int max)
{
	if (max - min == 0)
	{
		return min;
	}

	if (min > max)
	{
		int temp = max;
		max = min;
		min = temp;
	}
	return (rand() % (max - min + 1)) + min;
}

/*******************************************************************************
 * 				double randomIntGenerator(double min, double max)
 * Description: generates a random double between the values of the arguments it 
 * takes, inclusive. srand() must be initialized prior to calling function for
 * proper results
 * note: this code is adapted from an answer to a question on stackoverflow. It
 * can be found here: stackoverflow.com/questions/2704521/generate-random-double
 * -numbers-in-c
*******************************************************************************/
double randomDoubleGenerator(double min, double max)
{
	double randNum = static_cast<double>(rand()) / RAND_MAX;
	return min + randNum * (max - min);
}

/*******************************************************************************
 * 				void openFile(inputFile&)
 * Description: attempts to open a file. If it cannot be opened, it asks the
 * user if they would like to try a different file name. If the user chooses to
 * quit, it terminates. Otherwise, it tries to open that file and repeats
*******************************************************************************/
void openFile(std::ifstream &file)
{
	std::string fileName;
	
	do
	{
		std::cout << "Enter the filename you would like to read from: "
				<< std::flush;
		std::getline(std::cin,fileName);
		file.open(fileName);
		if(!file)
		{
			if(getFileFailMenu() == 2)
			{
				return;
			}
		}
	} while(!file);
}



/*******************************************************************************
 * 				int getFileFailMenu()
 * Description: in case a filename is invalid, this function asks the user if
 * they would like to try another file or quit. Returns 1 if user wants to try
 * another filename. Returns 2 if user wants to abort.
*******************************************************************************/
int getFileFailMenu()
{
	
	int menuChoice = 0;
	const int MIN_CHOICE = 1;
	const int MAX_CHOICE = 2;
	std::string userInput = "";

	std::cout << "\n\nThis file, is invalid." << std::endl;
			std::cout << "Would you like to try another file name?" <<
					"\n1. Yes\n2. No" << std::endl;
	
	while(true)
	{
		std::getline(std::cin,userInput);
		if(convertStringToInt(userInput,menuChoice,MIN_CHOICE,MAX_CHOICE))
		{
			switch(menuChoice)
			{
				case 1:
					return 1;
				case 2:
					return 2;
			};
		}
		else
		{
			std::cout << "Invalid choice." << std::endl;
		}
	}

}

/*******************************************************************************
 * 				bool getYesOrNo()
 * Description: Prompts user to enter 1 for "yes" or 2 for "no". Returns true
 * yes was selected, returns false if no wae selected
********************************************************************************/
bool getYesOrNo()
{
	
	int menuChoice = 0;
	const int MIN_CHOICE = 1;
	const int MAX_CHOICE = 2;
	std::string userInput = "";

	
	while(true)
	{

		std::cout << "1. Yes\n2. No" << std::endl;
		std::getline(std::cin,userInput);
		if(convertStringToInt(userInput,menuChoice,MIN_CHOICE,MAX_CHOICE))
		{
			switch(menuChoice)
			{
				case 1:
					return true;
				case 2:
					return false;
			};
		}
		else
		{
			std::cout << "Invalid choice." << std::endl;
		}
	}

}

/*******************************************************************************
 *						void pause()
 * Description: pauses the progress of the program until the user pushes enter.
*******************************************************************************/
void pause()
{
	std::cout << "\n\nPress [Enter] to continue.\n" << std::endl;
	std::string dummyString;
	std::getline(std::cin,dummyString);
}

/*******************************************************************************
 *					void clearTheScreen()
 * Description: clears the screen.
*******************************************************************************/
void clearTheScreen()
{
	//this was found at http://stackoverflow.com/questions/17335816/clear-scren
	//-using-c
	std::cout << "\033[2J\033[1;1H";
}

/*******************************************************************************
 *					 void getArray(&int*,&int)
 * Description: gets, from the user, an array of ints and populates it with
 * integers also from the user
*******************************************************************************/
void getArray(int *&array, int &size)
{
	bool gotGoodInt = false;
	std::string userInput = "";
	do
	{
		std::cout << "How many ints would you like to sum?" << std::endl;
		std::cout << "Enter an integer between 0 and 20." << std::endl;

		std::getline(std::cin,userInput);

		if(!convertStringToInt(userInput,size,0,20))
		{
			std::cout << "Invalid input. Please enter an integer " << 
					"between 0 and 20" << std::endl;
			pause();
		}
		else
		{
			gotGoodInt = true;
			array = new int[size];
		}

	}while(!gotGoodInt);

	for (int i = 0; i < size; i ++)
	{
		gotGoodInt = false;
		do
		{
			clearTheScreen();
			std::cout << "Enter int #" << i+1 << std::endl;

			std::getline(std::cin,userInput);

			if(!convertStringToInt(userInput,array[i],INT_MIN,INT_MAX))
			{
				std::cout << "Invalid input. Please enter an integer." <<
						std::endl;
				pause();
			}
			else
			{
				gotGoodInt = true;
			}

		}while(!gotGoodInt);

	}
}

/*******************************************************************************
 *					int getIntFromUser(int min, int max)
 * description: takes two ints as argumetns, min and max. Prompts the user for
 * an int between min and max, validates the input, reprompts if necessary.
 * Returns the validated int.
*******************************************************************************/
int getIntFromUser(int min, int max)
{
	std::string userInput = "";
	bool gotGoodInt = false;
	int returnInt;
	
	do
	{
		std::cout << "Please enter an integer between " << min << " and " << max
			<< "." << std::endl;

		std::getline(std::cin,userInput);
		
		if(convertStringToInt(userInput,returnInt,min,max))
		{
			gotGoodInt = true;
		}
		else
		{
			clearTheScreen();
			std::cout << "Invalid input." << std::endl;
			pause();
			clearTheScreen();
		}
		
	} while (!gotGoodInt);

	return returnInt;

}
