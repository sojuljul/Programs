#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class Fund
{
public:
	Fund();
	Fund(string name);
	~Fund();

	int getBalance() const;
	string getFundName() const;
	void setBalance(int amount);
	void setFundName(string name);

	bool AddToFund(int amount);
	bool SubtractFromFund(int amount);

	bool AddTransaction(Transaction record);

	bool isEnough(int amount) const;
	void PrintHistory() const;

private:
	string fundName;
	int balance;
	vector<Transaction> fundHistory;
};

