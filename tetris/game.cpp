#include "game.h"

//���� �ʱ⼳��
void init(void)
{
	//�ܼ� �� ũ��
	system("mode con cols=60 lines=35 | title TETRIS");
	//Ŀ�� �����
	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = false;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursor);
}

//�޴���� �� �̵�
int Menu(void)
{
	int x = 26;		//Ŀ�� ������
	int y = 16;

	Cursor(25, 10);
	cout << "��TETRIS��";

	Cursor(x - 2, y);
	cout << "> ���ӽ��� ";
	Cursor(x + 1, y + 2);
	cout << "���ھ�";
	Cursor(x, y + 4);
	cout << "��������";
	Cursor(x, y + 6);
	cout << "��������";

	while (true)
	{
		int sel = KeyControl(); //����Ű �Է�����

		switch (sel)
		{
		case UP:
			if (y > 16) {
				Cursor(x - 2, y);
				cout << " ";
				y -= 2;		//������ �̵�
				Cursor(x - 2, y);//Ŀ���̵�
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 22) {
				Cursor(x - 2, y);
				cout << " ";
				y += 2;		//������ �̵�
				Cursor(x - 2, y);//Ŀ���̵�
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

//���� ����
void GameStart() {
	system("cls");
	GameTable::PrintBox();
	Block *block = new Block(0, 5);

	
	while (1) {
		int key = KeyControl();
		if (key == ESC)
			break;
		else {
			switch (key)
			{
			case UP:
				block->RotationBlock();
				break;
			case DOWN:
				block->ShiftBlock(0, 1);
				break;
			case LEFT:
				block->ShiftBlock(-2, 0);
				break;
			case RIGHT:
				block->ShiftBlock(2, 0);
				break;
			default:
				break;
			}
		}
	}
}

//���� ���
void ScoreInfo()
{
	system("cls"); //ȭ�� �ʱ�ȭ

	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}

//��������
void GameInfo()
{
	system("cls"); //ȭ�� �ʱ�ȭ
	while (true)
	{

		Cursor(25, 10);
		cout << "��TETRIS��";

		Cursor(12, 16);
		cout << "��, �� ����Ű : �¿� ���̵�";
		Cursor(12, 17);
		cout << "�� ����Ű : �Ʒ��� ���̵�";
		Cursor(12, 18);
		cout << "�� ����Ű : �� ������ ���̵�";
		Cursor(12, 19);
		cout << "SPACE : �� ȸ�� (�ݽð� ����)";
		Cursor(12, 20);
		cout << "ESC : ���� �� Pause";
		Cursor(12, 22);
		cout << "������ : lovepys01@naver.com";

		if (KeyControl() == ESC)
			return;
	}
}
