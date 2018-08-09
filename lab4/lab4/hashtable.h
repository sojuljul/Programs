// ------------------------------------------------ hashtable.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class represents an open hash table that will store customers
// It will be built as a linked list, and each customer is placed at the end
// It will have a const size for the table and a const hash to place the customers
// It will contain methods to insert and getCustomer
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "customer.h"

class HashTable
{
	static const int SIZE = 50; // size of the table
	static const int HASH_NUMBER = 10; // hash number for hash function

public:
	HashTable();
	~HashTable();

	bool insertCustomer(int id, Customer *newCustomer);
	Customer* getCustomer(int id);

private:
	struct HashNode;
	struct HashList
	{
		HashNode *head;
	};

	// linked list structure for hash table
	struct HashNode
	{
		Customer *data; // customer info
		int customerID; // customer id
		HashNode *next;
	};

	HashList table[SIZE]; // hash table
};

#endif