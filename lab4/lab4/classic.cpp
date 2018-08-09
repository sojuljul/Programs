// ------------------------------------------------ classic.cpp -------------------------------------------------------
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
#include "classic.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes the month and major actor to nothing
// ----------------------------------------------------------------------------------------------
Classic::Classic()
{
	monthRelease = 0;
	majorActor = "";
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Classic::~Classic()
{
}

// ------------------------------------ Constructor(string) -------------------------------------
// Description: Takes in a string, reads each string in that line, and stores them
// to its respective data members
// ----------------------------------------------------------------------------------------------
Classic::Classic(const string& info)
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

	readLine >> temp; // first name to temp
	majorActor += temp + ' '; // add to major actor
	readLine >> temp; // last name to temp
	majorActor += temp; // add to major actor

	readLine >> monthRelease; // read month
	readLine >> yearRelease; // read year
}

// ------------------------------------ Constructor(string, int, int) -------------------------------------
// Description: Takes in an actor name, month, year and sets them
// ----------------------------------------------------------------------------------------------
Classic::Classic(string& newActor, int& newMonth, int& newYear)
{
	majorActor = newActor;
	monthRelease = newMonth;
	yearRelease = newYear;
}

// ------------------------------------ getDayRelease -------------------------------------
// Description: Returns the day release of a movie item as an int
// ----------------------------------------------------------------------------------------------
int Classic::getMonthRelease()
{
	return monthRelease;
}

// ------------------------------------ getMajorActor -------------------------------------
// Description: Returns the major actor name of a movie item as an int
// ----------------------------------------------------------------------------------------------
string Classic::getMajorActor()
{
	return majorActor;
}

// ------------------------------------ isEqual -------------------------------------
// Description: Checks if a classic movie is equal to another classic
// Checks for month, year, and major actor
// ----------------------------------------------------------------------------------------------
bool Classic::isEqual(const Movie* other) const
{
	const Classic* classicItem = (const Classic*)other;

	if ((yearRelease == classicItem->yearRelease) && (monthRelease == classicItem->monthRelease)
		&& (majorActor == classicItem->majorActor))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ isLess -------------------------------------
// Description: Checks if a classic movie is less than another classic
// Checks for release date first, then major actor
// ----------------------------------------------------------------------------------------------
bool Classic::isLess(const Movie* other) const
{
	const Classic* classicItem = (const Classic*)other;

	if (yearRelease < classicItem->yearRelease) // check year
	{
		return true;
	}
	else if (yearRelease == classicItem->yearRelease 
		&& monthRelease < classicItem->monthRelease) // year equal, check month
	{
		return true;
	}
	else if (yearRelease == classicItem->yearRelease 
		&& monthRelease == classicItem->monthRelease
		&& majorActor < classicItem->majorActor) // year & month equal, check actor
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ display -------------------------------------
// Description: Outputs the info of a classic movie
// ----------------------------------------------------------------------------------------------
string Classic::display() const
{
	ostringstream line; // string to be outputted
	line << setw(10) << left << stock 
		<< setw(20) << left << director 
		<< setw(30) << left << movieTitle 
		<< setw(20) << left << majorActor
		<< setw(5) << left << monthRelease 
		<< setw(5) << yearRelease << endl;
	return line.str();
}

// ------------------------------------ displayForCustomer -------------------------------------
// Description: Outputs the info of a classic movie for a customer that borrow/return
// ----------------------------------------------------------------------------------------------
string Classic::displayForCustomer() const
{
	ostringstream line; // string to be outputted
	line << "Classic: " << monthRelease << " " << yearRelease << " " << majorActor << " "
		<< movieTitle << " " << director;
	return line.str();
}