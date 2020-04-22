//-------------------------------------------------------------------
// Filename: BakingRecepyManager.h
// Description: The header-file for the BakingRecepy-class. Contains all necessary methods and objects.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef BAKINGRECIPEMANAGER_H
#define BAKINGRECIPEMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Ingredient.h"
#include "BakingRecipe.h"

//------------------------------
// Classdefinition - BakingRecipe
//------------------------------
class BakingRecipeManager
{
private:

	// Contains all the available recipes
	std::vector<std::shared_ptr<BakingRecipe>> recipes;

public:

	/**
	* Constructor
	*/
	BakingRecipeManager(std::string fileName);

	/**
	*	Destructor
	*/
	~BakingRecipeManager() {};

	/**
	* Function (boolean) - isBakeable
	* Checks whetever all the needed ingredients are available or not
	* Returns: True if the needed ingredients exists. False if they do not exist.
	*/
	bool hasAnotherRecipe();

	/**
	* Getter (Recepy-name)
	*/
	std::shared_ptr<BakingRecipe> getNextBakingRecipe();
};

#endif