//-------------------------------------------------------------------
// Filename: main.cpp
// Description: The startpoint of the program.
// Robin Viktorsson 2018-02-10 12:46
// Version 1.0
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "UserInterface.h"

//------------------------------
// Classdefinition
// Name: main
// Description: Creates an instance of the UserInterface-class and runs it so the user is presented to the menu
//------------------------------
int main()
{

	UserInterface ui; //Create an instance of UserInterface-class...
	ui.run(); //...and start its run-function

	system("pause");
    return 0;
}

