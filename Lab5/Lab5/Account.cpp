#include "stdafx.h"
#include "Account.h"

Account::Account(string first, string last, int id)
{
	firstName = first;
	lastName = last;
	this->id = id;
	transferSuccess = false;
	string fundList[] = { "Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund",
		"Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index" };

	//each account will have 10 funds, each with 0 dollars
	for (int i = 0; i < 10; i++)
	{
		fundArray[i].setFundName(fundList[i]);
		fundArray[i].setBalance(0);
	}
}


Account::~Account()
{
}

string Account::getFirstName() const
{
	return firstName;
}

string Account::getLastName() const
{
	return lastName;
}

int Account::getId() const
{
	return id;
}

//get fund name given its id
string Account::getFundName(int fundId) const
{
	return fundArray[fundId].getFundName();
}

//get the balance of the fund given its id
int Account::getFundBalance(int fundId) const
{
	return fundArray[fundId].getBalance();
}

bool Account::getTransferSuccess() const
{
	return transferSuccess;
}

//print the transaction history of all funds
void Account::History()
{
	for (int i = 0; i < 10; i++)
	{
		fundArray[i].PrintHistory();
	}
}

//print the transaction history of a fund given its id
void Account::FundHistory(int fundId)
{
	fundArray[fundId].PrintHistory();
}

void Account::Deposit(int amount, int fundId)
{
	fundArray[fundId].AddToFund(amount);
}

bool Account::Withdraw(int amount, int fundId)
{
	if (fundArray[fundId].isEnough(amount))
	{
		fundArray[fundId].SubtractFromFund(amount);
		return true;
	}

	//if not enough to withdraw, check their respective funds 0,1 OR 2,3
	//0 and 1 funds are together, 2 and 3 funds are together
	if (fundId == 0)
	{
		//check to make sure both funds is greater than or equal to the amount we are withdrawing
		if ((fundArray[fundId].getBalance() + fundArray[1].getBalance()) >= amount)
		{
			int remainAmount = amount - fundArray[fundId].getBalance();
			fundArray[fundId].SubtractFromFund(amount - remainAmount);
			fundArray[1].SubtractFromFund(remainAmount);
			int acctId = id * 10;

			Transaction *firstWithdraw = new Transaction('W', acctId + fundId, amount - remainAmount);
			Transaction *secondWithdraw = new Transaction('W', acctId + 1, remainAmount);
			fundArray[fundId].AddTransaction(*firstWithdraw); //add transaction to history
			fundArray[1].AddTransaction(*secondWithdraw); //add second transaction to history
			transferSuccess = true;
			return true;
		}
	}
	else if (fundId == 1)
	{
		if ((fundArray[fundId].getBalance() + fundArray[0].getBalance()) >= amount)
		{
			int remainAmount = amount - fundArray[fundId].getBalance();
			fundArray[fundId].SubtractFromFund(amount - remainAmount);
			fundArray[0].SubtractFromFund(remainAmount);
			int acctId = id * 10;

			Transaction *firstWithdraw = new Transaction('W', acctId + fundId, amount - remainAmount);
			Transaction *secondWithdraw = new Transaction('W', acctId + 0, remainAmount);
			fundArray[fundId].AddTransaction(*firstWithdraw);
			fundArray[0].AddTransaction(*secondWithdraw);
			transferSuccess = true;
			return true;
		}
	}
	else if (fundId == 2)
	{
		if ((fundArray[fundId].getBalance() + fundArray[3].getBalance()) >= amount)
		{
			int remainAmount = amount - fundArray[fundId].getBalance();
			fundArray[fundId].SubtractFromFund(amount - remainAmount);
			fundArray[3].SubtractFromFund(remainAmount);
			int acctId = id * 10;

			Transaction *firstWithdraw = new Transaction('W', acctId + fundId, amount - remainAmount);
			Transaction *secondWithdraw = new Transaction('W', acctId + 3, remainAmount);
			fundArray[fundId].AddTransaction(*firstWithdraw);
			fundArray[3].AddTransaction(*secondWithdraw);
			transferSuccess = true;
			return true;

		}
	}
	else if (fundId == 3)
	{
		if ((fundArray[fundId].getBalance() + fundArray[2].getBalance()) >= amount)
		{
			int remainAmount = amount - fundArray[fundId].getBalance();
			fundArray[fundId].SubtractFromFund(amount - remainAmount);
			fundArray[2].SubtractFromFund(remainAmount);
			int acctId = id * 10;

			Transaction *firstWithdraw = new Transaction('W', acctId + fundId, amount - remainAmount);
			Transaction *secondWithdraw = new Transaction('W', acctId + 2, remainAmount);
			fundArray[fundId].AddTransaction(*firstWithdraw);
			fundArray[2].AddTransaction(*secondWithdraw);
			transferSuccess = true;
			return true;
		}
	}

	return false; //not enough money to withdraw
	
}

//Add transaction to the fund[i]
void Account::CompleteTransaction(Transaction trans, int fundId)
{
	fundArray[fundId].AddTransaction(trans);
}

//Checks if one acct is equal by their id
bool Account::operator==(const Account &one) const
{
	if (id == one.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Checks if one acct is less by their id
bool Account::operator<(const Account &one) const
{
	if (id < one.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}