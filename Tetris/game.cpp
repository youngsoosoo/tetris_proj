#include "game.h"

//���� �ʱ⼳��
void Init(void)
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
	int y = 18;

	Cursor(x - 20, 9); cout << "�ɢɢ�  �ɢɢ�  �ɢɢ�  �ɢɢ�    �ɢɢ�   �ɢ�   ";
	Cursor(x - 20, 10); cout << "  ��    ��        ��    ��   ��     ��    ��     ";
	Cursor(x - 20, 11); cout << "  ��    �ɢɢ�    ��    �ɢɢ�      ��    �ɢɢ� ";
	Cursor(x - 20, 12); cout << "  ��    ��        ��    ��  ��      ��        �� ";
	Cursor(x - 20, 13); cout << "  ��    �ɢɢ�    ��    ��   ��   �ɢɢ�   �ɢ� ";

	Cursor(x - 2, y);
	cout << "> ���ӽ��� ";
	Cursor(x, y + 2);
	cout << "�ְ�����";
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
			if (y > 18) {
				Cursor(x - 2, y);
				cout << " ";
				y -= 2;		//������ �̵�
				Cursor(x - 2, y);//Ŀ���̵�
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 24) {
				Cursor(x - 2, y);
				cout << " ";
				y += 2;		//������ �̵�
				Cursor(x - 2, y);//Ŀ���̵�
				cout << ">";
			}
			break;
		case SPACE: case ENTER:
			return y - 18;
		default:
			break;
		}
	}
}

//���ӽ���
void GameStart()
{
	system("cls");
	srand((unsigned int)time(NULL));
	Block block(rand() % 7, rand() % 4);		//�ʱ� �� ����
	GameTable::PrintScore();
	while (true) 
	{
		if (GameTable::IsOver())	//���� ������
		{
			Sleep(100);
			GameTable::GameOver();	//���� ����
			break;
		}

		int combo = 0;
		while (GameTable::DeleteLine())			//��� �ϼ����� ����
		{
			GameTable::Score += 150 * combo;			//���� ���ӻ����� �߰����� �ִ� 900��
			combo++;
			GameTable::PrintScore();
		}
		GameTable::SetSpeed();	//������ ���� ���ϰ� �ӵ� �缳��

		GameTable::PrintBox();					//���� �׵θ� ���
		block.PrintBlock();						//�� ���

		Block nextBlock(rand() % 7, rand() % 4);//���� �� ���� ����
		GameTable::PrintNextBox();				//���� �� ���
		nextBlock.PrintNextBlock();

		clock_t oldTime = clock();				//�ð� ����
		while (true)
		{
			clock_t curTime = clock();
			if (_kbhit())			//Ű �Է��� ������
			{
				int input = KeyControl();

				if (input == ESC)	//ESC�Է½� �����Է�, ���̺� �ʱ�ȭ, ����
				{
					Sleep(100);
					GameTable::GameOver();
					return;
				}

				if (input == SPACE)	//�����̽� �� �Է½� �� �ϰ�
				{
					block.DownBottom();
					break;
				}

				switch (input)		//����Ű �Է½� ���̵�
				{
				case LEFT:
					block.ShiftBlock(-2, 0);
					break;
				case RIGHT:
					block.ShiftBlock(2, 0);
					break;
				case DOWN:
					block.ShiftBlock(0, 1);
					break;
				case UP:
					block.RotateBlock();
					break;
				case P:
					Cursor(12, 30);
					system("pause");
					Cursor(12, 30);
					cout << "                                    ";
					break;
				default:
					break;
				}
			}

			if (curTime - oldTime > GameTable::Speed)//�� ��������
			{
				if (block.FixBlock())	//���� �����Ǹ� �ݺ����� Ż���ϰ� �� �� ����
					break;
				oldTime = curTime;
				block.ShiftBlock(0, 1);
			}
		}
		block = nextBlock;				//���� ���� ���� ���� ��
	}
}

//���� ���
void BestScore()
{
	system("cls"); //ȭ�� �ʱ�ȭ
	int x = 15;
	int y = 11;
	Cursor(x, y); cout << "�ɢɢ�  ��BEST SCORE��  �ɢɢ�";
	Cursor(x + 10, y + 2); cout <<GameTable::GetBest() << " ��";
	Cursor(x, y + 4); cout << "�ɢɢɢɢɢɢɢɢɢɢɢɢɢɢ�";

	Cursor(x + 2, 20);  cout << "�������� ESC�� ��������.";
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
	int x = 12;
	int y = 14;
	Cursor(x + 14, y - 6); cout << "���� ����";

	Cursor(x, y); cout << "��, �� ����Ű : �¿� ���̵�";
	Cursor(x, y + 2); cout << "�� ����Ű : �Ʒ��� ���̵�";
	Cursor(x, y + 4); cout << "�� ����Ű : �� ȸ�� (�ݽð� ����)";
	Cursor(x, y + 6); cout << "SPACE : �� �ϰ�";
	Cursor(x, y + 8); cout << "ESC : ����, ������ / P : �Ͻ�����";

	Cursor(x, y + 12); cout << "������ : sunmoon4228@gmail.com";

	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}
