// ------------------------------------------------ history.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Transaction class
// It will inherit the protected data members/methods from Transaction
// It will override the doTransaction method to display the history of transactions
// for a given customer
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "history.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes the error string
// ----------------------------------------------------------------------------------------------
History::History()
{
	errorCustomer = "";
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
History::~History()
{
}

// ------------------------------------ doTransaction -------------------------------------
// Description: Reads a line from the text file to find the customer
// If found, display the customers transaction history
// ----------------------------------------------------------------------------------------------
void History::doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager)
{
	int customerID = 0;
	Customer* newCustomer = NULL;

	stringstream readLine; // takes in a line
	readLine << line; // contains line

	readLine >> customerID; // read ID
	newCustomer = cusManager.getCustomer(customerID); // find customer

	if (checkCustomer(newCustomer, customerID)) // if valid customer
	{
		newCustomer->movieHistory(); // display history of borrow/return
	}
}