#include "util.h"

//Ŀ���̵�
void Cursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//����Ű �Է��� �ް� �Է¹��� Ű ��ȯ
int KeyControl(void)
{
	char key = _getch();
	if (key == 224)
	{
		switch (key)
		{
		case UP:	// �� ����Ű
			return UP;
			break;
		case LEFT:	// �� ����Ű
			return LEFT;
			break;
		case RIGHT:	// �� ����Ű
			return RIGHT;
			break;
		case DOWN:	// �� ����Ű
			return DOWN;
			break;
		default:
			break;
		}
	}
	else
	{
		return key;
	}
}
