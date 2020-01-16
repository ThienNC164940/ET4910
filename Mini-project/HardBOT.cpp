#include<iostream>
#include"Caro.h"
using namespace std;
//Check two line make a certain win by checking all direction. If it's more than two computer need to stop it immediately
bool CaroChess::CheckdoubleMove(CaroChess& move) {
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			int count = 0;
			if (Matrix[i][j] == 0) {
				if (Matrix[i][j + 1] == 1 && Matrix[i][j + 2] == 1 && Matrix[i][j + 3] == 0) {
					count += 1;
				}
				if (Matrix[i][j - 1] == 1 && Matrix[i][j - 2] == 1 && Matrix[i][j - 3] == 0) {
					count += 1;
				}
				if (Matrix[i + 1][j] == 1 && Matrix[i + 2][j] == 1 && Matrix[i + 3][j] == 0) {
					count += 1;
				}
				if (Matrix[i - 1][j] == 1 && Matrix[i - 2][j] == 1 && Matrix[i - 3][j] == 0) {
					count += 1;
				}
				if (Matrix[i - 1][j + 1] == 1 && Matrix[i - 2][j + 2] == 1 && Matrix[i - 3][j + 3] == 0) {
					count += 1;
				}
				if (Matrix[i + 1][j + 1] == 1 && Matrix[i + 2][j + 2] == 1 && Matrix[i + 3][j + 3] == 0) {
					count += 1;
				}
				if (Matrix[i + 1][j - 1] == 1 && Matrix[i + 2][j - 2] == 1 && Matrix[i + 3][j - 3] == 0) {
					count += 1;
				}
				if (Matrix[i - 1][j - 1] == 1 && Matrix[i - 2][j - 2] == 1 && Matrix[i - 3][j - 3] == 0) {
					count += 1;
				}
				if (count >= 2) {
					move.x = i;
					move.y = j;
					return true;
				}
			}
		}
	}
	return false;
}
//Find a value corresponding to each point in board. the point has higher value, has more than chance to fill 
//It checks each empty point. If it is closer with many enemy point, it should be filled.
int** CaroChess::Defender() {
	int** list3 = new int* [16];
	for (int i = 0; i < 16; ++i)
	{
		list3[i] = new int[16];
	}

	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			list3[i][j] = 0;
		}
	}

	for (int i = 3; i < 13; ++i)
	{
		for (int j = 3; j < 13; ++j)
		{
			if (Matrix[i][j] == 0) {
				int column_left = j;
				int column_right = j;
				int row_up = i;
				int row_down = i;
				int count_right = 0;
				int count_left = 0;
				int count_up = 0;
				int count_down = 0;
				int count_northeast_up = 0;
				int count_southwest_down = 0;
				int count_northwest_up = 0;
				int count_southeast_down = 0;
				bool continue_search = true;

				while (column_left > 0 && continue_search) {
					if (Matrix[i][column_left - 1] == 1) {
						count_left += 1;
						column_left = column_left - 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while (column_right < 15 && continue_search) {
					if (Matrix[i][column_right + 1] == 1) {
						count_right += 1;
						column_right = column_right + 1;
					}
					else {
						continue_search = false;
					}
				}

				continue_search = true;

				while (row_up > 0 && continue_search) {
					if (Matrix[row_up - 1][j] == 1) {
						count_up += 1;
						row_up = row_up - 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while (row_down < 15 && continue_search) {
					if (Matrix[row_down + 1][j] == 1) {
						count_down += 1;
						row_down = row_down + 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				column_left = j;
				column_right = j;

				row_up = i;
				row_down = i;
				continue_search = true;

				while ((row_up > 0 && column_left > 0) && continue_search) {
					if (Matrix[row_up - 1][column_left - 1] == 1) {
						count_northwest_up += 1;
						row_up = row_up - 1;
						column_left = column_left - 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while ((row_down < 15 && column_right < 15) && continue_search) {
					if (Matrix[row_down + 1][column_right] == 1) {
						count_southeast_down += 1;
						row_down += 1;
						column_right += 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				column_left = j;
				column_right = j;
				row_up = i;
				row_down = i;

				while ((row_down < 15 && column_left > 0) && continue_search) {
					if (Matrix[row_down + 1][column_left - 1] == 1) {
						count_southwest_down += 1;
						row_down += 1;
						column_left -= 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while ((row_up > 0 && column_right < 15) && continue_search) {
					if (Matrix[row_up - 1][column_right + 1] == 1) {
						count_northeast_up += 1;
						row_up -= 1;
						column_right += 1;
					}
					else {
						continue_search = false;
					}
				}
				int total_count_horizontal = count_left + count_right + 1;
				int total_count_vertical = count_up + count_down + 1;
				int total_count_northwest_up = count_northwest_up + count_southeast_down + 1;
				int total_count_northeast_up = count_northeast_up + count_southwest_down + 1;
				int total_value = 0;
				int value = 0;

				for (auto item : { total_count_horizontal,total_count_vertical,total_count_northeast_up,total_count_northwest_up }) {
					if (item == 1) {
						value = 1;
					}
					if (item == 2) {
						value = 10;
					}
					if (item == 3) {
						value = 80;
					}
					if (item == 4) {
						value = 1500;
					}
					if (item == 5) {
						value = 8000;
					}
					total_value = total_value + value;
				}
				list3[i][j] = total_value;




			}
			else {
				list3[i][j] = -2;
			}
		}
	}

	return list3;

}
//Opposite of attacker
int** CaroChess::Attacker() {
	int** list3 = new int* [16];
	for (int i = 0; i < 16; ++i)
	{
		list3[i] = new int[16];
	}

	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			list3[i][j] = 0;
		}
	}

	for (int i = 3; i < 13; ++i)
	{
		for (int j = 3; j < 13; ++j)
		{
			if (Matrix[i][j] == 0) {
				int column_left = j;
				int column_right = j;
				int row_up = i;
				int row_down = i;
				int count_right = 0;
				int count_left = 0;
				int count_up = 0;
				int count_down = 0;
				int count_northeast_up = 0;
				int count_southwest_down = 0;
				int count_northwest_up = 0;
				int count_southeast_down = 0;
				bool continue_search = true;

				while (column_left > 0 && continue_search) {
					if (Matrix[i][column_left - 1] == 2) {
						count_left += 1;
						column_left = column_left - 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while (column_right < 15 && continue_search) {
					if (Matrix[i][column_right + 1] == 2) {
						count_right += 1;
						column_right = column_right + 1;
					}
					else {
						continue_search = false;
					}
				}

				continue_search = true;

				while (row_up > 0 && continue_search) {
					if (Matrix[row_up - 1][j] == 2) {
						count_up += 1;
						row_up = row_up - 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while (row_down < 15 && continue_search) {
					if (Matrix[row_down + 1][j] == 2) {
						count_down += 1;
						row_down = row_down + 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				column_left = j;
				column_right = j;

				row_up = i;
				row_down = i;
				continue_search = true;

				while ((row_up > 0 && column_left > 0) && continue_search) {
					if (Matrix[row_up - 1][column_left - 1] == 2) {
						count_northwest_up += 1;
						row_up = row_up - 1;
						column_left = column_left - 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while ((row_down < 15 && column_right < 15) && continue_search) {
					if (Matrix[row_down + 1][column_right] == 2) {
						count_southeast_down += 1;
						row_down += 1;
						column_right += 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				column_left = j;
				column_right = j;
				row_up = i;
				row_down = i;

				while ((row_down < 15 && column_left > 0) && continue_search) {
					if (Matrix[row_down + 1][column_left - 1] == 2) {
						count_southwest_down += 1;
						row_down += 1;
						column_left -= 1;
					}
					else {
						continue_search = false;
					}
				}
				continue_search = true;

				while ((row_up > 0 && column_right < 15) && continue_search) {
					if (Matrix[row_up - 1][column_right + 1] == 2) {
						count_northeast_up += 1;
						row_up -= 1;
						column_right += 1;
					}
					else {
						continue_search = false;
					}
				}
				int total_count_horizontal = count_left + count_right + 1;
				int total_count_vertical = count_up + count_down + 1;
				int total_count_northwest_up = count_northwest_up + count_southeast_down + 1;
				int total_count_northeast_up = count_northeast_up + count_southwest_down + 1;
				int total_value = 0;
				int value = 0;

				for (auto item : { total_count_horizontal,total_count_vertical,total_count_northeast_up,total_count_northwest_up }) {
					if (item == 1) {
						value = 2;
					}
					if (item == 2) {
						value = 20;
					}
					if (item == 3) {
						value = 550;
					}
					if (item == 4) {
						value = 2000;
					}
					if (item == 5) {
						value = 20000;
					}
					total_value = total_value + value;
				}
				list3[i][j] = total_value;




			}
			else {
				list3[i][j] = -2;
			}
		}
	}

	return list3;

}
//Sum of attacker value and defender value to make a highest chance point to fill
CaroChess CaroChess::Findbestvalue(int** list2, int** list3) {
	CaroChess move;
	move.x = 0;
	move.y = 0;
	int x = 0, y = 0;
	int tmp = list2[0][0] + list3[0][0];
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			int copy = (list3[i][j] + list2[i][j]);
			if (tmp < copy) {
				tmp = list3[i][j] + list2[i][j];
				move.x = i;
				move.y = j;
			}

		}
	}
	return move;
}
//Check doubleMove before attacker and defender. Because doubleMove has higher priority
CaroChess CaroChess::findBestMove() {
	CaroChess move;
	if (CheckdoubleMove(move)) {
		return move;
	}
	int** list2 = Attacker();
	int** list3 = Defender();
	move = Findbestvalue(list2, list3);
	return move;
}
// Input position and set position for BOT
void CaroChess::HardBOT() {
	CaroChess bot;
	while (true) {
		if (Turn == true) {
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
		}
		else {
			CaroChess move = findBestMove();
			Matrix[move.x][move.y] = 2;
			Turn = true;
			break;
		}
	}
}
// play with hard BOT
void CaroChess::PlayHardBOT() {
	CaroChess* play = new CaroChess();
	while (true)
	{
		play->Print();
		play->HardBOT();
		play->Print();
		int result = play->CheckWin();
		if (result == 1) {
			cout << "You win" << endl;
			break;
		}
		if (result == 2) {
			cout << "You lose" << endl;
			break;
		}

		if (play->CheckEnd()) {
			cout << "Draw" << endl;
			break;
		}
		system("cls");
	}
	delete play;
}