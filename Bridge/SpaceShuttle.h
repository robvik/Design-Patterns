//------------------------------
// Header filename: SpaceShuttle.h
// Robin Viktorsson 2018-02-10 08:57
// Description: The header-file for the SpaceShuttle-class. Contains all constructor and function definitions necessary for this class.
// Version: 1.0
//------------------------------
#ifndef SPACESHUTTLE_H
#define SPACESHUTTLE_H

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Vehicle.h"

//------------------------------
// Classdefinition
// Name: SpaceShuttle
// Inherits Vehicle
//------------------------------
class SpaceShuttle : public Vehicle
{
public:

	// Constructor and destructor
	SpaceShuttle(PowerSource* powerSource) : Vehicle(powerSource) {};
	~SpaceShuttle() {};

	// Functions
	void drive() override // Start driving the SpaceShuttle
	{
		if (isRunning())
			std::cout << "Starting to drive SpaceShuttle..." << std::endl;
		else
			std::cout << "You have to start the SpaceShuttle first." << std::endl;
	};

	void steerLeft(int degrees) override // Steer the SpaceShuttle to the left
	{
		if (isRunning())
			std::cout << "You steer the SpaceShuttle " << degrees << " degrees to the left." << std::endl;
		else
			std::cout << "You have to start the SpaceShuttle first." << std::endl;
	};

	void steerRight(int degrees) override // Steer the SpaceShuttle to the right
	{
		if (isRunning())
			std::cout << "You steer the SpaceShuttle " << degrees << " degrees to the right." << std::endl;
		else
			std::cout << "You have to start the SpaceShuttle first." << std::endl;
	};
};

#endif