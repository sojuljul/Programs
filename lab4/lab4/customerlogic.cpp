// ------------------------------------------------ customerlogic.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "customerlogic.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
CustomerLogic::CustomerLogic()
{
}

// ------------------------------------ Destructor ------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
CustomerLogic::~CustomerLogic()
{
}

// ------------------------------------ buildCustomerTable -------------------------------------
// Description: It will read in a text file of customers containing their ID, 
// first name, and last name per line. It will store the customers in a 
// hash table.
// ----------------------------------------------------------------------------------------------
void CustomerLogic::buildCustomerTable(ifstream& inFileCustomer)
{
	int customerID = 0;
	string firstName = "";
	string lastName = "";
	string temp = ""; // temp string

	for (;;)
	{
		getline(inFileCustomer, temp, ' '); // read ID
		stringstream(temp) >> customerID; // convert string to int
		getline(inFileCustomer, lastName, ' '); // read last name
		getline(inFileCustomer, firstName); // read first name

		if (inFileCustomer.eof()) // if end of file
		{
			break;
		}

		Customer* newCustomer = new Customer(customerID, lastName, firstName); // create customer object
		bool success = customerTable.insertCustomer(customerID, newCustomer); // insert into hash table

		if (!success) // if invalid
		{
			delete newCustomer; // delete customer
			newCustomer = NULL;
		}
	}
}

// ------------------------------------ getCustomer -------------------------------------
// Description: Returns a customer by finding it in the hash table based on the ID
// Otherwise, returns null if not found
// ----------------------------------------------------------------------------------------------
Customer* CustomerLogic::getCustomer(int id)
{
	Customer* newCustomer = NULL;
	newCustomer = customerTable.getCustomer(id);
	return newCustomer;
}
