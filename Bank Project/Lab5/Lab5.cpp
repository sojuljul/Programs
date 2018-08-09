// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bank.h"

int main()
{
	Bank jollyBank;

	jollyBank.ReadTransactionsFromFile("BankTransIn.txt");
	jollyBank.ExecuteAllTransactionInQ();
	jollyBank.Display();
    return 0;
}

