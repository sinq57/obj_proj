//*************************************************************
//************ SET OF: keyboard, screen, cardreader and moneybox
//*************************************************************

#pragma once
//#include "stdafx.h"
#include "classMoney.h"


using namespace std;
class Money;

class Keyboard
{
public:
	Keyboard();
	void dataIn(string&);
	void dataIn(double&);
	int getInt();
	int getChar();
private:
};

class Screen
{
public:
	Screen();
	void dataOut(string);
	void dataOut(int);
	void dataOut(double);
	void dataOut(char);
	void display(string a, string b);
	void makeBackgroundColor();
	void printDash();
	void decorate();
	void clearScreen();
	void loading();
	void goToXY(int x, int y);
	void printInsideFrame(string, int);

private:
};

class MoneyBox
{
public:
	Money moneyArray[10];
	MoneyBox();
	void makeMoneyArray();
	void getDenominationNumber();
	long moneyTotal();
	void updateMoney();
	~MoneyBox();
private:
	int DenominationNumber;
};

class CardReader
{
public:
	CardReader();
	int getCardAccountNumber();
	void display(string a);
private:
};