#include "GameTable.h"

int GameTable::score = 0;
int GameTable::x = 4;
int GameTable::y = 4;

int GameTable::BOX[TABLE_HEIGHT][TABLE_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
            if (BOX[i][j] == WALL || BOX[i][j] == UNDER) cout << "▦";
            else if (BOX[i][j] == LINE) cout << "__";
            else if (BOX[i][j] == BLOCK) cout << "■";
			else cout << "  ";
		}
		cout << endl;
	}
    TableScore();
    NextBlockView();
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
            if (BOX[i][j] == BLOCK) {
                BOX[i][j] = 0;
            }
        }
    }
}

bool GameTable::FullBlock() {
    for (int j = 0; j < TABLE_HEIGHT; j++) {
        for (int i = 0; i < TABLE_WIDTH; i++) {
            int a = BOX[j/*높이*/][i/*길이*/];
        }
    }
    return false;
}


bool GameTable::DeleteBlockLine() {
    for (int Y = TABLE_HEIGHT - 1; Y > 0; Y--) {    // 블럭 한 줄이 전부 블럭인지
        bool Line = true;
        for (int X = 1; X < TABLE_WIDTH - 1; X++) {
            if (BOX[Y][X] != BLOCK)
            {
                Line = false;
                break;
            }
        }
        int full = Y;
        if (Line) {
            for (int i = full-1; i > 0; i--) {
                for (int j = 1; j < TABLE_WIDTH - 1; j++) {
                    if (BOX[i + 1][j] != UNDER && BOX[i][j] != LINE) {
                        BOX[i + 1][j] = BOX[i][j];
                    }
                }
            }
            score += 1000;
            TableScore();
            return true;
        }
    }
    return false;
}

bool GameTable::GameOver() {
    for (int j = 1; j < TABLE_WIDTH - 1; j++) {
        if (BOX[5][j] == BLOCK) {
            return true;
        }
    }
    return false;
}

void GameTable::TableScore() {
    Cursor(40, 20);
    cout << "SCORE :" << score;
}

void GameTable::NextBlockView() {
    Cursor(35, 10);
    cout << "NEWX BLCOK :";
    Cursor(35, 11);
    cout << "▩▩▩▩▩▩" << endl;
    Cursor(35, 12);
    cout << "▩        ▩" << endl;
    Cursor(35, 13);
    cout << "▩        ▩" << endl;
    Cursor(35, 14);
    cout << "▩        ▩" << endl;
    Cursor(35, 15);
    cout << "▩        ▩" << endl;
    Cursor(35, 16);
    cout << "▩        ▩" << endl;
    Cursor(35, 17);
    cout << "▩▩▩▩▩▩" << endl;
}


