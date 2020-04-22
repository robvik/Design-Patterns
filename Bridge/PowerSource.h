//------------------------------
// Header filename: PowerSource.h
// Robin Viktorsson 2018-02-10 08:57
// Description: The header-file for the PowerSource-class. Contains all constructor and function definitions necessary for this class.
// Version: 1.0
//------------------------------
#ifndef POWERSOURCE_H
#define POWERSOURCE_H
#include <string>
#include <iostream>

//------------------------------
// Classdefinition
// Name: PowerSource
//------------------------------
class PowerSource 
{
public:

	// Constructor and destructor
	PowerSource(std::string type) :typeStr(type) {};
	virtual ~PowerSource() = default;

	// Function definitions
	const std::string& type() const { return typeStr; } // Returns a string containing info about the type of the powersource
	virtual bool isRunning() const = 0; // Pure virtual function
	virtual bool tryStart() = 0;    // returns true if success, else false
	virtual void stop() = 0; // Pure virtual functions
	virtual bool setPower(int p) = 0;   // returns true if success, else false
	virtual bool incPower(int p = 10) = 0;    // returns true if success, else false
	virtual bool decPower(int p = 10) = 0;    // returns true if success, else false

private:
	std::string typeStr;  // A descriptive name
};

#endif
