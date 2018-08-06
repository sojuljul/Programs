#include "stdafx.h"
#include "Fund.h"


Fund::Fund()
{
	balance = 0;
}

Fund::Fund(string name)
{
	fundName = name;
	balance = 0;
}

Fund::~Fund()
{
}

int Fund::getBalance() const
{
	return balance;
}

string Fund::getFundName() const
{
	return fundName;
}

void Fund::setBalance(int amount)
{
	this->balance = amount;
}

void Fund::setFundName(string name)
{
	fundName = name;
}

//add a given amount to the balance
bool Fund::AddToFund(int amount)
{
	balance += amount;
	return true;
}

//subtract a given amount from the balance
bool Fund::SubtractFromFund(int amount)
{
	if (isEnough(amount)) //checks if there is enough money for to subtract the amount from balance
	{
		balance -= amount;
		return true;
	}
	
	return false;
}

//add a transaction to the history vector
bool Fund::AddTransaction(Transaction record)
{
	fundHistory.push_back(record);
	return true;
}

//checks if the current balance has enough money than a given amount that will be subtracted
bool Fund::isEnough(int amount) const
{
	if (balance >= amount)
	{
		return true;
	}

	return false;
}

//prints the history for each fund for an acct
void Fund::PrintHistory() const
{
	if (fundHistory.size() != 0)
	{
		cout << fundName << ": $" << balance << endl;
		
		for (int i = 0; i < fundHistory.size(); i++)
		{
			cout << fundHistory[i];
		}
	}
}