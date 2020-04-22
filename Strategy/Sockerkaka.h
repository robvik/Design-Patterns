//-------------------------------------------------------------------
// Filename: Sockerkaka.h
// Description: The header-file for the Sockerkaka-class. Contains all necessary methods.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef SOCKERKAKA_H
#define SOCKERKAKA_H
#include <iostream>
#include <string>
#include <vector>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Ingredient.h"
#include "BakingRecipe.h"

//------------------------------
// Classdefinition - Sockerkaka
// Inherits BakingRecipe
//------------------------------
class Sockerkaka : public BakingRecipe
{
public:

	/**
	* Constructor
	*/
	Sockerkaka() : BakingRecipe("Sockerkaka") {
		neededIng = { Ingredient("egg"), Ingredient("sugar"), Ingredient("baking-powder"), Ingredient("wheat-flour"), Ingredient("marge"), Ingredient("lemon") };
	};
	void bakeIt() 
	{  
		for (Ingredient& ing : neededIng)
			std::cout << "Adding some " << ing.getName() << std::endl;
		
		std::cout << "Voila! The Sockerkaka is finished." << std::endl;
		std::cout << std::endl;
	};
};

#endif