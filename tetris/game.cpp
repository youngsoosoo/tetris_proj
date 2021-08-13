#include "game.h"

//게임 초기설정
void init(void)
{
	//콘솔 앱 크기
	system("mode con cols=60 lines=35 | title TETRIS");
	//커서 숨기기
	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = false;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursor);
}

//메뉴출력 밑 이동
int Menu(void)
{
	int x = 26;		//커서 기준점
	int y = 16;

	Cursor(25, 10);
	cout << "☆TETRIS☆";

	Cursor(x - 2, y);
	cout << "> 게임시작 ";
	Cursor(x + 1, y + 2);
	cout << "스코어";
	Cursor(x, y + 4);
	cout << "게임정보";
	Cursor(x, y + 6);
	cout << "게임종료";

	while (true)
	{
		int sel = KeyControl(); //방향키 입력정보

		switch (sel)
		{
		case UP:
			if (y > 16) {
				Cursor(x - 2, y);
				cout << " ";
				y -= 2;		//기준점 이동
				Cursor(x - 2, y);//커서이동
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 22) {
				Cursor(x - 2, y);
				cout << " ";
				y += 2;		//기준점 이동
				Cursor(x - 2, y);//커서이동
				cout << ">";
			}
			break;
		case SPACE: case ENTER:
			return y - 16;
		default:
			break;
		}
	}
}

//게임 시작
void GameStart() {
	system("cls");
	GameTable::PrintBox();
	srand((unsigned int)time(NULL));	//랜덤함수
	Block block(0, rand() % 7);				//블럭 객체 생성
	while (1) {
		if (GameTable::GameOver()) {
			GameTable::ResetTable();
			system("cls");
			Cursor(10, 15);
			cout << " ======================================= " << endl << endl;
			Cursor(10, 16);
			cout << " ===============GAME OVER=============== " << endl << endl;
			Cursor(10, 17);
			cout << " ======================================= " << endl << endl;
			Cursor(10, 18);
			cout << " 엔터키를 누르면 메뉴로 돌아갑니다." << endl;
			if (getchar()) {
				break;
			}
		}
		while (GameTable::DeleteBlockLine());
		GameTable::PrintBox();
		clock_t start = clock();			//시작시간		
		
		Block block1(0, rand() % 7);		//다음 블럭 객체 생성
		block1.NextBlock();
		

		while (1) {
			clock_t time = clock();
			if (_kbhit()) {
				int key = KeyControl();
				if (key == ESC) {
					GameTable::ResetTable();
					return;
				}
				switch (key)
				{
				case UP:
					block.RotationBlock();
					break;
				case DOWN:
					block.ShiftBlock(0, 1);
					break;
				case LEFT:
					block.ShiftBlock(-2, 0);
					break;
				case RIGHT:
					block.ShiftBlock(2, 0);
					break;
				case SPACE:
					for (int i = 0; i < 4; i++) {
						block.OneDown();
						system("cls");
					}
					break;
				default:
					break;
				}
			}
			if (time - start > 800) {
				if (block.FixBlock()) {
					block = block1;
					break;
				}
				start = time;
				block.ShiftBlock(0, 1);
			}
		}
	}
}

//점수 출력
void ScoreInfo()
{
	system("cls"); //화면 초기화

	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}

//게임정보
void GameInfo()
{
	system("cls"); //화면 초기화
	while (true)
	{

		Cursor(25, 10);
		cout << "☆TETRIS☆";

		Cursor(12, 16);
		cout << "←, → 방향키 : 좌우 블럭이동";
		Cursor(12, 17);
		cout << "↓ 방향키 : 아래로 블럭이동";
		Cursor(12, 18);
		cout << "↑ 방향키 : 맨 밑으로 블럭이동";
		Cursor(12, 19);
		cout << "SPACE : 블럭 회전 (반시계 방향)";
		Cursor(12, 20);
		cout << "ESC : 종료 및 Pause";
		Cursor(12, 22);
		cout << "제작자 : lovepys01@naver.com";

		if (KeyControl() == ESC)
			return;
	}
}
