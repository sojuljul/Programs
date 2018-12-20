// ------------------------------------------------ comedy.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Movie class.
// It will inherit the protected data members from Movie
// It will override methods display, displayForCustomer, isEqual, isLess
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "comedy.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Comedy::Comedy()
{
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Comedy::~Comedy()
{
}

// ------------------------------------ Constructor(string, int) -------------------------------------
// Description: Takes in a title and year and sets them
// ----------------------------------------------------------------------------------------------
Comedy::Comedy(string &newTitle, int &newYear)
{
	movieTitle = newTitle;
	yearRelease = newYear;
}

// ------------------------------------ Constructor(string) -------------------------------------
// Description: Takes in a string, reads each string in that line, and stores
// them to respective data members
// ----------------------------------------------------------------------------------------------
Comedy::Comedy(const string& info)
{
	stringstream readLine; // takes in a line
	readLine << info; // contains line
	string temp = ""; // temp string

	getline(readLine, temp, ','); // read movieType
	movieType = temp[0]; // put into char

	getline(readLine, temp, ','); // read stock
	stringstream(temp) >> stock; // convert string to int

	getline(readLine, director, ','); // read director
	getline(readLine, movieTitle, ','); // read title

	getline(readLine, temp, ','); // read year
	stringstream(temp) >> yearRelease; // convert string to int
}

// ------------------------------------ isEqual -------------------------------------
// Description: Checks if comedy movie is equal to another comedy
// Checks for title and year
// ----------------------------------------------------------------------------------------------
bool Comedy::isEqual(const Movie* other) const
{
	const Comedy* comedyItem = (const Comedy*)other;

	if ((movieTitle == comedyItem->movieTitle) && (yearRelease == comedyItem->yearRelease))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ isLess -------------------------------------
// Description: Checks if comedy movie is less than another comedy
// Checks title first, then by year
// ----------------------------------------------------------------------------------------------
bool Comedy::isLess(const Movie* other) const
{
	const Comedy* comedyItem = (const Comedy*)other;

	if (movieTitle < comedyItem->movieTitle) // check title
	{
		return true;
	}
	else if ((movieTitle == comedyItem->movieTitle) 
		&& (yearRelease < comedyItem->yearRelease)) // title equal, check year
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ display -------------------------------------
// Description: Outputs the info of a comedy movie
// ----------------------------------------------------------------------------------------------
string Comedy::display() const
{
	ostringstream line; // string to be outputted
	line << setw(10) << left << stock
		<< setw(20) << left << director 
		<< setw(35) << left << movieTitle 
		<< setw(10) << yearRelease << endl;
	return line.str();
}

// ------------------------------------ display -------------------------------------
// Description: Outputs the info of a comedy movie for a customer that borrow/return
// ----------------------------------------------------------------------------------------------
string Comedy::displayForCustomer() const
{
	ostringstream line; // string to be outputted
	line << "Comedy: " << movieTitle << " " << director << " " << yearRelease;
	return line.str();
}