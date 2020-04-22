//-------------------------------------------------------------------
// Filename: Scones.h
// Description: The header-file for the Scones-class. Contains all necessary methods.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef SCONES_H
#define SCONES_H
#include <iostream>
#include <string>
#include <vector>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Ingredient.h"
#include "BakingRecipe.h"

//------------------------------
// Classdefinition - Scones
// Inherits BakingRecipe
//------------------------------
class Scones : public BakingRecipe
{

public:

	/**
	* Constructor
	*/
	Scones() : BakingRecipe("Scones") {
		neededIng = { Ingredient("oil"), Ingredient("baking-powder"), Ingredient("wheat-flour"), Ingredient("salt"), Ingredient("sugar"), Ingredient("milk") };
	};
	void bakeIt() 
	{  
		for (Ingredient& ing : neededIng)
			std::cout << "Adding some " << ing.getName() << std::endl;

		std::cout << "Voila! The Scones are finished." << std::endl;
		std::cout << std::endl;
	};
};

#endif