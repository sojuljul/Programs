// ------------------------------------------------ movielogic.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class will build the movies from a text file.
// It will keep track of error inputs in a string
// It contains a BSTree for each movie type (Classic, Comedy, Drama)
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "movielogic.h"

// ------------------------------------ buildMovieInventory -------------------------------------
// Description: It will read in a text file of different types of movies 
// and add them to a vector in its respective slot (Comedy, Drama, Classics). 
// This will print an error message if a line contains a negative stock number and/or invalid movie type.
// ----------------------------------------------------------------------------------------------
void MovieLogic::buildMovieInventory(ifstream& inFileMovie)
{
	string tempLine = ""; // temp string

	for (;;)
	{
		getline(inFileMovie, tempLine); // get line

		if (inFileMovie.eof()) // if end of file
		{
			break;
		}

		Movie* newMovie = MovieFactory::createMovie(tempLine); // create movie object

		// insert the movie into its respective BSTree
		switch (tempLine[0]) // get the first char letter
		{
		case 'F': // comedy
			comedyBST.insert(newMovie);
			break;
		case 'D': // drama
			dramaBST.insert(newMovie);
			break;
		case 'C': // classic
			classicBST.insert(newMovie);
			break;
		default: // if invalid movie type
			addError("ERROR: Invalid Movie Type: " + tempLine);
			break;
		}
	}

	displayMovieError(); // display all invalid movie errors
}

// ------------------------------------ displayMovieError -------------------------------------
// Description: Outputs all the invalid movies from the text file
// ----------------------------------------------------------------------------------------------
void MovieLogic::displayMovieError() const
{
	cout << "---------- Invalid Movies ----------" << endl;
	cout << errorMovie << endl;
}

// ------------------------------------ addError -------------------------------------
// Description: Adds an error to a string containing all errors per line
// ----------------------------------------------------------------------------------------------
void MovieLogic::addError(string error)
{
	errorMovie += error + "\n";
}

// ------------------------------------ displayInventory -------------------------------------
// Description: Outputs all the movies for each movie type: Classic, Comedy, Drama
// It will call the BSTree display to output the movies in order
// ----------------------------------------------------------------------------------------------
void MovieLogic::displayInventory()
{
	// comedy movies
	cout << "--------------- Comedy ---------------" << endl;
	cout << "Stock" << setw(15) 
		<< "Director" << setw(20) 
		<< "Title" << setw(29) << "Year" << endl;
	comedyBST.display();

	// drama movies
	cout << "--------------- Drama ---------------" << endl;
	cout << "Stock" << setw(15) 
		<< "Director" << setw(20) 
		<< "Title" << setw(29) << "Year" << endl;
	dramaBST.display();

	// classic movies
	cout << "--------------- Classic ---------------" << endl;
	cout << "Stock" << setw(15) 
		<< "Director" << setw(20) 
		<< "Title" << setw(29) 
		<< "Major Actor" << setw(15) 
		<< "Month" << setw(5) << "Year" << endl;
	classicBST.display();
}

// ------------------------------------ getMovie -------------------------------------
// Description: Returns a movie object depending on the movie type
// It can be a Comedy, Drama, or Classic movie object
// ----------------------------------------------------------------------------------------------
Movie* MovieLogic::getMovie(Movie* newMovie, char movType)
{
	switch (movType)
	{
	case 'F': // comedy
		return comedyBST.retrieve(newMovie);
		break;
	case 'D': // drama
		return dramaBST.retrieve(newMovie);
		break;
	case 'C': //classic
		return classicBST.retrieve(newMovie);
		break;
	default: // if invalid movie type
		return NULL;
		break;
	}
}