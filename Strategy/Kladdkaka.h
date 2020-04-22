//-------------------------------------------------------------------
// Filename: Kladdkaka.h
// Description: The header-file for the Kladdkaka-class. Contains all necessary methods.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef KLADDKAKA_H
#define KLADDKAKA_H
#include <iostream>
#include <string>
#include <vector>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Ingredient.h"
#include "BakingRecipe.h"

//------------------------------
// Classdefinition - Kladdkaka
// Inherits BakingRecipe
//------------------------------
class Kladdkaka : public BakingRecipe
{

public:

	/**
	* Constructor
	*/
	Kladdkaka() : BakingRecipe("Kladdkaka") {
		neededIng = { Ingredient("egg"), Ingredient("sugar"), Ingredient("baking-powder"), Ingredient("wheat-flour"), Ingredient("salt"), Ingredient("marge"), Ingredient("cocoa-powder") };
	};
	void bakeIt() 
	{ 
		for (Ingredient& ing : neededIng)
			std::cout << "Adding some " << ing.getName() << std::endl;	

		std::cout << "Voila! The Kladdkaka is finished." << std::endl;
		std::cout << std::endl;
	};
};

#endif