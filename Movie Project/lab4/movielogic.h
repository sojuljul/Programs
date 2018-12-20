// ------------------------------------------------ movielogic.h -------------------------------------------------------
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

#pragma once
#ifndef MOVIELOGIC_H
#define MOVIELOGIC_H
#include <string>
#include <iostream>
#include <fstream>

#include "movie.h"
#include "bintree.h"
#include "moviefactory.h"

class MovieLogic
{
public:
	void buildMovieInventory(ifstream&);
	Movie* getMovie(Movie* newMovie, char movType);
	void displayInventory();

private:
	void addError(string);
	void displayMovieError() const;

	string errorMovie;
	BinTree comedyBST; // BSTree for comedy
	BinTree dramaBST; // BSTree for drama
	BinTree classicBST; // BSTree for classic
};

#endif
