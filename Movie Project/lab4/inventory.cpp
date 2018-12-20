// ------------------------------------------------ inventory.cpp -------------------------------------------------------
// Juliano Nguyen - CSS 343
// Creation Date: 03/03/2017
// Date of Last Modification: 03/14/2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is a sub-class of the Transaction class
// It will override the doTransaction method to display the inventory of all movies
// from Classic, Comedy, Drama
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Assume all data is correct. Handle input errors, such as invalid movie type,
// media type, customer ID, etc.
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "inventory.h"

// ------------------------------------ Default Constructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Inventory::Inventory()
{
}

// ------------------------------------ Destructor -------------------------------------
// Description: Do nothing
// ----------------------------------------------------------------------------------------------
Inventory::~Inventory()
{
}

// ------------------------------------ doTransaction -------------------------------------
// Description: Display the inventory of all movies for each movie type
// which include Classic, Comedy, and Drama
// ----------------------------------------------------------------------------------------------
void Inventory::doTransaction(string line, CustomerLogic& cusManager, MovieLogic& movManager)
{
	movManager.displayInventory();
}