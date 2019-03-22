/*******************************************************************************
** File: inputValidation.hpp, header file for the inputValidation helper
** 		functions
** Author: Jordan K Bartos
** Date: April 10, 2018
** Description: contains function headers for inputValidation functions
*******************************************************************************/

#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <string>
#include <random>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

bool isAnInt(const std::string&);
bool isADouble(const std::string&);
bool convertStringToInt(const std::string&,int&,int,int);
bool convertStringToDouble(const std::string&,double&,double,double);
int randomIntGenerator(int min, int max);
double randomDoubleGenerator(double min, double max);
void openFile(std::ifstream &file);
int getFileFailMenu();
bool getYesOrNo();
void pause();
void clearTheScreen();
void getArray(int*&,int&);
int getIntFromUser(int,int);


#endif
