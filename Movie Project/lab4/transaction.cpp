// ------------------------------------------------ transaction.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is the base class for the different types of transactions
// It will have Borrow, Return, Inventory, History for its sub-classes
// It will keep track of errors in a string
// It will contain a method to do a transaction, which will be overriden in subclasses
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "transaction.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes the error string
// ----------------------------------------------------------------------------------------------
Transaction::Transaction()
{
	errorCustomer = "";
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Transaction::~Transaction()
{
}

// ------------------------------------ doTransaction -------------------------------------
// Description: Do nothing. It will be inherited from sub-classes
// Borrow, Return, Inventory, History will override this method
// ----------------------------------------------------------------------------------------------
void Transaction::doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager)
{
}

// ------------------------------------ checkCustomer -------------------------------------
// Description: Takes in a customer and an ID
// Return true if valid customer; otherwise, returns false
// ----------------------------------------------------------------------------------------------
bool Transaction::checkCustomer(Customer* newCustomer, int id)
{
	if (newCustomer == NULL) // if customer is null
	{
		ostringstream temp; // takes in a line
		temp << id; // read ID
		addError("ERROR: Invalid ID: " + temp.str()); // convert to string
		return false;
	}
	else // customer is valid
	{
		return true;
	}
}

// ------------------------------------ getCustomerErrors -------------------------------------
// Description: Returns all the errors built as a string
// ----------------------------------------------------------------------------------------------
string Transaction::getCustomerErrors()
{
	return errorCustomer;
}

// ------------------------------------ addError -------------------------------------
// Description: Takes in a string and concatenates it to the error string
// ----------------------------------------------------------------------------------------------
void Transaction::addError(string error)
{
	errorCustomer += error + "\n";
}