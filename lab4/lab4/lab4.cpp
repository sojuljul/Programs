// ------------------------------------------------ lab4.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is the main driver, which will read the three text files
// for movies, customers, and commands. Then, build all three.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "businesslogic.h"

int main()
{
	ifstream inFileMovie("data4movies.txt");
	ifstream inFileCustomer("data4customers.txt");
	ifstream inFileCommand("data4commands.txt");

	// check if valid text file
	if ((!inFileMovie) || (!inFileCustomer) || (!inFileCommand))
	{
		cout << "File cannot be opened" << endl;
		return 1; // failed
	}

	// build the movies, customers, and commands
	BusinessLogic manager;
	manager.buildAll(inFileMovie, inFileCustomer);
	manager.commandReader(inFileCommand);

    return 0;
}

