/*
o A string member variable to store a symbol
o A declaration for a public constructor that takes in a parameter representing a string symbol for
	the field inhabitant (vegetable, rabbit, captain, etc)
o Declarations for appropriate getter/setter functions
o A declaration for a virtual deconstructor
o Appropriate header guards
*/

#pragma once
#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H
#include <string>

using namespace std;

class FieldInhabitant{
private:
	string symbol;

public:
	// constructor
	FieldInhabitant(const string& symbol);

	// Getter Symbol
	string getSymbol() const;

	// Setter Symbol
	void setSymbol(const string& newSymbol);
	
	// vitual destructor
	virtual ~FieldInhabitant();
};

#endif // FIELDNHABITANT.H

