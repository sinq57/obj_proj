#include "stdafx.h"
using namespace std;

Money::Money()
{
	//number = 0;
	//denomination = 0;

}
void Money::setDenomination(int a)
{
	denomination = a;
}
void Money::setNumber(int a)
{
	number = a;
}

int Money::getDenomination()
{
	return denomination;
}

int Money::getNumber()
{
	return number;

}

MoneyBox::~MoneyBox()
{

}