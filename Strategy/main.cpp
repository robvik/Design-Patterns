//-------------------------------------------------------------------
// Filename: Bakery.cpp
// Description: The startpoint of the program. Creates instances of objects and calls functions necessary to run the program. 
// Robin Viktorsson 2018-02-03 11:46
// Version 1.0
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "BakingRecipeManager.h"
#include "BakingRecipe.h"

//------------------------------------------------------------------------------
// Function definition 
// Name: main
// Description: Creates an pointer to the following classes: BakingRecipeManager and BakingRecipe
// Iterates through the available recipes and bakes them
//------------------------------------------------------------------------------
int main()
{
	std::unique_ptr<BakingRecipeManager> bakingManager(new BakingRecipeManager("skafferi.dat"));
	std::shared_ptr<BakingRecipe> recipe = NULL;

	do {

		recipe = bakingManager->getNextBakingRecipe();
		std::cout << "Recipe name: " << recipe->getName() << std::endl;
		recipe->bakeIt();

	} while (bakingManager->hasAnotherRecipe());

	system("pause");
	return 0;
}