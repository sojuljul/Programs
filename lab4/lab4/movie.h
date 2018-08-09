// ------------------------------------------------ movie.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/04/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a base class for the different types of movies. 
// It will have Comedy, Drama, and Classics for its sub-classes. 
// This contains the stock, director, title, and year released for the movie.
// It will have methods display, displayForCustomer, isEqual, isLess but not defined
// It will have methods to increase/decrease the stock of a movie
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Movie
{
public:
	Movie();
	virtual ~Movie();

	int getStock();
	string getDirector();
	string getTitle();
	int getYearRelease();
	bool addStock(int stockValue);
	bool subtractStock();

	virtual bool isEqual(const Movie* other) const = 0;
	virtual bool isLess(const Movie* other) const = 0;
	virtual string display() const = 0;
	virtual string displayForCustomer() const = 0;

protected:
	char movieType;
	int stock;
	string director;
	string movieTitle;
	int yearRelease;
};

#endif