// ------------------------------------------------ transfactory.h -------------------------------------------------------
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

#pragma once
#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"

class TransFactory
{
public:

	static Transaction* createTransaction(const char& actionType);
};

#endif