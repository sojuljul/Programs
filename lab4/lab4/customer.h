// ------------------------------------------------ customer.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class contains customer info, like ID, first name, last name.
// It will keep track of each customers transaction in a vector of linked list
// It will handle borrow/return methods and store them in the vector
// Has overloaded operator== and != to check for duplicate customers
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "movie.h"

class Customer
{
public:
	Customer();
	~Customer();
	Customer(int id, string lastName, string firstName);

	string getFirstName();
	string getLastName();
	int getID();
	bool operator==(const Customer& other) const;
	bool operator!=(const Customer& other) const;
	bool borrowMovie(Movie* newMovie);
	bool returnMovie(Movie* newMovie);
	void movieHistory();

	string getInfo();

private:
	int customerID;
	string lastName;
	string firstName;
	int oneStock;

	bool borrowMovieHelper(Movie* newMovie); // helper method for borrowMovie
	bool returnMovieHelper(Movie* newMovie); // helper method for returnMovie

	bool addTransaction(const char transType, Movie* newMovie);
	vector<string> transHistory; // vector of transactions

	// linked list structure for transaction history
	struct TransactionList
	{
		Movie* data;
		char transType;
		TransactionList* next;
	};
	TransactionList* rootList;

	// linked list structure for borrow/return
	struct TransactionNode
	{
		Movie* data;
		char transType;
		TransactionNode* next;
	};
	TransactionNode* root;
};

#endif