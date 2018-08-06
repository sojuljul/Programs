#include "stdafx.h"
#include "Bank.h"


Bank::Bank()
{
}


Bank::~Bank()
{
}

bool Bank::ReadTransactionsFromFile(string filename)
{
	ifstream inFile;
	string readLine;
	inFile.open(filename);
	
	if (!inFile)
	{
		cerr << "ERROR: Cannot open file" << endl;
		return false;
	}

	while (getline(inFile, readLine))
	{
		istringstream parseLine(readLine);
		char transType;
		parseLine >> transType;

		if (transType == 'O') //open account
		{
			string lastName, firstName;
			int id;
			parseLine >> lastName >> firstName >> id;
			Transaction addToQueue(transType, lastName, firstName, id); //create a transaction
			transactionList.push(addToQueue); //push it into the queue
		}
		else if (transType == 'D' || transType == 'W') //deposit or withdraw
		{
			int id, amount;
			parseLine >> id >> amount;
			Transaction addToQueue(transType, id, amount);
			transactionList.push(addToQueue);
		}
		else if (transType == 'H') //history
		{
			int id;
			parseLine >> id;
			Transaction addToQueue(transType, id);
			transactionList.push(addToQueue);
		}
		else if (transType == 'T') //transfer
		{
			int id, amount, transferId;
			parseLine >> id >> amount >> transferId;
			Transaction addtoQueue(transType, id, amount, transferId);
			transactionList.push(addtoQueue);
		}
		else //transaction not found
		{
			cerr << "ERROR: Transaction not found" << endl;
		}

	}

	inFile.close();
	return true;
}

void Bank::ExecuteAllTransactionInQ()
{
	while (!transactionList.empty())
	{
		Transaction tempLine = transactionList.front(); //get the front of the queue

		if (tempLine.getTransType() == 'O') //open account
		{
			int acctId = tempLine.getId();
			string firstName = tempLine.getFirstName();
			string lastName = tempLine.getLastName();

			Account *acct = new Account(firstName, lastName, acctId);
			if (accountList.Insert(acct) == false) //inserts the acct AND checks for duplicates
			{
				cerr << "ERROR: Account " << acct->getId() << " is already open. Transaction refused." << endl;
			}
		}
		else if (tempLine.getTransType() == 'D') //deposit
		{
			//Deposit will have 5 digits, 4 digit account id, 1 digit fund id
			int acctId = tempLine.getId() / 10;
			int fundId = tempLine.getId() % 10; //remainder, which is the last digit
			int amount = tempLine.getAmount();

			//add amount to the fund id for that account
			Account *acct;
			accountList.Retrieve(acctId, acct); //retrieve the acct given its id
			acct->Deposit(amount, fundId);
			acct->CompleteTransaction(tempLine, fundId);
		}
		else if (tempLine.getTransType() == 'W') //withdraw
		{
			//Deposit will have 5 digits, 4 digit account id, 1 digit fund id
			int acctId = tempLine.getId() / 10;
			int fundId = tempLine.getId() % 10;
			int amount = tempLine.getAmount();

			Account *acct;
			accountList.Retrieve(acctId, acct);
			if (acct->Withdraw(amount, fundId))
			{
				tempLine.setWithdrawSuccess(true);
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << acct->getFirstName() << " " << 
					acct->getLastName() << " " << acct->getFundName(fundId) << endl;
				tempLine.setWithdrawSuccess(false);
			}

			//add transaction to the vector, do not display when withdrawing more from a fund
			if (acct->getTransferSuccess() == false)
			{
				acct->CompleteTransaction(tempLine, fundId);
			}
		}
		else if (tempLine.getTransType() == 'H') //history
		{
			//account id is either 5 digits or 4 digits
			if (tempLine.getId() >= 10000 && tempLine.getId() <= 99999) //5 digits
			{
				int acctId = tempLine.getId() / 10;
				int fundId = tempLine.getId() % 10;
				Account *acct;

				if (accountList.Retrieve(acctId, acct)) //retrieve acct given its id
				{
					cout << "Transaction History for " << acct->getFirstName() << " " << acct->getLastName() << " ";
					acct->FundHistory(fundId);
				}
				else
				{
					cerr << "ERROR: Account " << acct->getId() << " not found." << endl;
				}
			}
			else if (tempLine.getId() >= 1000 && tempLine.getId() <= 9999) //4 digits
			{
				Account *acct;
				
				if (accountList.Retrieve(tempLine.getId(), acct))
				{
					cout << "Transaction History for " << acct->getFirstName() << " " << acct->getLastName() << " by fund." << endl;
					acct->History();
				}
				else
				{
					cerr << "ERROR: Account " << acct->getId() << " not found." << endl;
				}
			}

		}
		else if (tempLine.getTransType() == 'T') //transfer
		{
			//account id 5 digits, and transfer id 5 digits
			int acctId = tempLine.getId() / 10;
			int fundId = tempLine.getId() % 10;
			int amount = tempLine.getAmount();
			int transferId = tempLine.getTransferId() / 10;
			int transferFundId = tempLine.getTransferId() % 10;

			Account *acct, *transferAcct;

			if (accountList.Retrieve(acctId, acct)) //retrieve acct given its id
			{
				if (accountList.Retrieve(transferId, transferAcct)) //retrive other acct given its id
				{
					if (acct->Withdraw(amount, fundId)) //withdraw from the fund
					{
						transferAcct->Deposit(amount, transferFundId); //deposit into the other's fund
						transferAcct->CompleteTransaction(tempLine, transferFundId); //add transaction for the other (deposit)
						acct->CompleteTransaction(tempLine, fundId); //add transaction for the acct (withdraw)
					}
					else
					{
						cerr << "ERROR: Not enough funds to transfer" << endl;
					}
				}
				else
				{
					cerr << "ERROR: Account " << transferId << " not found. Transferal refused." << endl;
				}
			}
			else
			{
				cerr << "ERROR: Account " << acctId << " not found. Transferal refused." << endl;
			}
		}

		transactionList.pop();
	}
}

void Bank::Display()
{
	cout << "\nProcessing Done. Final Balances" << endl;
	accountList.Display(); //prints out the accts in the tree AND their funds
}