/*
File:       ConcreteDecorator.h
Objective:	Designmönster DT063G - DP Decorator
Last change: March 2018 / Robin Viktorsson
*/

#include <iostream>

class ConcreteDecorator : public ConcreteComponent {
public:
	ConcreteDecorator(ConcreteComponent *comp) : nextComp(comp) {}
	virtual ~ConcreteDecorator() { delete nextComp; }
	
	double getCost() { return nextComp->getCost(); }
	std::string getDesc() { return nextComp->getDesc(); }

private:

	std::string body;
	double price;
	ConcreteComponent *nextComp;
};

class SugarDecorator : public ConcreteDecorator {

public:
	SugarDecorator(ConcreteComponent *comp) : ConcreteDecorator(comp), productname("Sugar"), price(1) { std::cout << "Added Sugar..." << std::endl;  }

	std::string getDesc() { return ConcreteDecorator::getDesc().append(productname).append(" "); }
	double getCost() { return ConcreteDecorator::getCost() + price; }

private:
	std::string productname;
	double price;
};

class MilkDecorator : public ConcreteDecorator {

public:
	MilkDecorator(ConcreteComponent *comp) : ConcreteDecorator(comp), productname("Milk"), price(1) { std::cout << "Added Milk..." << std::endl; }

	std::string getDesc() { return ConcreteDecorator::getDesc().append(productname).append(" "); }
	double getCost() { return ConcreteDecorator::getCost() + price; }

private:
	std::string productname;
	double price;
};

class CreamDecorator : public ConcreteDecorator {

public:
	CreamDecorator(ConcreteComponent *comp) : ConcreteDecorator(comp), productname("Cream"), price(2) { std::cout << "Added Cream..." << std::endl; }

	std::string getDesc() { return ConcreteDecorator::getDesc().append(productname).append(" "); }
	double getCost() { return ConcreteDecorator::getCost() + price; }

private:
	std::string productname;
	double price;
};

class WhippedCreamDecorator : public ConcreteDecorator {

public:
	WhippedCreamDecorator(ConcreteComponent *comp) : ConcreteDecorator(comp), productname("Whipped Cream"), price(5)  { std::cout << "Added Whipped Cream..." << std::endl; }

	std::string getDesc() { return ConcreteDecorator::getDesc().append(productname).append(" "); }
	double getCost() { return ConcreteDecorator::getCost() + price;	}

private:
	std::string productname;
	double price;
};