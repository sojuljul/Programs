// ------------------------------------------------ return.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Transaction class
// It will override the doTransaction method to return a movie
// It will inherit protected data members/methods from Transaction
// It will have method readTransaction to determine the movie type
// and returnMovie to determine if successful transaction
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef RETURN_H
#define RETURN_H

#include <string>
#include <iostream>
using namespace std;

#include "transaction.h"

class Return: public Transaction
{
public:
	Return();
	~Return();

	virtual void doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager);

protected:
	void readTransaction(string info, Customer* newCustomer, MovieLogic& movManager);
	void returnMovie(Customer* newCustomer, Movie* customerMovie, Movie* tempMovie);
};

#endif