#pragma once
#include<vector>
using namespace std;
class CaroChess {
public:
	int x; // column
	int y; // row
	int Matrix[16][16] = { 0 }; // set Matrix[16][16]=0;
	bool Turn = true; // switch turn
	int Level; // level of BOT
	vector<CaroChess>ListPoint; // list contain x & y
	int CheckWin(); 
	void Print(); // Print  on the console
	bool CheckEnd(); 
	CaroChess CheckBOT(int level); // Check position 
	void PlayBOT();
	void Enter(); // Enter from the keyboard
	CaroChess();
	void TwoPlayer(); // Mode two player 
	bool Check(int m_x, int m_y); // Check for duplicates
	void BOT();// Mode play with BOT
	void Mode();// Choose difficulty level
	/*
	...........................
	         Hard BOT
	...........................
	*/
	int** Defender(); //BOT defender 
	int** Attacker(); // BOT attacker
	CaroChess Findbestvalue(int** list2, int** list3); 
	CaroChess findBestMove(); 
	bool CheckdoubleMove(CaroChess& move);
	void HardBOT();
	void PlayHardBOT();
};