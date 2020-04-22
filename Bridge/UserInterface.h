//-------------------------------------------------------------------
// Header filename: UserInterface.h
// Description: The header-file for the UserInterface-class. Contains all necessary variables, instances of other classes, containers, constructor and function definitions.
// Robin Viktorsson 2018-02-10 13:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <string>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Menu.h"
#include "SpaceShuttle.h"
#include "Submarine.h"
#include "Jetplane.h"
#include "PowerSource.h"
#include "Vehicle.h"
#include "GasTurbine.h"
#include "V8Classic.h"
#include "FuelCell.h"
#include "PowerSourceAdapters.h"

//------------------------------
// Classdefinition
//------------------------------
class UserInterface {

public:

	//Constructor and destructor
	UserInterface();
	~UserInterface() { delete vehicle; };

	//Run-method
	void run();

private:

	// The PowerSource is the implementator
	PowerSource* powerSource;
	Vehicle *vehicle; 

	//Instances of menu-classes
	Menu vehicleMenu;
	Menu powerSourceMenu;
	Menu actionMenu;

	//Menu-methods
	void mainMenu();
	void vehicleSubMenu();
	void simulationMenu();

};
#endif