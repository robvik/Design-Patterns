#include "Vehicle.h"
#include <iostream>
#include "GasTurbine.h"
std::string Vehicle::toString()
{
	std::string vehicleInfo = "Powersource: " + powerSource->type();
	if (powerSource->isRunning())
		vehicleInfo += " Status: Running";
	else
		vehicleInfo += " Status: Not running";

	return vehicleInfo;
}

std::string Vehicle::poweredBy()
{
	return powerSource->type();
}

bool Vehicle::isRunning() {
	return powerSource->isRunning();
}

bool Vehicle::tryStart()
{
	if (powerSource->isRunning()) {
		std::cout << "The vehicle is already started." << std::endl;
		return false;
	}
	else { // Vehicle is not running. Lets start it up
		powerSource->tryStart();
		return true;
	}
}

bool Vehicle::stop()
{
	if (powerSource->isRunning()) {
		powerSource->stop();
		return true;
	} else return false;
}

bool Vehicle::incPower(int p)
{
	bool success = powerSource->incPower(p) ? true : false;
	return success;
}

bool Vehicle::decPower(int p)
{
	bool success = powerSource->decPower(p) ? true : false;
	return success;
}

void Vehicle::setPowerSource(PowerSource* ps)
{
	delete powerSource;
	powerSource = ps;
}
