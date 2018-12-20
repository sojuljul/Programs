// ------------------------------------------------ customer.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "customer.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes first name, last name, ID, stock, root
// ----------------------------------------------------------------------------------------------
Customer::Customer()
{
	firstName = "";
	lastName = "";
	customerID = 0;
	oneStock = 1;
	root = NULL;
	rootList = NULL;
}

// ------------------------------------ Constructor(int, string, string) -------------------------------------
// Description: Takes in an ID, last name, first name, and sets them
// Initialize the stock and root
// ----------------------------------------------------------------------------------------------
Customer::Customer(int id, string lastName, string firstName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->customerID = id;
	this->oneStock = 1;
	root = NULL;
	rootList = NULL;
}

// ------------------------------------ Destructor -------------------------------------
// Description: Deletes all the nodes in the linked list for transaction history
// Deletes all the nodes stored in linked list for borrow/return
// ----------------------------------------------------------------------------------------------
Customer::~Customer()
{
	// transaction history
	TransactionList* current = rootList;
	while (current != NULL)
	{
		rootList = rootList->next; // move head to the next node
		current->data = NULL; // data is null
		delete current; // delete node
		current = rootList; // point to new head
	}

	// borrow/return list
	TransactionNode* currentNode = root;
	while (currentNode != NULL)
	{
		root = root->next; // move head to the next node
		currentNode->data = NULL; // data is null
		delete currentNode; // delete node
		currentNode = root; // point to new head
	}

	transHistory.clear(); // clear the vector
}

// ------------------------------------ getFirstName -------------------------------------
// Description: Returns the first name as a string
// ----------------------------------------------------------------------------------------------
string Customer::getFirstName()
{
	return firstName;
}

// ------------------------------------ getLastName -------------------------------------
// Description: Returns the last name as a string
// ----------------------------------------------------------------------------------------------
string Customer::getLastName()
{
	return lastName;
}

// ------------------------------------ getID -------------------------------------
// Description: Returns the customers ID as an int
// ----------------------------------------------------------------------------------------------
int Customer::getID()
{
	return customerID;
}

// ------------------------------------ operator== -------------------------------------
// Description: Returns true if customer IDs are the same
// Otherwise, returns false
// ----------------------------------------------------------------------------------------------
bool Customer::operator==(const Customer& other) const
{
	if (customerID == other.customerID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ operator!= -------------------------------------
// Description: Returns true if customer IDs are not the same
// Otherwise, returns false
// ----------------------------------------------------------------------------------------------
bool Customer::operator!=(const Customer& other) const
{
	return !(customerID == other.customerID);
}

// ------------------------------------ borrowMovie -------------------------------------
// Description: Returns true if a movie was borrowed
// subtracts stock from movie, and adds a transaction to the customers history
// Otherwise, returns false
// ----------------------------------------------------------------------------------------------
bool Customer::borrowMovie(Movie* newMovie)
{
	// if stock of movie is not 0
	// call helper method to add movie into list for borrow/return
	if (newMovie->getStock() != 0 
		&& borrowMovieHelper(newMovie) == true)
	{
		newMovie->subtractStock(); // subtract from stock
		return addTransaction('B', newMovie);
	}
	else
	{
		return false;
	}
}

// ------------------------------------ returnMovie -------------------------------------
// Description: Returns true if a movie was returned
// adds stock to movie, and adds a transaction to the customers history
// Otherwise, returns false
// ----------------------------------------------------------------------------------------------
bool Customer::returnMovie(Movie* newMovie)
{
	// call helper method to find if movie is found in list for borrow/return
	if (returnMovieHelper(newMovie) == true)
	{
		newMovie->addStock(oneStock); // add to stock
		return addTransaction('R', newMovie);
	}
	else
	{
		return false;
	}
}

// ------------------------------------ borrowMovieHelper -------------------------------------
// Description: Helper method to add movie to the end of list for borrow/return
// CASES: empty and filled list
// ----------------------------------------------------------------------------------------------
bool Customer::borrowMovieHelper(Movie* newMovie)
{
	TransactionNode* insNode = new TransactionNode; // new node
	insNode->data = newMovie; // store data
	insNode->next = NULL;

	if (root == NULL) // if empty
	{
		insNode->next = root; // next points to head
		root = insNode; // head points to new node
	}
	else // if filled
	{
		TransactionNode* current = root;
		while (current->next != NULL)
		{
			current = current->next; // traverse to end
		}
		current->next = insNode; // next points to new node
	}

	return true;
}

// ------------------------------------ returnMovieHelper -------------------------------------
// Description: Helper method to find movie in list for borrow/return and delete node
// CASES: empty and filled list
// ----------------------------------------------------------------------------------------------
bool Customer::returnMovieHelper(Movie* newMovie)
{
	if (root == NULL) // if empty
	{
		return false;
	}

	TransactionNode* current = root->next;
	TransactionNode* previous = root;

	if (previous->data->isEqual(newMovie)) // if movie found
	{
		previous->data = NULL; // data is null
		delete previous; // delete node
		root = current; // head to next head
		return true;
	}
	
	// traverse through list for borrow/return
	while (current != NULL)
	{
		if (current->data->isEqual(newMovie)) // if movie found
		{
			previous->next = current->next; // point to next of current
			current->data = NULL; // data is null
			delete current; // delete node
			return true;
		}

		previous = current; // point to current
		current = current->next; // point to next of current
	}

	return false;
}

// ------------------------------------ getInfo -------------------------------------
// Description: Outputs the customers info that includes ID, last name, first name
// ----------------------------------------------------------------------------------------------
string Customer::getInfo()
{
	ostringstream line;
	line << "Customer ID: " << customerID << " " << lastName << ", " << firstName;
	return line.str();
}

// ------------------------------------ addTransaction -------------------------------------
// Description: Adds a transaction to the end of the list for transaction history
// CASES: empty and filled list
// ----------------------------------------------------------------------------------------------
bool Customer::addTransaction(const char transType, Movie* newMovie)
{
	TransactionList* insNode = new TransactionList; // new node
	insNode->data = newMovie; // store data
	insNode->transType = transType; // store transaction type
	insNode->next = NULL;

	if (rootList == NULL) // if empty
	{
		rootList = insNode; // head points to new node
	}
	else // if filled
	{
		TransactionList* current = rootList; // temp for head

		while (current->next != NULL)
		{
			current = current->next; // traverse to end
		}
		current->next = insNode; // point to new node
	}

	return true;
}

// ------------------------------------ movieHistory -------------------------------------
// Description: Outputs the transaction history for a customer
// Displays the movie that was borrowed/returned
// Display movies from latest to earliest
// ----------------------------------------------------------------------------------------------
void Customer::movieHistory()
{
	cout << endl;
	cout << getInfo() << endl; // print customer info
	cout << "---------- History ----------- " << endl;

	TransactionList* current = rootList; // temp for head
	while (current != NULL)
	{
		if (current->transType == 'B') // if borrow
		{
			transHistory.push_back("Borrowed " + current->data->displayForCustomer()); // add to vector
		}
		else if (current->transType == 'R') // if return
		{
			transHistory.push_back("Returned " + current->data->displayForCustomer()); // add to vector
		}
		current = current->next; // traverse through list
	}

	// print the transactions from latest to earliest
	vector<string>::reverse_iterator reverseHistory; // iterates a vector in reverse order
	for (reverseHistory = transHistory.rbegin(); reverseHistory != transHistory.rend(); reverseHistory++)
	{
		cout << *reverseHistory << endl; // print the data at each element
	}
	cout << endl;
}