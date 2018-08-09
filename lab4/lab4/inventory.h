// ------------------------------------------------ inventory.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Transaction class
// It will override the doTransaction method to display the inventory of all movies
// from Classic, Comedy, Drama
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "transaction.h"
#include "customerlogic.h"
#include "movielogic.h"

class Inventory: public Transaction
{
public:
	Inventory();
	~Inventory();

	virtual void doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager);
};

#endif