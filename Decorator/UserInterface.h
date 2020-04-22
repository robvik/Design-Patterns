/*
File:       UserInterface.h
Objective:	Designmönster DT063G - DP Decorator
Last change: March 2018 / Robin Viktorsson
*/

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "ConcreteComponents.h"
#include "ConcreteDecorator.h"

class UserInterface {

public:
	~UserInterface() { delete firstComp; }

	void run();
	void printDesc() { std::cout << firstComp->getDesc().append(" "); }
	void printCost() { std::cout << firstComp->getCost(); }

private:
	ConcreteComponent *firstComp;
};
#endif