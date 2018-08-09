#include "stdafx.h"
#include "Transaction.h"


Transaction::Transaction()
{
}

//deposit or withdraw transaction
Transaction::Transaction(char type, int id, int amount)
{
	this->transType = type;
	this->id = id;
	this->amount = amount;
	withdrawSuccess = true;
}

//transfer transaction
Transaction::Transaction(char type, int id, int amount, int transferId)
{
	this->transType = type;
	this->id = id;
	this->amount = amount;
	this->transferId = transferId;
	withdrawSuccess = true;
}

//history transaction
Transaction::Transaction(char type, int id)
{
	this->transType = type;
	this->id = id;
	withdrawSuccess = true;
}

//open account transaction
Transaction::Transaction(char type, string last, string first, int id)
{
	this->transType = type;
	this->lastName = last;
	this->firstName = first;
	this->id = id;
	withdrawSuccess = true;
}

Transaction::~Transaction()
{
}

string Transaction::getFirstName() const
{
	return firstName;
}

string Transaction::getLastName() const
{
	return lastName;
}

char Transaction::getTransType() const
{
	return transType;
}

int Transaction::getId() const
{
	return id;
}

int Transaction::getAmount() const
{
	return amount;
}

int Transaction::getTransferId() const
{
	return transferId;
}

bool Transaction::getWithdrawSuccess() const
{
	return withdrawSuccess;
}

void Transaction::setWithdrawSuccess(bool success)
{
	withdrawSuccess = success;
}

//overloads the operator << to display info depending on transaction
ostream& operator<<(ostream &outStream, const Transaction &source)
{
	if (source.getTransType() == 'O') //open acct
	{
		outStream << source.getTransType() << " " << source.getLastName() << " " << source.getFirstName() << " " << source.getId();
	}
	else if (source.getTransType() == 'D' || source.getTransType() == 'W') //deposit or withdraw
	{
		outStream << source.getTransType() << " " << source.getId() << " " << source.getAmount();
	}
	else if (source.getTransType() == 'T') //transfer
	{
		outStream << source.getTransType() << " " << source.getId() << " " << source.getAmount() << " " << source.getTransferId();
	}
	else if (source.getTransType() == 'H') //history
	{
		outStream << source.getTransType() << " " << source.getId();
	}

	if (source.getWithdrawSuccess() == false) //did not withdraw from an account
	{
		outStream << " (Failed)";
	}
	return outStream << endl;
}