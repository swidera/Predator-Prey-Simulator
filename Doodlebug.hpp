/*******************************************************************************
 * File: Doodlebug.hpp
 * Author:
 * Date:
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
	private:
		int starvingCounter;
		Direction direction;

	public:
		Doodlebug(int,int);
		~Doodlebug();
		char printCritter() const override;
		bool move(Critter***,int,int,int,int) override;
		void breed(Critter***,int,int,int,int) override;
};



#endif



