// ------------------------------------------------ moviefactory.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This will have a method to create a movie object
// It will have Classic, Comedy, Drama classes for it to create
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "moviefactory.h"

// ------------------------------------ createMovie -------------------------------------
// Description: Returns a new movie object depending on the movie type
// It can create a Classic, Comedy, or Drama movie object
// ----------------------------------------------------------------------------------------------
Movie* MovieFactory::createMovie(const string& readLine)
{
	Movie* newMovie = NULL;

	switch (readLine[0])
	{
	case 'F': // comedy
		newMovie = (Movie*) new Comedy(readLine);
		break;
	case 'D': // drama
		newMovie = (Movie*) new Drama(readLine);
		break;
	case 'C': // classic
		newMovie = (Movie*) new Classic(readLine);
		break;
	default: // if not a valid movie type
		newMovie = NULL;
		break;
	}

	return newMovie;
}