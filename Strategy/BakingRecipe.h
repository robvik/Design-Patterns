//-------------------------------------------------------------------
// Filename: BakingRecepy.h
// Description: The header-file for the BakingRecepy-class. Contains all necessary methods and objects.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef BAKINGRECIPE_H
#define BAKINGRECIPE_H
#include <iostream>
#include <string>
#include <vector>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Ingredient.h"
#include "BakingRecipeManager.h"

//------------------------------
// Classdefinition - BakingRecepy
//------------------------------
class BakingRecipe
{
protected:

	// Recipename
	std::string iName;

	// Collection of all the needed ingredients
	std::vector<Ingredient> neededIng;

public:

	/**
	* Constructor
	*/
	BakingRecipe(std::string aName) : iName(aName) {}

	/**
	*	Destructor
	*/
	~BakingRecipe() { neededIng.clear(); };

	/**
	* Function definition
	* Name: bakeIt
	* Bakes the recipe
	*/
	virtual void bakeIt() = 0;

	/**
	* Function declaration
	* Name: isBakeable
	* Checks whetever all the needed ingredients are available or not
	* Returns: True if the needed ingredients exists. False if they do not exist.
	*/
	bool isBakeable(std::vector<Ingredient>& availableIngred) {

		for (Ingredient &neededIngredient : neededIng)
			if (!(std::find(availableIngred.begin(), availableIngred.end(), neededIngredient) != availableIngred.end()))
				return false;

		return true;
	};

	/**
	* Getter (Recipe-name)
	*/
	std::string getName() { return iName; }
};

#endif