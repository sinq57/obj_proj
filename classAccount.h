#pragma once
#include "stdafx.h"
using namespace std;


class Account
{
public:
	Account();
	void setBlockedAmount(int);
	int getBlockedAmount();

	void setCardId(string);
	string getCardId();

	void setPin(int);
	int getPin();

	void setBalance(int);
	int getBalance();
private:
	int blockedAmount;
	string cardId;
	int pin;
	int balance;
};