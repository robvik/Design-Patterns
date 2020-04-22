//-------------------------------------------------------------------
// Filename: UserInterface.cpp
// Description: This file is responsible for all userinterface-related code. It creates and presents the menu/submenus to the user.
// Robin Viktorsson 2018-02-07 12:46
// Version 1.0
//-------------------------------------------------------------------

//------------------------------------------------------------------------------
// Including header-files
//------------------------------------------------------------------------------
#include "UserInterface.h"
#include <iostream>

//------------------------------------------------------------------------------
// Constructor
// Name: UserInterface
// Description: Creates the menus and their contents/options which will be presented to the user.
//------------------------------------------------------------------------------
UserInterface::UserInterface()
{

	//Setting up the StartMenu
	vehicleMenu.setHeader("************* CHOOSE VEHICLE *************");
	vehicleMenu.addItem("Submarine");
	vehicleMenu.addItem("Spaceshuttle");
	vehicleMenu.addItem("Jetplane");

	//Setting up the SimulationMenu
	powerSourceMenu.setHeader("*********** CHOOSE POWERSOURCE ***********");
	powerSourceMenu.addItem("GasTurbine");
	powerSourceMenu.addItem("Fuel Cell");
	powerSourceMenu.addItem("V8Classic");

	actionMenu.setHeader("*********** CHOOSE ACTION ***********");
	actionMenu.addItem("Try to start vehicle");
	actionMenu.addItem("Drive");
	actionMenu.addItem("Increase Power");
	actionMenu.addItem("Decrease Power");
	actionMenu.addItem("Steer left");
	actionMenu.addItem("Steer right");
	actionMenu.addItem("Stop");
	actionMenu.addItem("Change Power source");
	actionMenu.addItem("Exit");
}

//------------------------------------------------------------------------------
// Function definition 
// Name: run
// Description: The first method which is run.
//------------------------------------------------------------------------------
void UserInterface::run()
{
	//Show the mainmenu
	mainMenu();
}

//------------------------------------------------------------------------------
// Function definition 
// Name: vehicleSubMenu
// Description: Once the powersource has been decided its time to choose the vehicle
//------------------------------------------------------------------------------
void UserInterface::vehicleSubMenu() {

	const int menuChoices = 3;
	bool go = true;
	do {

		vehicleMenu.printMenuItems();
		switch (vehicleMenu.getMenuChoice(menuChoices)) {
			case 1: // Submarine
				vehicle = new Submarine(powerSource);
				simulationMenu();
				go = false;
				break;

			case 2: // Spaceshuttle
				vehicle = new SpaceShuttle(powerSource);
				simulationMenu();
				go = false;
				break;

			case 3: // Jetplane
				vehicle = new Jetplane(powerSource);
				simulationMenu();
				go = false;
				break;
		}
	} while (go);
}

//------------------------------------------------------------------------------
// Function definition 
// Name: mainMenu
// Description: This menu is the initiating menu which allows the user to select the vehicle
//------------------------------------------------------------------------------
void UserInterface::mainMenu()
{
	const int menuChoices = 3;
	bool go = true;
	do {

		powerSourceMenu.printMenuItems();
		switch (powerSourceMenu.getMenuChoice(menuChoices)) {
			case 1: // GasTurbine adapter
				powerSource = new GasTurbineAD();
				vehicleSubMenu();
				go = false;
				break;
			case 2: // Fuel Cell adapter
				powerSource = new FuelCellAD();
				vehicleSubMenu();
				go = false;
				break;
			case 3: // V8Classic adapter
				powerSource = new V8ClassicAD();
				vehicleSubMenu();
				go = false;
				break;
		}

	} while (go);
}

//------------------------------------------------------------------------------
// Function definition 
// Name: simulationMenus
// Description: This is an action-based menu. It allows the user to control the vehicle.
//------------------------------------------------------------------------------
void UserInterface::simulationMenu() {

	std::cout << "Vehicle information:" << std::endl;
	std::cout << vehicle->toString() << std::endl;

	const int menuChoices = 9;
	bool go = true;
	do {

		actionMenu.printMenuItems();
		int powerInc = 0, powerDec = 0, degreesLeft = 0, degreesRight = 0, answer;
		switch (actionMenu.getMenuChoice(menuChoices)) {
		case 1: // Try to start	
			vehicle->tryStart();
			break;
		case 2: // Drive
			vehicle->drive();
			break;
		case 3: // Increase power
			std::cout << "How much power do you wish to increase? ";	
			std::cin >> powerInc;
			vehicle->incPower(powerInc);
			break;
		case 4: // Decrease power
			std::cout << "How much power do you wish to decrease? ";
			std::cin >> powerDec;
			vehicle->decPower(powerDec);
			break;
		case 5: // Steer left
			std::cout << "How many degrees do you want to steer to left? ";
			std::cin >> degreesLeft;
			vehicle->steerLeft(degreesLeft);
			break;
		case 6: // Steer right
			std::cout << "How many degrees do you want to steer to right? ";
			std::cin >> degreesRight;
			vehicle->steerRight(degreesRight);
			break;
		case 7: // Stop
			vehicle->stop();
			break;
		case 8: // Change powersource
			
			do {
				std::cout << "Which powersource do you want to change to?" << std::endl;
				std::cout << "1. GasTurbine" << std::endl << "2. FuelCell" << std::endl << "3. V8Classic" << std::endl;
				std::cin >> answer;
			} while (answer <= 0 || answer > 3);

			if (answer == 1)
				vehicle->setPowerSource(new GasTurbineAD());
			else if (answer == 2) 
				vehicle->setPowerSource(new FuelCellAD());
			else if (answer == 3) 
				vehicle->setPowerSource(new V8ClassicAD());
			else
				std::cout << "Default: Error." << std::endl;

			std::cout << "Vehicle is now powered by: " << vehicle->poweredBy() << std::endl;
			break;
		case 9:  // Exit
			go = false;
			break;
		}
	} while (go);

}