#include<iostream>
#include"Caro.h"
using namespace std;
// Check game is over
bool CaroChess::CheckEnd() {
	for (int i = 3; i < 13; i++) {
		for (int j = 3; j < 13; j++) {
			if (Matrix[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
// Check position
bool CaroChess::Check(int m_x, int m_y) {
	for (int i = 0; i < ListPoint.size(); i++) {
		if (m_x == ListPoint[i].x && m_y == ListPoint[i].y) {
			return true;
		}
	}
	if (Matrix[m_x+3][m_y+3] != 0) {
		return true;
	}
	return false;
}
// Check play result
int CaroChess::CheckWin() {
	for (int i = 3; i < 13; i++) {
		for (int j = 3; j < 13; j++) {
			//  Row from left to right
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i][j + 1]) && (Matrix[i][j] == Matrix[i][j + 2]) &&
				(Matrix[i][j] == Matrix[i][j + 3])) {
				return Matrix[i][j];
			}
			//  Row from right to left
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i][j - 1]) && (Matrix[i][j] == Matrix[i][j - 2]) &&
				(Matrix[i][j] == Matrix[i][j - 3])) {
				return Matrix[i][j];
			}
			//  Column from up to down
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i + 1][j]) && (Matrix[i][j] == Matrix[i + 2][j]) &&
				(Matrix[i][j] == Matrix[i + 3][j])) {
				return Matrix[i][j];
			}
			//  Column from down to up
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i - 1][j]) && (Matrix[i][j] == Matrix[i - 2][j]) &&
				(Matrix[i][j] == Matrix[i - 3][j])) {
				return Matrix[i][j];
			}
			//  Diagonal row upper the right
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i - 1][j + 1]) && (Matrix[i][j] == Matrix[i - 2][j + 2]) &&
				(Matrix[i][j] == Matrix[i - 3][j + 3])) {
				return Matrix[i][j];
			}
			//  Diagonal row upper the left
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i - 1][j - 1]) && (Matrix[i][j] == Matrix[i - 2][j - 2]) &&
				(Matrix[i][j] == Matrix[i - 3][j - 3])) {
				return Matrix[i][j];
			}
			//  Diagonal row lower the right
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i + 1][j + 1]) && (Matrix[i][j] == Matrix[i + 2][j + 2]) &&
				(Matrix[i][j] == Matrix[i + 3][j + 3])) {
				return Matrix[i][j];
			}
			//  Diagonal row lower the left
			if ((Matrix[i][j] != 0) && (Matrix[i][j] == Matrix[i + 1][j - 1]) && (Matrix[i][j] == Matrix[i + 2][j - 2]) &&
				(Matrix[i][j] == Matrix[i + 3][j - 3])) {
				return Matrix[i][j];
			}
		}
	}
	return 0;
}
// Position BOT chose
CaroChess CaroChess::CheckBOT(int level) {
	CaroChess position;
	if (level==1||level == 2) {
		// level normal and level hard 
		if ((ListPoint.size() <= 1)&&(level!=1)) {
			int pos = ListPoint.size();
			if (ListPoint[pos - 1].y < 9) {
				position.x = ListPoint[pos - 1].x+3;
				position.y = ListPoint[pos - 1].y + 4;
				return position;
			}
		}
		for (int i = 3; i < 13; i++) {
			for (int j = 3; j < 13; j++) {
				// Row from left to right
				if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i][j + 1]) && (j < 11) &&
					(Matrix[i][j + 2] == 0)) {
					position.x = i;
					position.y = j + 2;
					return position;
				}
				// Row from right to left
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i][j - 1]) && (j > 4) &&
					(Matrix[i][j - 2] == 0)) {
					position.x = i;
					position.y = j - 2;
					return position;
				}
				// Column from up to down
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i + 1][j]) && (i < 11) &&
					(Matrix[i + 2][j] == 0)) {
					position.x = i + 2;
					position.y = j;
					return position;
				}
				// Column from down to up
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i - 1][j]) && (i > 4) &&
					(Matrix[i - 2][j] == 0)) {
					position.x = i - 2;
					position.y = j;
					return position;
				}
				// Diagonal row upper the right
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i - 1][j + 1]) && (j > 4) &&
					(Matrix[i - 2][j + 2] == 0)) {
					position.x = i - 2;
					position.y = j + 2;
					return position;
				}
				// Diagonal row upper the left
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i - 1][j - 1]) && (i > 4) &&
					(Matrix[i - 2][j - 2] == 0)) {
					position.x = i - 2;
					position.y = j - 2;
					return position;
				}
				// Diagonal row lower the right
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i + 1][j + 1]) && (j < 11) &&
					(Matrix[i + 2][j + 2] == 0)) {
					position.x = i + 2;
					position.y = j + 2;
					return position;
				}
				// Diagonal row lower the left
				else if ((Matrix[i][j] == 1) && (Matrix[i][j] == Matrix[i + 1][j - 1]) && (i < 11) &&
					(Matrix[i + 2][j - 2] == 0)) {
					position.x = i + 2;
					position.y = j - 2;
					return position;
				}
			}
		}
		for (int i = 3; i < 13; i++) {
			for (int j = 3; j < 13; j++) {
				// the other cases
				if (!(Matrix[i][j] == 1 || Matrix[i][j] == 2)) {
					position.x = i;
					position.y = j;
					return position;
				}
			}
		}
	}
	return position;
}
