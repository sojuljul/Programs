// ------------------------------------------------ commandlogic.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "commandlogic.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initialize the error string
// ----------------------------------------------------------------------------------------------
CommandLogic::CommandLogic()
{
	errorTransaction = "";
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
CommandLogic::~CommandLogic()
{
}

// ------------------------------------ processTransactions -------------------------------------
// Description: It will read in a text file of transactions per line. 
// This will print an error message if a line contains an invalid transaction type, 
// incorrect customer ID, invalid media type, invalid movie type, and/or invalid movie data.
// ----------------------------------------------------------------------------------------------
void CommandLogic::processTransactions(ifstream& inFileCommand, CustomerLogic& cusManager, MovieLogic& movManager)
{
	char actionCode = ' ';
	string tempLine = ""; // temp string
	Transaction* newTrans = NULL;

	for (;;)
	{
		inFileCommand >> actionCode; // read transaction type
		newTrans = TransFactory::createTransaction(actionCode); // create transaction object

		if (inFileCommand.eof()) // if end of file
		{
			break;
		}

		switch (actionCode)
		{
		case 'I': // inventory
			getline(inFileCommand, tempLine); // get line
			newTrans->doTransaction(tempLine, cusManager, movManager); // do inventory
			errorTransaction += newTrans->getCustomerErrors(); // add errors from transaction
			delete newTrans; // delete trans object
			newTrans = NULL;
			break;
		case 'H': // history
			getline(inFileCommand, tempLine); // get line
			newTrans->doTransaction(tempLine, cusManager, movManager); // do history
			errorTransaction += newTrans->getCustomerErrors(); // add errors from transaction
			delete newTrans; // delete trans object
			newTrans = NULL;
			break;
		case 'B': // borrow
			getline(inFileCommand, tempLine); // get line
			newTrans->doTransaction(tempLine, cusManager, movManager); // do borrow
			errorTransaction += newTrans->getCustomerErrors(); // add errors from transaction
			delete newTrans; // delete trans object
			newTrans = NULL;
			break;
		case 'R': // return
			getline(inFileCommand, tempLine); //get line
			newTrans->doTransaction(tempLine, cusManager, movManager); // do return
			errorTransaction += newTrans->getCustomerErrors(); // add errors from transaction
			delete newTrans; // delete trans object
			newTrans = NULL;
			break;
		default: // if invalid transaction type
			getline(inFileCommand, tempLine); // get line
			string errorType(1, actionCode); // convert char into string
			errorTransaction += "ERROR: Invalid Transaction Type: " + errorType + tempLine + "\n";
			break;
		}
	}

	delete newTrans; // delete trans object
	newTrans = NULL;
	displayTransError(); // display all errors
}

// ------------------------------------ displayTransError -------------------------------------
// Description: Outputs all the errors from the transactions after reading text file
// ----------------------------------------------------------------------------------------------
void CommandLogic::displayTransError() const
{
	cout << "---------- Invalid Transactions ----------" << endl;
	cout << errorTransaction << endl;
}