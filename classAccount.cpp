#include "stdafx.h"
using namespace std;

Account::Account()
{
	blockedAmount = 0;
	cardId = "";
	pin = 0;
	balance = 0;
}

void Account::setBlockedAmount(int a)
{
	blockedAmount = a;
}

int Account::getBlockedAmount()
{
	return blockedAmount;
}
void Account::setBalance(int a)
{
	balance = a;
}

int Account::getBalance()
{
	return balance;
}

void Account::setCardId(string a)
{
	cardId = a;
}

string Account::getCardId()
{
	return cardId;
}

void Account::setPin(int a)
{
	pin = a;
}

int Account::getPin()
{
	return pin;
}