#include "stdafx.h"
using namespace std;

//extern ofstream f_history;
//extern ofstream f_bill;

TransactionHistory::TransactionHistory()
{

}

void TransactionHistory::saveTransaction()
{
	time_t rawtime;
	time(&rawtime);
	char str[26];
	ctime_s(str, sizeof(str), &rawtime);
	cout << "Time " << str << ": ";
	cout << "Time " << str << ": ";
}