#include "GameTable.h"

int GameTable::x = 10;
int GameTable::y = 8;

int GameTable::BOX[TABLE_HEIGHT][TABLE_WIDTH] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1}
};

void  GameTable::PrintBox() {
	for (int i = 0; i < TABLE_HEIGHT; i++) {
		Cursor(x, y + i);
		for (int j = 0; j < TABLE_WIDTH; j++) {
			if (BOX[i][j] == 1 || BOX[i][j] == 4) cout << "▦";
			else if (BOX[i][j] == 2) cout << "--";
			else cout << "  ";
		}
		cout << endl;
	}
}

bool GameTable::IsBlock(int _x, int _y /*블록의 위치*/) {   //해당 x, y 좌표에 블럭이 존재하는지 확인
    if (BOX[_y - y][(_x - x)/2] == WALL || BOX[_y - y][(_x - x)/2] == BLOCK || BOX[_y - y][(_x - x) / 2] == UNDER) {
        return true;
    }
    return false;
}

bool GameTable::IsInTable(int _x /*블록의 x좌표*/) {
    if (x < _x && _x < (x + (TABLE_WIDTH * 2) - 2)) {
        return true;
    }
    return false;
}

void GameTable::ResetTable() {
    for (int i = 0; i < TABLE_HEIGHT; i++) {
        for (int j = 0; j < TABLE_WIDTH; j++) {
            if (GameTable::BOX[i][j] == BLOCK) {
                GameTable::BOX[i][j] = 0;
            }
        }
    }
}

bool GameTable::FullBlock() {
    for (int j = 0; j < TABLE_HEIGHT; j++) {
        for (int i = 0; i < TABLE_WIDTH; i++) {
            int a = GameTable::BOX[j/*높이*/][i/*길이*/];
        }
    }
    return false;
}


void GameTable::DeleteBlockLine() {
    for (int j = 0; j < TABLE_HEIGHT; j++) {
        for (int i = 0; i < TABLE_WIDTH; i++) {
            if (BOX[j/*높이*/][i/*길이*/] == BLOCK) {
                BOX[j][i] = 0;
            }
        }
    }
}

