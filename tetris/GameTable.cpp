#include "GameTable.h"

int GameTable::x = 10;
int GameTable::y = 8;

GameTable::GameTable() {
	PrintBox();
}

void  GameTable::PrintBox() const {
	for (int i = 0; i < TABLE_HEIGHT; i++) {
		Cursor(x, y + i);
		for (int j = 0; j < TABLE_WIDTH; j++) {
			if (box[i][j] == 1) cout << "▦";
			else if (box[i][j] == 2) cout << "--";
			else cout << "  ";
		}
		cout << endl;
	}
}

void GameTable::PrintBlock() {
	srand((unsigned int)time(NULL));
	int num = rand() % 7 + 1;
	if      (num == 1) block1 = new Block1(); // 1번 블럭 생성
	else if (num == 2) block2 = new Block2(); // 2번 블럭 생성
	else if (num == 3) block3 = new Block3(); // 3번 블럭 생성
	else if (num == 4) block4 = new Block4(); // 4번 블럭 생성
	else if (num == 5) block5 = new Block5(); // 5번 블럭 생성
	else if (num == 6) block6 = new Block6(); // 6번 블럭 생성
	else if (num == 7) block7 = new Block7(); // 7번 블럭 생성



	
}