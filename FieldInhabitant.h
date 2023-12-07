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

