// ------------------------------------------------ bintree.cpp -------------------------------------------------------
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

#include "stdafx.h"
#include "bintree.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Root is set to null
// ----------------------------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}

// ------------------------------------ Destructor -------------------------------------
// Description: Calls makeEmpty to delete the BSTree
// ----------------------------------------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

// ------------------------------------ makeEmpty -------------------------------------
// Description: Calls a helper method to delete the BSTree
// ----------------------------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}

// ------------------------------------ makeEmptyHelper -------------------------------------
// Description: Deletes the BSTree by deleting the data and node
// Recursively goes to the left and right of the BStree
// ----------------------------------------------------------------------------------------------
void BinTree::makeEmptyHelper(Node* &current)
{
	if (current != NULL)
	{
		makeEmptyHelper(current->left); // left side of tree
		makeEmptyHelper(current->right); // right side of tree

		delete current->data;
		current->data = NULL;

		delete current;
		current = NULL;
	}
}

// ------------------------------------ isEmpty -------------------------------------
// Description: Returns true if BSTree is empty by checking if the root is null
// otherwise, returns false
// ----------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ------------------------------------ insert -------------------------------------
// Description: Inserts a movie into the BSTree
// Calls a helper method to insert the movie
// ----------------------------------------------------------------------------------------------
bool BinTree::insert(Movie* newMovie)
{
	return insertHelper(root, newMovie);
}

// ------------------------------------ insertHelper -------------------------------------
// Description: Inserts a movie into the BSTree
// CASES: empty or filled BSTree
// Insert depending on data of movie: equal, less than, or greater than
// ----------------------------------------------------------------------------------------------
bool BinTree::insertHelper(Node* &current, Movie* newMovie)
{
	if (current == NULL) // empty tree
	{
		current = new Node;
		current->data = newMovie;
		current->left = NULL; // left child is null
		current->right = NULL; // right child is null
		return true;
	}
	else // tree is filled with nodes
	{
		if (newMovie->isEqual(current->data)) // check for duplicates
		{
			delete newMovie; // delete movie
			newMovie = NULL;
			return false;
		}
		else if (newMovie->isLess(current->data)) // go to the left of tree
		{
			if (current->left == NULL)
			{
				Node *insNode = new Node;
				insNode->data = newMovie;
				insNode->left = NULL; // left child is null
				insNode->right = NULL; // right child is null
				current->left = insNode; // point to new node
				return true;
			}
			else
			{
				return insertHelper(current->left, newMovie); // traverse left of tree
			}
		}
		else // go to right of tree
		{
			if (current->right == NULL)
			{
				Node *insNode = new Node;
				insNode->data = newMovie;
				insNode->left = NULL; // left child is null
				insNode->right = NULL; // right child is null
				current->right = insNode; // point to new node
				return true;
			}
			else
			{
				return insertHelper(current->right, newMovie); // traverse right of tree
			}
		}

	}
}

// ------------------------------------ retrieve -------------------------------------
// Description: Retrieve a movie from the BSTree
// Calls a helper method to retrieve the movie
// ----------------------------------------------------------------------------------------------
Movie* BinTree::retrieve(const Movie* target)
{
	return retrieveHelper(root, target);
}

// ------------------------------------ retrieveHelper -------------------------------------
// Description: Returns a movie if found in the BSTree
// Otherwise, returns null
// CASES: equal, less than, greater than
// ----------------------------------------------------------------------------------------------
Movie* BinTree::retrieveHelper(Node* &current, const Movie* target) const
{
	if (current == NULL) // node not found
	{
		return NULL; // return null
	}

	if (target->isEqual(current->data)) // value found
	{
		return current->data; // return movie data
	}
	else if (target->isLess(current->data)) // if target less than movie
	{
		return retrieveHelper(current->left, target); // traverse left of tree
	}
	else // target greater than movie
	{
		return retrieveHelper(current->right, target); // traverse right of tree
	}
}

// ------------------------------------ display -------------------------------------
// Description: Calls a helper method to output the movies from the BSTree
// ----------------------------------------------------------------------------------------------
void BinTree::display()
{
	inorderHelper(root);
	cout << endl;
}

// ------------------------------------ inorderHelper -------------------------------------
// Description: Displays the movie data in order
// ----------------------------------------------------------------------------------------------
void BinTree::inorderHelper(Node* current) const
{
	if (current != NULL)
	{
		inorderHelper(current->left); // traverse left of tree
		cout << current->data->display(); // display movie data
		inorderHelper(current->right); // traverse right of tree
	}
}