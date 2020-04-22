//-------------------------------------------------------------------
// Filename: Ingredient.h
// Description: The header-file for the Ingredient-class. Contains all necessary methods and objects.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <iostream>

//-------------------------------------------------------------------
// Including header-files
//-------------------------------------------------------------------

//------------------------------
// Classdefinition - Ingredient
//------------------------------
class Ingredient
{
private:

	// Recipename
	std::string iName;

public:

	/**
	* Constructor
	*/
	Ingredient(std::string aName) : iName(aName) {};

	/**
	*	Destructor
	*/
	~Ingredient() {};

	/**
	* Getter (Name)
	*/
	std::string getName() const { return iName; }

	/**
	* Operator overloading std::string
	*/
	operator std::string() const { return iName; }

	/**
	* Operator overloading ==
	*/
	bool operator==(const Ingredient &rhs) const {
		return iName == rhs.iName;
	}

};

#endif