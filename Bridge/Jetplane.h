//------------------------------
// Header filename: Jetplane.h
// Robin Viktorsson 2018-02-10 08:57
// Description: The header-file for the Jetplane-class. Contains all constructor and function definitions necessary for this class.
// Version: 1.0
//------------------------------
#ifndef JETPLANE_H
#define JETPLANE_H

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "Vehicle.h"

//------------------------------
// Classdefinition
// Name: Jetplane
// Inherits Vehicle
//------------------------------
class Jetplane : public Vehicle
{
public:

	// Constructor and destructor
	Jetplane(PowerSource* powerSource) : Vehicle(powerSource) {};
	~Jetplane() { };

	// Functions
	void drive() override // Start driving the Jetplane
	{
		if (isRunning())
			std::cout << "Starting to drive Jetplane..." << std::endl;
		else
			std::cout << "You have to start the Jetplane first." << std::endl;
	};

	void steerLeft(int degrees) override // Steer the Jetplane to the left
	{
		if (isRunning())
			std::cout << "You steer the Jetplane " << degrees << " degrees to the left." << std::endl;
		else
			std::cout << "You have to start the Jetplane first." << std::endl;
	};

	void steerRight(int degrees) override // Steer the Jetplane to the right
	{
		if (isRunning())
			std::cout << "You steer the Jetplane " << degrees << " degrees to the right." << std::endl;
		else
			std::cout << "You have to start the Jetplane first." << std::endl;
	};
};

#endif