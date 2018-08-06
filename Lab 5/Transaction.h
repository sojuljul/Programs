#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction
{
	friend ostream& operator<<(ostream &outStream, const Transaction &source);

public:
	Transaction();
	Transaction(char type, int id, int amount); //deposit, withdraw
	Transaction(char type, int id, int amount, int transferId); //transfer
	Transaction(char type, int id); //history
	Transaction(char type, string last, string first, int id); //open
	~Transaction();

	string getFirstName() const;
	string getLastName() const;
	char getTransType() const;
	int getId() const;
	int getAmount() const;
	int getTransferId() const;
	bool getWithdrawSuccess() const;
	void setWithdrawSuccess(bool success);

private:
	char transType;
	string firstName;
	string lastName;
	int id;
	int amount;
	int transferId;
	bool withdrawSuccess;
};

