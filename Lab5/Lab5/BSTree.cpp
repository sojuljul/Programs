#include "stdafx.h"
#include "BSTree.h"


BSTree::BSTree()
{
	root = NULL;
}


BSTree::~BSTree()
{
}

bool BSTree::InsertHelper(Node *&pNode, Account *acct)
{
	if (pNode == NULL) //empty
	{
		pNode = new Node;
		pNode->pAcct = acct;
		pNode->left = NULL;
		pNode->right = NULL;
		return true;
	}
	else //root is filled
	{
		if (acct->getId() < pNode->pAcct->getId()) //if id is less, go left of tree
		{
			if (pNode->left == NULL)
			{
				Node *insNode = new Node;
				insNode->pAcct = acct;
				insNode->left = NULL;
				insNode->right = NULL;
				pNode->left = insNode;
				return true;
			}
			else
			{
				return InsertHelper(pNode->left, acct);
			}
		}
		else if (acct->getId() > pNode->pAcct->getId()) //if id is greater, go right of tree
		{
			if (pNode->right == NULL)
			{
				Node *insNode = new Node;
				insNode->pAcct = acct;
				insNode->left = NULL;
				insNode->right = NULL;
				pNode->right = insNode;
				return true;
			}
			else
			{
				return InsertHelper(pNode->right, acct);
			}
		}
		else //check for duplicates
		{
			return false;
		}
	}
}

bool BSTree::Insert(Account *acct)
{
	return InsertHelper(root, acct);
}

bool BSTree::RetrieveHelper(const int &acctId, Account * &target, Node *pNode) const
{
	if (pNode == NULL) //empty OR traversed the entire tree
	{
		target = NULL;
		return false;
	}
	else if (acctId == pNode->pAcct->getId()) //if id was found in tree
	{
		target = pNode->pAcct;
		return true;
	}
	else if (acctId < pNode->pAcct->getId()) //if id is less, go to the left
	{
		return RetrieveHelper(acctId, target, pNode->left);
	}
	else //otherwise go to the right
	{
		return RetrieveHelper(acctId, target, pNode->right);
	}
}

bool BSTree::Retrieve(const int &acctId, Account * &target) const
{
	return RetrieveHelper(acctId, target, root);
}

void BSTree::DisplayHelper(Node *pNode) const
{
	if (pNode != NULL)
	{
		DisplayHelper(pNode->left); //start with the left side
		cout << pNode->pAcct->getFirstName() << " " << pNode->pAcct->getLastName() << " Account ID: " << pNode->pAcct->getId() << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << pNode->pAcct->getFundName(i) << ": $" << pNode->pAcct->getFundBalance(i) << endl;
		}

		cout << endl;
		DisplayHelper(pNode->right); //print the right side of the tree
	}
}

void BSTree::Display() const
{
	DisplayHelper(root);
}

//empty the tree
void BSTree::Empty()
{
	delete root->pAcct;
	delete root;
	root = NULL;
}

//checks if tree is empty
bool BSTree::isEmpty() const
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