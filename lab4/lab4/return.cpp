// ------------------------------------------------ return.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "return.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes the error string
// ----------------------------------------------------------------------------------------------
Return::Return()
{
	errorCustomer = "";
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Return::~Return()
{
}

// ------------------------------------ doTransaction -------------------------------------
// Description: Reads in a line from the text file to find the customer
// Then determines which movie type to return the movie
// ----------------------------------------------------------------------------------------------
void Return::doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager)
{
	string temp = ""; // temp string
	int customerID = 0;
	Customer* newCustomer = NULL;

	stringstream readLine; // takes in a line
	readLine << line; // contains line

	readLine >> customerID; // read ID
	newCustomer = cusManager.getCustomer(customerID); // find customer
	if (checkCustomer(newCustomer, customerID)) // if valid customer
	{
		getline(readLine, temp); // read remaining line
		readTransaction(temp, newCustomer, movManager); // return movie
	}
}

// ------------------------------------ readTransaction -------------------------------------
// Description: Determines which movie type to return the movie
// It can return Classic, Comedy, or Drama
// Add errors to list if invalid movie type or media type
// ----------------------------------------------------------------------------------------------
void Return::readTransaction(string info, Customer* newCustomer, MovieLogic& movManager)
{
	stringstream readLine; // takes in a line
	readLine << info; // contains line

	char movType = ' ';
	char mediaType = ' ';

	string tempYear = "";
	string tempTitle = "";
	string tempDirector = "";
	string tempMonth = "";
	string tempName = "";

	string majActor = "";
	int year = 0;
	int month = 0;
	Movie* tempMovie = NULL;
	Movie* customerMovie = NULL;

	readLine >> mediaType; // read media type

	if (mediaType == 'D') // if its DVD
	{
		readLine >> movType; // read movie type

		switch (movType)
		{
		case 'F': // comedy
			getline(readLine, tempTitle, ','); // read title
			getline(readLine, tempYear); // read year
			stringstream(tempYear) >> year; // convert string to int
			tempMovie = new Comedy(tempTitle, year); // create comedy object
			customerMovie = movManager.getMovie(tempMovie, movType); // find movie
			returnMovie(newCustomer, customerMovie, tempMovie); // return movie
			delete tempMovie; // delete temp movie
			tempMovie = NULL;
			break;
		case 'D': // drama
			getline(readLine, tempDirector, ','); // read director
			getline(readLine, tempTitle, ','); // read title
			tempMovie = new Drama(tempDirector, tempTitle); // create Drama object
			customerMovie = movManager.getMovie(tempMovie, movType); // find movie
			returnMovie(newCustomer, customerMovie, tempMovie); // return movie
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
			customerMovie = movManager.getMovie(tempMovie, movType); // find movie
			returnMovie(newCustomer, customerMovie, tempMovie); // return movie
			delete tempMovie; // delete temp movie
			tempMovie = NULL;
			break;
		default: // if invalid movie type
			getline(readLine, tempName); // read line
			string errorType(1, movType); // convert char to string for movie type
			addError("ERROR: Invalid movie type " + errorType + tempName); // add error to list
			break;
		}
	}
	else // if invalid media type
	{
		string errorType(1, mediaType); // convert char to string for media type
		getline(readLine, tempName); // read line
		addError("ERROR: Invalid media type: " + errorType + tempName); // add error to list
	}
}

// ------------------------------------ returnMovie -------------------------------------
// Description: Return the movie to inventory and determine if success returned
// If not, then add error to list
// ----------------------------------------------------------------------------------------------
void Return::returnMovie(Customer* newCustomer, Movie* customerMovie, Movie* tempMovie)
{
	if (customerMovie != NULL) // if movie is not null
	{
		bool success = newCustomer->returnMovie(customerMovie); // return movie from list
		if (!success) // if failed return
		{
			addError("ERROR: " + newCustomer->getInfo() + " did not borrow "
				+ customerMovie->displayForCustomer());
		}
	}
	else // if movie is null
	{
		addError("ERROR: Invalid retrieve " + tempMovie->displayForCustomer());
	}
}
