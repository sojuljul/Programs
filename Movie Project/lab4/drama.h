// ------------------------------------------------ drama.h -------------------------------------------------------
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

#pragma once
#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include <iostream>
using namespace std;

#include "movie.h"

class Drama: public Movie
{
public:
	Drama();
	virtual ~Drama();
	Drama(const string& info);
	Drama(string& newTitle, string& newDirector);

	virtual string display() const;
	virtual string displayForCustomer() const;

protected:
	virtual bool isEqual(const Movie* other) const;
	virtual bool isLess(const Movie* other) const;
};

#endif