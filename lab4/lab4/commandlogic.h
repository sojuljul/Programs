// ------------------------------------------------ commandlogic.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class will process the transactions from a text file.
// It will keep track of error inputs in a string
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef COMMANDLOGIC_H
#define COMMANDLOGIC_H
#include <string>
#include <iostream>
#include <fstream>

#include "movie.h"
#include "movielogic.h"
#include "customerlogic.h"
#include "transfactory.h"

class CommandLogic
{
public:
	CommandLogic();
	virtual ~CommandLogic();

	void processTransactions(ifstream&, CustomerLogic&, MovieLogic&);
	void displayTransError() const;

private:
	string errorTransaction; // keep track of errors
};

#endif