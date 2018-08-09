#pragma once
#include <iostream>
#include <string>
#include "Fund.h"
using namespace std;

class Account
{
	static const int NUM_FUNDS = 10;

public:
	Account(string first, string last, int id);
	~Account();

	string getFirstName() const;
	string getLastName() const;
	int getId() const;
	string getFundName(int fundId) const;
	int getFundBalance(int fundId) const;
	bool getTransferSuccess() const;

	void History();
	void FundHistory(int fundId);
	
	void Deposit(int amount, int fundId);
	bool Withdraw(int amount, int fundId);

	void CompleteTransaction(Transaction trans, int fundId);
	
	bool operator==(const Account &one) const;
	bool operator<(const Account &one) const;

private:
	string firstName;
	string lastName;
	int id;
	Fund fundArray[NUM_FUNDS];
	bool transferSuccess;
};

