// ------------------------------------------------ movie.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a base class for the different types of movies. 
// It will have Comedy, Drama, and Classics for its sub-classes. 
// This contains the movie type, stock, director, title, and year for the movie. 
// This class will be used to store the movies in a HashTable class. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "movie.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Initializes the movieType, stock, director, movieTitle, and year
// ----------------------------------------------------------------------------------------------
Movie::Movie()
{
	movieType = ' ';
	stock = 0;
	director = "";
	movieTitle = "";
	yearRelease = 0;
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Movie::~Movie()
{
}

// ------------------------------------ getStock -------------------------------------
// Description: Returns the stock of a movie item as an int
// ----------------------------------------------------------------------------------------------
int Movie::getStock()
{
	return stock;
}

// ------------------------------------ getDirector -------------------------------------
// Description: Returns the director of a movie item as a string
// ----------------------------------------------------------------------------------------------
string Movie::getDirector()
{
	return director;
}

// ------------------------------------ getTitle -------------------------------------
// Description: Returns the movie title of a movie item as a string
// ----------------------------------------------------------------------------------------------
string Movie::getTitle()
{
	return movieTitle;
}

// ------------------------------------ getYearRelease -------------------------------------
// Description: Returns the year release of a movie item as an int
// ----------------------------------------------------------------------------------------------
int Movie::getYearRelease()
{
	return yearRelease;
}

// ------------------------------------ addStock -------------------------------------
// Description: Increases the stock of a movie given a value
// ----------------------------------------------------------------------------------------------
bool Movie::addStock(int stockValue)
{
	if (stockValue < 0) // if negative value
	{
		return false;
	}
	else // if positive value
	{
		stock += stockValue; // add to stock
		return true;
	}
}

// ------------------------------------ subtractStock -------------------------------------
// Description: Decreases the stock of a movie
// ----------------------------------------------------------------------------------------------
bool Movie::subtractStock()
{
	if (stock <= 0) // if negative stock
	{
		return false;
	}
	else // if positive stock
	{
		stock--; // subtract
		return true;
	}
}