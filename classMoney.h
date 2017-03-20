#pragma once

class Money
{
public:
	Money();
	void setDenomination(int);  //denomination : value of banknote
	int getNumber();
	void setNumber(int);
	int getDenomination();
private:
	int number;
	int denomination;
};