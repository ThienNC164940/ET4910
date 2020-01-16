#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include"Caro.h"
using namespace std;
// Function set corlor
void TextCorlor(int n) {
	HANDLE corlor;
	corlor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(corlor, n);
}
// constructor
CaroChess::CaroChess() {
	x = 0;
	y = 0;
}
// Function enter from the keyboard
void CaroChess::Enter() {
	CaroChess Person;
	while (true)
	{
		if (Turn == true) {
			cout << "\nPlayer 1:" << endl;
		}
		else {
			cout << "\nPlayer 2:" << endl;
		}
		cout << "\nEnter position:" << endl;
		cout << "x = ";
		cin >> Person.x;
		cout << "y = ";
		cin >> Person.y;
		// check value invalid
		if (Person.x < 0 || Person.x > 9 || Person.y < 0 || Person.y > 9) {
			cout << "\nValue invalid, please re-enter" << endl;
			continue;
		}
		if (Check(Person.x, Person.y)) {
			cout << "\nThis position already exists, please choose another position" << endl;
			continue;
		}
		// set character X <=> 1 and O <=> 2
		// X equivalent player 1, and O equivalent player 2
		else {
			// set possition of the player 1 and player 2
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					// player 1
					if (Person.x+3 == i && Person.y+3 == j&&Turn==true) {
						Matrix[i][j] = 1;
						Turn = false;
						break;
					}
					// player 2
					if (Person.x+3 == i && Person.y+3 == j && Turn == false) {
						Matrix[i][j] = 2;
						Turn = true;
						break;
					}
				}
			}
			//Put into vector
			ListPoint.push_back(Person);
			system("cls"); // Clear consle
			break;
		}
	}
}
// Print chessboard
void CaroChess::Print() {
	TextCorlor(11);
	system("cls");
	cout << "      0   1   2   3   4   5   6   7   8   9  " << endl;
	cout << "    ----------------------------------------" << endl;
	for (int i = 3; i < 13; i++) {
		cout << i-3 <<"   ";
		for (int j = 3; j < 13; j++) {
			if (Matrix[i][j] == 1) {
				cout << "| ";
				TextCorlor(7);
				cout << "X ";
				TextCorlor(11);

			}
			else if (Matrix[i][j] == 2) {
				cout << "| ";
				TextCorlor(12);
				cout << "O ";
				TextCorlor(11);
			}
			else {
				cout << "|   ";
			}
		}
		cout << "|";
		cout << "\n";
		cout << "    ";
		for (int i = 3; i < 13; i++) {
			cout << "----";
		}
		cout << "\n";
	}
}
// Two player mode
void CaroChess::TwoPlayer() {
	CaroChess* play = new CaroChess();
	TextCorlor(11);
	while (play->CheckWin()==0)
	{
		play->Print();
		play->Enter();
		if (play->CheckWin() == 1) {
			cout << "\nPlayer 1 win" << endl;
			break;
		}
		if (play->CheckWin() == 2) {
			cout << "\nPlayer 2 win" << endl;
			break;
		}
		if (play->CheckEnd()) {
			cout << "\nDraw" << endl;
			break;
		}
	}
	delete play;
}