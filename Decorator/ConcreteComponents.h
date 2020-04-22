/*
File:       ConcreteComponents.h
Objective:	Designmönster DT063G - DP Decorator
Last change: March 2018 / Robin Viktorsson
*/

#include <string>

class ConcreteComponent {
public:
	virtual ~ConcreteComponent() {}
	virtual std::string getDesc() = 0;
	virtual double getCost() = 0;
};

class CoffeComponent : public ConcreteComponent {
public:
	CoffeComponent() : productname("Coffee"), price(10) { std::cout << "You choose Coffee..." << std::endl; }

	std::string getDesc() { return productname.append(" "); }
	double getCost() { return price; }

private:
	std::string productname;
	double price;
};


class EspressoComponent : public ConcreteComponent {
public:
	EspressoComponent() : productname("Espresso"), price(14) { std::cout << "You choose Espresso..." << std::endl; }

	std::string getDesc() { return productname.append(" "); }
	double getCost() { return price; }

private:
	std::string productname;
	double price;
};

class TeaComponent : public ConcreteComponent {
public:
	TeaComponent() : productname("Tea"), price(10) { std::cout << "You choose Tea..." << std::endl; }

	std::string getDesc() { return productname.append(" "); }
	double getCost() { return price; }

private:
	std::string productname;
	double price;
};

class ChocolateComponent : public ConcreteComponent {
public:
	ChocolateComponent() : productname("Chocolate"), price(12) { std::cout << "You choose Chocolate..." << std::endl; }

	std::string getDesc() { return productname.append(" "); }
	double getCost() { return price; }

private:
	std::string productname;
	double price;
};