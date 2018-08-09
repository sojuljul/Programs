// ------------------------------------------------ businesslogic.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "businesslogic.h"

// ------------------------------------ buildAll -------------------------------------
// Description: Calls method to build the movie from text file
// and build the customers from text file
// ----------------------------------------------------------------------------------------------
void BusinessLogic::buildAll(ifstream& inFileMovie, ifstream& inFileCustomer)
{
	movieObj.buildMovieInventory(inFileMovie);
	customerObj.buildCustomerTable(inFileCustomer);
}

// ------------------------------------ commandReader -------------------------------------
// Description: Calls method to process the transactions from text file
// ----------------------------------------------------------------------------------------------
void BusinessLogic::commandReader(ifstream& inFileCommand)
{
	commandObj.processTransactions(inFileCommand, customerObj, movieObj);
}




