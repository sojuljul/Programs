// ------------------------------------------------ bintree.h -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class represents the BSTree to store the movies
// It contains methods to insert, retrieve, isEmpty, makeEmpty, display
// It will contain helper methods since the functions are built recursively
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
using namespace std;

#include "movie.h"

class BinTree
{
public:
	BinTree();
	~BinTree();

	bool insert(Movie* newMovie);
	Movie* retrieve(const Movie* target);
	bool isEmpty() const;
	void makeEmpty();
	void display();

private:
	struct Node
	{
		Movie* data;
		Node* left;
		Node* right;
	};
	Node* root;

	// helper methods
	void inorderHelper(Node* current) const;
	void makeEmptyHelper(Node* &current);
	bool insertHelper(Node* &current, Movie* newMovie);
	Movie* retrieveHelper(Node* &current, const Movie* target) const;
};

#endif