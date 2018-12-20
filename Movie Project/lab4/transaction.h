// ------------------------------------------------ transaction.h -------------------------------------------------------
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

#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "customerlogic.h"
#include "movielogic.h"

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

	virtual void doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager);
	string getCustomerErrors();

protected:
	bool checkCustomer(Customer* newCustomer, int id);
	string errorCustomer;
	void addError(string error);
};

#endif
