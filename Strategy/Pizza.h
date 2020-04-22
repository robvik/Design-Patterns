//-------------------------------------------------------------------
// Filename: Pizza.h
// Description: The header-file for the Pizza-class. Contains all necessary methods and objects.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
#include <vector>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Ingredient.h"
#include "BakingRecipe.h"

//------------------------------
// Classdefinition - Pizza
// Inherits BakingRecipe
//------------------------------
class Pizza : public BakingRecipe
{

public:

	/**
	* Constructor
	*/
	Pizza() : BakingRecipe("Pizza") {
		neededIng = { Ingredient("oil"), Ingredient("yeast"), Ingredient("wheat-flour"), Ingredient("salt") };
	};
	void bakeIt() 
	{
		for (Ingredient& ing : neededIng)
			std::cout << "Adding some " << ing.getName() << std::endl;

		std::cout << "Voila! The Pizza is finished." << std::endl;
		std::cout << std::endl;
	};

};

#endif