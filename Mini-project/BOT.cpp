#include<iostream>
#include"Caro.h"
#include<Windows.h>
using namespace std;
void CaroChess::Mode() {
	CaroChess bot;
	while (true) {
		cout << "\nPlayer 1:" << endl;
		cout << "\nEnter position:" << endl;
		cout << "x = ";
		cin >> bot.x;
		cout << "y = ";
		cin >> bot.y;
		if (bot.x < 0 || bot.x > 9 || bot.y < 0 || bot.y > 9) {
			cout << "\nValue invalid, please re-enter " << endl;
			continue;
		}
		if (Check(bot.x, bot.y)) {
			cout << "\nThis position already exists, please choose another position" << endl;
			continue;
		}
		//Put into vector
		ListPoint.push_back(bot);
		// set possition of the player
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				if (bot.x + 3 == i && bot.y + 3 == j) {
					Matrix[i][j] = 1;
					break;
				}
			}
		}
		Turn = false;
		if (CheckWin() == 1) {
			system("cls"); // Clear consle
			break;
		}
		// set possition of the BOT
		for (int i = 3; i < 13; i++) {
			for (int j = 3; j < 13; j++) {
				if (Turn == false) {
					Matrix[CheckBOT(Level).x][CheckBOT(Level).y] = 2;
					Turn = true; // switch turn
					break;
				}
			}
			if (Turn == true) {
				break;
			}
		}
		system("cls"); // Clear consle
		break;
	}
}
void CaroChess::PlayBOT() {
	//TxtCorlor(11);
	while (CheckWin() == 0)
	{
		Print();
		Mode();
		if (CheckWin() == 1) {
			cout << "\nYou win" << endl;
			break;
		}
		if (CheckWin() == 2) {
			cout << "\nYou lose" << endl;
			break;
		}
		if (CheckEnd()) {
			cout << "\nDraw" << endl;
			break;
		}
	}
}
void CaroChess::BOT() {
	CaroChess* play = new CaroChess();
	system("cls");
	cout << "*-----PLAY WITH BOT-----*" << endl;
	cout << "1.Easy Mode" << endl;
	cout << "2.Normal Mode" << endl;
	cout << "3.Hard Mode" << endl;
	cout << "4.Back to menu" << endl;
	cout << "Press number to choice ";
	cin >> play->Level; // set level from keyboard
	switch (play->Level) {
	case 1: play->PlayBOT(); break; // Easy mode
	case 2: play->PlayBOT(); break; // Normal mode
	case 3: play->PlayHardBOT(); break; // Hard mode
	case 4: break;
	default: 
		break;
	}
	delete play;
}