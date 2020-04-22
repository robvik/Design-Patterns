//-------------------------------------------------------------------
// Filename: BakingRecipeManager.cpp
// Description: Contains the constructor/methods necessary to the BakingRecipeManager-class
// Robin Viktorsson 2018-01-25 11:46
// Version 1.0
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "BakingRecipeManager.h"
#include "NoBakingException.h"
#include "Pizza.h"
#include "Scones.h"
#include "Sockerkaka.h"
#include "Kladdkaka.h"
#include "BakingRecipe.h"

//------------------------------------------------------------------------------
// Constructor
// Description: The constructor reads ingredients from a textfile, stores the ingredient in a temporary array
// and checks whetever they are necessary to bake available recipes
//------------------------------------------------------------------------------
BakingRecipeManager::BakingRecipeManager(std::string fileName) {

	std::ifstream file;
	file.open(fileName);
	if (!file.is_open()) //Make sure the file is opened otherwise theres nothing to be ready
		throw std::runtime_error("Could not open " + fileName);

	std::vector<Ingredient> ingredients;
	std::string str;
	try {
		while (std::getline(file, str)) { //Loop through all lines in the file
			ingredients.push_back(str);
		}
	}
	catch (std::ios_base::failure e) {
		std::cout << "Could not read " << fileName << std::endl;
		throw;
	}
	file.close();

	// Store and add recipes if they are bakeable
	std::shared_ptr<BakingRecipe> pizza(new Pizza());
	if (pizza->isBakeable(ingredients))
		recipes.push_back(pizza);

	std::shared_ptr<BakingRecipe> scones(new Scones());
	if (scones->isBakeable(ingredients))
		recipes.push_back(scones);

	std::shared_ptr<BakingRecipe> kladdkaka(new Kladdkaka());
	if (kladdkaka->isBakeable(ingredients))
		recipes.push_back(kladdkaka);

	std::shared_ptr<BakingRecipe> sockerkaka(new Sockerkaka());
	if (sockerkaka->isBakeable(ingredients))
		recipes.push_back(sockerkaka);

};

//------------------------------------------------------------------------------
// Function definition
// Name: getNextBakingRecipe
// Description: Fetched and erases the next available recipe, if any
// Returns: An BakingRecipe-pointer to the recipe if any is available, otherwise it returns NULL
//------------------------------------------------------------------------------
std::shared_ptr<BakingRecipe> BakingRecipeManager::getNextBakingRecipe()
{
	try {

		int index = 0;
		if (index < 0 || index > recipes.size())
			throw NoBakingException();
		else {
			std::shared_ptr<BakingRecipe> recipe = recipes.at(index);
			recipes.erase(recipes.begin());
			return recipe;
		}
	}
	catch (NoBakingException &e) {
		std::cout << e.what() << std::endl;
	}

	return NULL;
};

//------------------------------------------------------------------------------
// Function definition
// Name: hasAnotherRecipe
// Description: Checks whetever theres another recipe to bake or not
// Returns: True if there are still available recipes, otherwise false
//------------------------------------------------------------------------------
bool BakingRecipeManager::hasAnotherRecipe()
{
	if (recipes.size() >= 1)
		return true;
	else
		return false;
};