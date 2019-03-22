/*******************************************************************************
 * File: Ant.hpp
 * Author: Gabriel Rice
 * Date: 5/6/18
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
	protected:
		Direction direction; //enum declaration
		int x; //left/right movement
		int y; //up/down movement
		
	public:
		Ant(int,int);
		void setX(int);
		void setY(int);
		int getX;
		int getY;
		bool move(Critter***,int,int,int,int);
		void breed(Critter***,int,int,int,int);
		~Ant() override;
		char printCritter() const override;
		bool step(int);

};



#endif

