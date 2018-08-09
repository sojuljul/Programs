// ------------------------------------------------ drama.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Movie class
// It will inherit the protected data members from Movie
// It will override methods display, displayForCustomer, isEqual, isLess
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "drama.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Drama::Drama()
{
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Drama::~Drama()
{
}

// ------------------------------------ Constructor(string) -------------------------------------
// Description: Takes in a string, reads each string in that line, and stores them
// to its respetive data members
// ----------------------------------------------------------------------------------------------
Drama::Drama(const string& info)
{
	stringstream readLine; // takes in a line
	readLine << info; // contains line
	string temp = ""; // temp string

	getline(readLine, temp, ','); // read movie type
	movieType = temp[0]; // put into char

	getline(readLine, temp, ','); // read stock
	stringstream(temp) >> stock; // convert string to int

	getline(readLine, director, ','); // read director
	getline(readLine, movieTitle, ','); // read title

	getline(readLine, temp, ','); // read year
	stringstream(temp) >> yearRelease; // convert string to int
}

// ------------------------------------ Constructor(string, string) -------------------------------------
// Description: Takes in a title and director, then sets them
// ----------------------------------------------------------------------------------------------
Drama::Drama(string& newTitle, string& newDirector)
{
	movieTitle = newTitle;
	director = newDirector;
}

// ------------------------------------ isEqual -------------------------------------
// Description: Checks if a drama movie is equal to another drama
// Checks for director and title
// ----------------------------------------------------------------------------------------------
bool Drama::isEqual(const Movie* other) const
{
	const Drama* dramaItem = (const Drama*)other;

	if ((director == dramaItem->director) && (movieTitle == dramaItem->movieTitle))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ isLess -------------------------------------
// Description: Checks if a drama movie is less than another drama
// Checks for director first, then title
// ----------------------------------------------------------------------------------------------
bool Drama::isLess(const Movie* other) const
{
	const Drama* dramaItem = (const Drama*)other;

	if (director < dramaItem->director) // check director
	{
		return true;
	}
	else if ((director == dramaItem->director) 
		&& (movieTitle < dramaItem->movieTitle)) // director equal, check title
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ display -------------------------------------
// Description: Outputs the info of a drama movie
// ----------------------------------------------------------------------------------------------
string Drama::display() const
{
	ostringstream line; // string to be outputted
	line << setw(10) << left << stock 
		<< setw(20) << left << director 
		<< setw(35) << left << movieTitle 
		<< setw(10) << yearRelease << endl;
	return line.str();
}

// ------------------------------------ display -------------------------------------
// Description: Outputs the info of a drama movie for a customer that borrow/return
// ----------------------------------------------------------------------------------------------
string Drama::displayForCustomer() const
{
	ostringstream line; // string to be outputted
	line << "Drama: " << director << " " << movieTitle << " " << yearRelease;
	return line.str();
}