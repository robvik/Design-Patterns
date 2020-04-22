//-------------------------------------------------------------------
// Filename: NoBakingException.h
// Description: The header-file for the NoBakingException-class. Contains all necessary methods.
// Robin Viktorsson 2018-02-01 11:46
// Version 1.0
//-------------------------------------------------------------------
#ifndef NOBAKINGEXCEPTION_H
#define NOBAKINGEXCEPTION_H
#include <exception>

//------------------------------
// Classdefinition - NoBakingException
// Inherits Exception
//------------------------------
class NoBakingException : public std::exception
{

public:
	virtual const char* what() const throw() {
		return "You tried to access a recipe on an index outside the vectors range.";
	}
};

#endif