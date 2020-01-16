#include<iostream>
#include<Windows.h>
#include<vector>
#include"Caro.h"
using namespace std;
int main() {
	CaroChess PlayGame;
	int choice;
	while (true) {
		cout << "------------CARO GAME-----------" << endl;
		cout << "1.Play with BOT" << endl;
		cout << "2.Play with another player" << endl;
		cout << "3.Exit game " << endl;
		cout << "Press number to choice ";
		cin >> choice;
		switch (choice)
		{
		case 1: PlayGame.BOT(); break;
		case 2:PlayGame.TwoPlayer(); break;
		case 3: exit(0);
		default: cout << "\nNo choice";
			break;
		}
	}
}