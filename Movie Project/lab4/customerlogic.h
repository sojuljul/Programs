// ------------------------------------------------ customerlogic.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class will build the customers from a text file in a hash table.
// It contains method to getCustomer from the hash table
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef CUSTOMERLOGIC_H
#define CUSTOMERLOGIC_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "hashtable.h"
#include "customer.h"

class CustomerLogic
{
public:
	CustomerLogic();
	~CustomerLogic();

	void buildCustomerTable(ifstream&);
	Customer* getCustomer(int id);

private:
	HashTable customerTable;
};

#endif