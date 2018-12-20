// ------------------------------------------------ history.h -------------------------------------------------------
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

#pragma once
#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "transaction.h"
#include "customerlogic.h"
#include "movielogic.h"

class History: public Transaction
{
public:
	History();
	~History();

	virtual void doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager);
};

#endif