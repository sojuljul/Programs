// ------------------------------------------------ hashtable.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "hashtable.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initialize each elements head in the table to null
// ----------------------------------------------------------------------------------------------
HashTable::HashTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		table[i].head = NULL; // head is null
	}
}

// ------------------------------------ Destructor -------------------------------------
// Description: Delete the data and node of each element in all buckets of the table
// ----------------------------------------------------------------------------------------------
HashTable::~HashTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (table[i].head != NULL)
		{
			HashNode *current = table[i].head; // point to head

			while (current != NULL)
			{
				table[i].head = table[i].head->next; // head points to next
				delete current->data; // delete data
				current->data = NULL;
				delete current; // delete node
				current = table[i].head; // point to new head
			}
		}
	}
}

// ------------------------------------ insertCustomer -------------------------------------
// Description: Insert customer in the hash table according to their ID
// Uses a hash number to determine which bucket the customer will be stored in
// Check for invalid ID if > 9999 or < 0
// ----------------------------------------------------------------------------------------------
bool HashTable::insertCustomer(int id, Customer *newCustomer)
{
	if (id > 9999 || id < 0) // check for invalid id
	{
		return false;
	}

	int hashValue = (id % HASH_NUMBER); // determine bucket in table

	HashNode *insNode = new HashNode; // new node
	insNode->customerID = id; // store id
	insNode->data = newCustomer; // store customer info
	insNode->next = NULL;

	if (table[hashValue].head == NULL) // if empty
	{
		insNode->next = table[hashValue].head;
		table[hashValue].head = insNode; // head points to new node
	}
	else // if filled
	{
		HashNode *current = table[hashValue].head; // point to head

		while (current->next != NULL)
		{
			if (id == current->customerID) // check for duplicates
			{
				delete current->data; // delete date
				current->data = NULL;
				delete current; // delete node
				current = NULL;
				return false;
			}
			current = current->next; // traverse to end
		}

		current->next = insNode; // point to new node
	}

	return true;
}

// ------------------------------------ getCustomer -------------------------------------
// Description: Return customer if found in the table
// Otherwise, return null
// Check for invalid ID if > 9999 or < 0
// ----------------------------------------------------------------------------------------------
Customer* HashTable::getCustomer(int id)
{
	if (id > 9999 || id < 0) // check for invalid ID
	{
		return NULL;
	}

	int hashValue = (id % HASH_NUMBER); // determine bucket in table

	if (table[hashValue].head == NULL) // if empty
	{
		return NULL;
	}
	else // if filled
	{
		HashNode* current = table[hashValue].head; // point to head

		while (current != NULL)
		{
			if (id == current->customerID) // if found
			{
				return current->data; // return customer info
			}
			current = current->next; // traverse the elements
		}
	}

	return NULL; // if not found
}