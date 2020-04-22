//------------------------------
// Header filename: Submarine.h
// Robin Viktorsson 2018-02-10 08:57
// Description: The header-file for the Submarine-class. Contains all constructor and function definitions necessary for this class.
// Version: 1.0
//------------------------------
#ifndef SUBMARINE_H
#define SUBMARINE_H

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Vehicle.h"

//------------------------------
// Classdefinition
// Name: Submarine
// Inherits Vehicle
//------------------------------
class Submarine : public Vehicle
{
public:

	// Constructor and destructor
	Submarine(PowerSource* powerSource) : Vehicle(powerSource) {}
	~Submarine() {};

	// Functions 
	void drive() override // Start driving the Submarine
	{ 
		if (isRunning())
			std::cout << "Starting to drive Submarine..." << std::endl;
		else
			std::cout << "You have to start the Submarine first." << std::endl;
	};

	void steerLeft(int degrees) override // Steer the Submarine to the left
	{ 
		if (isRunning())
			std::cout << "You steer the Submarine " << degrees << " degrees to the left." << std::endl;
		else
			std::cout << "You have to start the Submarine first." << std::endl;
	};

	void steerRight(int degrees) override  // Steer the Submarine to the right
	{
		if (isRunning())
			std::cout << "You steer the Submarine " << degrees << " degrees to the right." << std::endl;
		else
			std::cout << "You have to start the Submarine first." << std::endl;
	};
};

#endif