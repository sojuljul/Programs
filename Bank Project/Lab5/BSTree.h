#pragma once
#include "Account.h"
#include <iostream>
using namespace std;

class BSTree
{
public:
	BSTree();
	~BSTree();

	bool Insert(Account *);

	// retrieve object, first parameter is the ID of the account
	// second parameter holds pointer to found object, NULL if not found
	bool Retrieve(const int &acctId, Account * &target) const;

	// displays the contents of a tree to cout
	void Display() const;
	void Empty();
	bool isEmpty() const;

private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};
	Node *root;

	bool InsertHelper(Node *&pNode, Account *acct);
	bool RetrieveHelper(const int &acctId, Account * &target, Node *pNode) const;
	void DisplayHelper(Node *pNode) const;
};

