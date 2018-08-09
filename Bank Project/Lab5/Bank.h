#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <fstream>
#include "Transaction.h"
#include "Account.h"
#include "BSTree.h"
#include "Fund.h"
using namespace std;

class Bank
{
public:
	Bank();
	~Bank();

	bool ReadTransactionsFromFile(string filename);
	void ExecuteAllTransactionInQ();
	void Display();

private:
	BSTree accountList;
	queue<Transaction> transactionList;
};

