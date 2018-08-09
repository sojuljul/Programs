// ------------------------------------------------ moviefactory.h -------------------------------------------------------
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

#pragma once
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <string>
#include <iostream>
using namespace std;

#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

class MovieFactory
{
public:

	static Movie* createMovie(const string& readLine);
};

#endif