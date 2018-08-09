// ------------------------------------------------ businesslogic.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class contains methods to read the text files
// to build the movies, customers, and process the commands.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "commandlogic.h"
#include "customerlogic.h"
#include "movielogic.h"

class BusinessLogic 
{
public:
	void buildAll(ifstream&, ifstream&); // movies and customers
	void commandReader(ifstream&); // transactions

private:
	// objects for building each file
	CustomerLogic customerObj;
	MovieLogic movieObj;
	CommandLogic commandObj;
};

#endif