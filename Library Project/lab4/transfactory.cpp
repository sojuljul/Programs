// ------------------------------------------------ transfactory.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This will contain a method to create a transaction object
// It will contain Borrow, Return, Inventory, History classes for it to create
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "transfactory.h"

// ------------------------------------ createTransaction -------------------------------------
// Description: Returns a new transaction object depending on the transaction type
// It can create a Borrow, Return, Inventory, or History object
// ----------------------------------------------------------------------------------------------
Transaction* TransFactory::createTransaction(const char& actionType)
{
	Transaction *newTrans = NULL;

	switch (actionType)
	{
	case 'B': // borrow
		newTrans = new Borrow();
		break;
	case 'R': // return
		newTrans = new Return();
		break;
	case 'I': // inventory
		newTrans = new Inventory();
		break;
	case 'H': // history
		newTrans = new History();
		break;
	default: // if invalid transaction type
		newTrans = NULL;
		break;
	}

	return newTrans;
}
