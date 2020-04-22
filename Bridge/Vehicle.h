//------------------------------
// Header filename: Vehicle.h
// Robin Viktorsson 2018-02-10 08:57
// Description: The header-file for the Vehicle-class. Contains all constructor and function definitions necessary for this class.
// Version: 1.0
//------------------------------
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------
#include "PowerSource.h"

//------------------------------
// Classdefinition
// Name: Vehicle
//------------------------------
class Vehicle
{

public:
	
	// Constructor and destructor
	Vehicle(PowerSource* powerSource) : powerSource(powerSource) {};
	virtual ~Vehicle() { delete powerSource; };
	
	// Function definitions
	std::string toString(); // e.g."SpaceShutte"
	std::string poweredBy(); // e.g."FuelCell"
	bool isRunning();
	bool tryStart(); // Try to start the powersource
	bool stop(); // Stop the powersource
	bool incPower(int p = 5); // Increase power
	bool decPower(int p = 5); // Decrease power
	virtual void drive() = 0; // Simulate a driving scenario
	void setPowerSource(PowerSource* ps); // Change PowerSource

	//Operations for steering
	virtual void steerLeft(int degrees) = 0;
	virtual void steerRight(int degrees) = 0;

private:
	PowerSource* powerSource;
};

#endif