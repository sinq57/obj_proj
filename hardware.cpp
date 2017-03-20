#include "stdafx.h"

using namespace std;


int Keyboard::getInt()
{
	int k = _getch();
	return k;
}

int Keyboard::getChar()
{
	char k = _getch();
	return k;
}

void Keyboard::dataIn(string &a)
{
	cin >> a;
}

void Keyboard::dataIn(double &a)
{
	cin >> a;
}

Screen::Screen()
{

}

void Screen::dataOut(string a)
{
	cout << a;
}

void Screen::dataOut(double a)
{
	cout << a;
}


void Screen::dataOut(int a)
{
	cout << a;
}

void Screen::dataOut(char a)
{
	cout << a;
}

void Screen::display(string a, string b)
{
	system("color 67");
	dataOut( "\n");
	decorate();
	dataOut( " |                             WELCOME TO WBK BANK                            | ");
	decorate();
	dataOut( " ");
	for (int i=1; i<=16; i++) dataOut( "-");
	dataOut( "  ");
	for (int i=1; i<=42; i++) dataOut( "-");
	dataOut( "  ");
	for (int i=1; i<=16; i++) dataOut( "-");
	dataOut( "\n | RUT TIEN - 1 | |");
	for (int i=1; i<=42; i++) dataOut( " ");
	dataOut( "| | 2-CHUYEN TIEN|\n");
	printDash();
	dataOut( " ");
	printDash();
	dataOut( "\n |THANH TOAN- 3 | |");
	dataOut( a );
	dataOut( "| | 4-MUA THE NAP|\n");
	printDash();
	dataOut( " ");
	printDash();
	dataOut( "\n |XEM SO DU - 5 | |");
	dataOut( b );
	dataOut( "| | 6-DOI MA PIN |\n");
	printDash();
	dataOut( " ");
	printDash();
	dataOut( "\n |IN SAO KE - 7 | |");
	for (int i=1; i<=42; i++) dataOut( " ");
	dataOut( "| | 0 - THOAT !  |");
	dataOut( "  ");
	for (int i=1; i<=16; i++) dataOut( "-");
	dataOut( "  ");
	for (int i=1; i<=42; i++) dataOut( "-");
	dataOut( "  ");
	for (int i=1; i<=16; i++) dataOut( "-");
	dataOut( " ");
	dataOut( "\n");
	dataOut( " -------------------------------  -------------  ------------------------------\n");
	dataOut( " |                             |  | 1 | 2 | 3 |  |         WBK BANK           |\n");
	dataOut( " |                             |  -------------  |                            |\n");
	dataOut( " |      |---------------|      |  | 4 | 5 | 6 |  |            WE              |\n");
	dataOut( " |      |  INSERT CARD  |      |  -------------  |                            |\n");
	dataOut( " |      |  -----------  |      |  | 7 | 8 | 9 |  |        WILL HOLD           |\n");
	dataOut( " |      |     HELLO     |      |  -------------  |                            |\n");
	dataOut( " |      |---------------|      |  | Y | 0 | N |  |        YOUR TRUST          |\n");
	dataOut( " |                             |  -------------  |                            |\n");
	dataOut( " -------------------------------  -------------  ------------------------------\n");
	decorate();
	dataOut( " |                            THANK FOR TRANSACTIONS                          | ");
	decorate();
	for (int i=1; i<=40; i++) dataOut( " ");
}

void Screen::decorate()
{
	dataOut(" ");
	for(int i = 1; i = 78; i++)
		dataOut("-");
	dataOut(" ");
}

void Screen::makeBackgroundColor()
{
	system("color 17");
}

void Screen::printDash()
{
	dataOut(" ");
	for (int i = 1; i <= 16; i++)
		dataOut("-");
	dataOut(" |");
	for (int i = 1; i <= 42; i++)
		dataOut(" ");
	dataOut("| ");
	for (int i = 1; i <= 16; i++)
		dataOut("-");
	dataOut(" ");
}

void Screen::clearScreen()
{
	system("cls");
}

void Screen::goToXY(int x, int y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x,y };
	SetConsoleCursorPosition(hStdout, position);
}

void Screen::printInsideFrame(string a, int line)
{
	goToXY(19, line);
	dataOut(a);
}


void Screen::loading()  // time emulator for reading card and executing transaction 
{
	printInsideFrame("            ", 12);
	Sleep(300);
	for (int i = 1; i <= 10; i++) {
		dataOut(". ");
		Sleep(200);
	}

}

MoneyBox::MoneyBox()
{

}

void MoneyBox::makeMoneyArray()
{
	ifstream f_money("MoneyInBank.txt");
	int count = 0, denomination, number;
	if (f_money.is_open())
	{
		while (!f_money.eof())
		{
			++count;
			f_money >> denomination >> number;
			moneyArray[count].setDenomination(denomination);
			moneyArray[count].setNumber(number);
			
		}
		DenominationNumber = count;
		f_money.close();
	}
}

long MoneyBox::moneyTotal()
{
	long sum = 0;
	for (int i = 0; i <= DenominationNumber; i++)
		sum += moneyArray[i].getDenomination()*moneyArray[i].getNumber();
	return sum;
}

void MoneyBox::updateMoney()
{
	ofstream f_money("MoneyInBank.txt");
	for (int i = 1; i <= DenominationNumber; i++)
		f_money << moneyArray[i].getDenomination() << " " << moneyArray[i].getNumber() << endl;
	f_money.close();
}


CardReader::CardReader()
{

}

void CardReader::display(string a)
{
	Screen screen;
	for (int i = 1; i <= 5; i++) {
		screen.goToXY(8, 23);
		screen.dataOut(a);
		Sleep(300);
		screen.goToXY(8, 23);
		screen.dataOut("|               |");
	}
}