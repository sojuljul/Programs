// ------------------------------------------------ borrow.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Transaction class
// It will override the doTransaction method to borrow a movie if available in stock
// It will inherit protected data members/methods from Transaction
// It will have method readTransaction to determine the movie type
// and borrowMovie to determine if successful transaction
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "borrow.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes the error string
// ----------------------------------------------------------------------------------------------
Borrow::Borrow()
{
	errorCustomer = "";
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Borrow::~Borrow()
{
}

// ------------------------------------ doTransaction -------------------------------------
// Description: Reads a line from the text file to find the customer
// Then determines which movie type to borrow the movie
// ----------------------------------------------------------------------------------------------
void Borrow::doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager)
{
	string temp = ""; // temp string
	int customerID = 0;
	Customer* newCustomer = NULL;

	stringstream readLine; // takes in a line from the text file
	readLine << line; // contains the line

	readLine >> customerID; // read the ID

	newCustomer = cusManager.getCustomer(customerID); // find customer

	if (checkCustomer(newCustomer, customerID)) // check if valid customer
	{
		getline(readLine, temp); // read remaining line
		readTransaction(temp, newCustomer, movManager); // borrow movie
	}
}

// ------------------------------------ readTransaction -------------------------------------
// Description: Determines which movie type to borrow the movie
// It can borrow from Classic, Comedy, or Drama
// Add errors to the list if invalid movie type or media type
// ----------------------------------------------------------------------------------------------
void Borrow::readTransaction(string info, Customer* newCustomer, MovieLogic& movManager)
{
	stringstream readLine; // takes in a line
	readLine << info; // contains remaining line after ID

	char movType = ' ';
	char mediaType = ' ';

	string majActor = "";
	string tempTitle = "";
	string tempYear = "";
	string tempDirector = "";
	string tempMonth = "";
	string tempName = "";

	int year = 0;
	int month = 0;
	Movie* customerMovie = NULL;
	Movie* tempMovie = NULL;

	readLine >> mediaType; // read the media type

	if (mediaType == 'D') // if its DVD
	{
		readLine >> movType; // read the movie type

		switch (movType)
		{
		case 'F': // comedy
			getline(readLine, tempTitle, ','); // read Title
			getline(readLine, tempYear); // read Year
			stringstream(tempYear) >> year; // convert string to int
			tempMovie = new Comedy(tempTitle, year); // create comedy object
			customerMovie = movManager.getMovie(tempMovie, movType); // find movie and assign
			borrowMovie(newCustomer, customerMovie, tempMovie); // borrow the movie with info
			delete tempMovie; // delete temp movie
			tempMovie = NULL;
			break;
		case 'D': // drama
			getline(readLine, tempDirector, ','); // read director
			getline(readLine, tempTitle, ','); // read title
			tempMovie = new Drama(tempTitle, tempDirector); // create drama object
			customerMovie = movManager.getMovie(tempMovie, movType); // find movie and assign
			borrowMovie(newCustomer, customerMovie, tempMovie); // borrow movie with info
			delete tempMovie; // delete temp movie
			tempMovie = NULL;
			break;
		case 'C': // classic
			getline(readLine, tempName, ' '); // read space
			getline(readLine, tempMonth, ' '); // read month
			stringstream(tempMonth) >> month; // convert string to int
			getline(readLine, tempYear, ' '); // read year
			stringstream(tempYear) >> year; // convert string to int
			readLine >> tempName; // read first name
			majActor += tempName + ' '; // add to major actor
			readLine >> tempName; // read last name
			majActor += tempName; // add to major actor
			tempMovie = new Classic(majActor, month, year); // create classic object
			customerMovie = movManager.getMovie(tempMovie, movType); // find movie and assign
			borrowMovie(newCustomer, customerMovie, tempMovie); // borrow movie with info
			delete tempMovie; // delete temp movie
			tempMovie = NULL;
			break;
		default: // if invalid movie type
			getline(readLine, tempName); // read line
			string errorType(1, movType); // convert char to string for movie type
			addError("ERROR: Invalid Movie Type: " + errorType + tempName); // add error to list
			break;
		}
	}
	else // if invalid media type
	{
		string errorType(1, mediaType); // convert char to string for media type
		getline(readLine, tempName); // read line
		addError("ERROR: Invalid Media Type: " + errorType + tempName); // add error to list
	}
}

// ------------------------------------ borrowMovie -------------------------------------
// Description: Borrow a movie from inventory and determine if success borrowed
// If not, add error to list
// ----------------------------------------------------------------------------------------------
void Borrow::borrowMovie(Customer* newCustomer, Movie* customerMovie, Movie* tempMovie)
{
	if (customerMovie != NULL) // if movie is not null
	{
		bool success = newCustomer->borrowMovie(customerMovie); // borrow movie from list
		if (!success) // if failed borrow
		{
			addError("ERROR: " + newCustomer->getInfo() + " borrow from empty stock: "
				+ customerMovie->displayForCustomer());
		}
	}
	else // if movie is null
	{
		addError("ERROR: Invalid Retrieve: " + tempMovie->displayForCustomer());
	}
}