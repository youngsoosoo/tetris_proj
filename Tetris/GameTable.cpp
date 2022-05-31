#include "GameTable.h"

int GameTable::X = 8;
int GameTable::Y = 6;

const int GameTable::CBOX[TABLE_HEIGHT + 2][TABLE_WIDTH] = {
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
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int GameTable::Box[TABLE_HEIGHT + 2][TABLE_WIDTH] = {
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
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int GameTable::NextBox[7][7] = {
	{1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1},
};

int GameTable::Score = 0;

int GameTable::Speed = 800;	//�ʱ� �� �ϰ� �ӵ�

void GameTable::ResetBox()
{
	for (int i = 0; i < TABLE_HEIGHT + 2; i++)		//���̺� �ʱ�ȭ
	{
		for (int j = 0; j < TABLE_WIDTH; j++)
		{
			Box[i][j] = CBOX[i][j];
		}
	}
	Score = 0;	//���� �ʱ�ȭ
	Speed = 800;	//�ӵ� �ʱ�ȭ
}

//��Ʈ���� �ڽ� ���
void GameTable::PrintBox()
{
	for (int i = 0; i < TABLE_HEIGHT + 2; i++)
	{
		Cursor(X, Y + i - 2);
		for (int j = 0; j < TABLE_WIDTH; j++)
		{
			if (Box[i][j] == LINE)
				cout << "��";
			else if (Box[i][j] == OVER)
				cout << "__";
			else if (Box[i][j] == EMPTY)
				cout << "  ";
			else if (Box[i][j] == FIX)
				cout << "��";
		}
	}
}

//���� ���� �����ִ� �ڽ� ���
void GameTable::PrintNextBox()
{
	Cursor(X + 26, Y - 1);
	cout << "NEXT..";
	for (int i = 0; i < 7; i++)
	{
		Cursor(X + 26, Y + i);
		for (int j = 0; j < 7; j++)
		{
			if (NextBox[i][j] == 1)
				cout << "��";
			else
				cout << "  ";
		}
	}
}

//x, y��ǥ�� ���� �ִ��� Ȯ��
bool GameTable::IsBlock(int x, int y)
{
	if (Box[y - Y + 2][(x - X)/2] == LINE || Box[y - Y + 2][(x - X)/2] == FIX)
		return true;
	return false;
}

//�ش� x��ǥ�� ���̺� �������� Ȯ��
bool GameTable::IsInTable_X(int x)
{
	if (X < x && x < X + (TABLE_WIDTH - 2) * 2 + 2)
		return true;
	return false;
}

//�ش� ������ �ϼ��ƴ��� Ȯ��
bool GameTable::CheckLine(int line)
{
	for (int i = 1; i < TABLE_WIDTH - 1; i++)
	{
		if (Box[line][i] != FIX)			//������ �ϼ����� ����, false��ȯ
			return false;
	}
	return true;
}

//�� �� �ϼ��� ���� ����
bool GameTable::DeleteLine()
{
	for (int i = TABLE_HEIGHT + 1; i > 2; i--)
	{
		if (CheckLine(i))	//�� �� �ϼ��ߴ��� Ȯ�� (�ؿ�������)
		{
			for (int j = 1; j < TABLE_WIDTH - 1; j++)//�� �����ϱ�
			{
				Box[i][j] = EMPTY;
			}

			PrintBox();		//�� ���� �����ֱ�
			Sleep(100);

			for (int j = i; j > 2; j--)	//�� ����, �ٴ� �ʱ�ȭ�ϱ�
			{
				for (int k = 1; k < TABLE_WIDTH - 1; k++)
				{
					if (j == 3)
						Box[j][k] = OVER;
					else if (j == 4)
						Box[j][k] = EMPTY;
					else
						Box[j][k] = Box[j - 1][k];
				}
			}
			Score += 1000;	//���� �� �⺻����
			return true;
		}
	}
	return false; 
}

//���ھ� ���
void GameTable::PrintScore()
{
	Cursor(X + 26, 20);
	cout << "Best Score : " << GetBest();
	Cursor(X + 26, 22);
	cout << "Your Score : " << Score;
}

//������ �Ѿ����� Ȯ��
bool GameTable::IsOver()
{
	for (int i = 1; i < TABLE_WIDTH - 1; i++)
	{
		if (Box[3][i] == FIX)
			return true;
	}
	return false;
}

//���� ������ ��������, �ְ���������, �ʱ�ȭ
void GameTable::GameOver()
{
	system("cls");
	int x = 15;
	int y = 11;
	if (GetBest() >= Score)
	{
		Cursor(x, y); cout << "�ɢɢ�   ..GAME OVER..  �ɢɢ�";
		Cursor(x + 10, y + 2); cout << Score << " ��";
		Cursor(x, y + 4); cout << "�ɢɢɢɢɢɢɢɢɢɢɢɢɢɢ�";
	}
	else	//�ְ��������� ������ ����
	{
		Cursor(x, y); cout << "�ɢɢ�  ��BEST SCORE��  �ɢɢ�";
		Cursor(x + 10, y + 2); cout << Score << " ��";
		Cursor(x, y + 4); cout << "�ɢɢɢɢɢɢɢɢɢɢɢɢɢɢ�";
		SetBest(Score);
	}

	Cursor(x + 2, 20);  cout << "�������� ESC�� ��������...";
	ResetBox();	//���� �ʱ�ȭ
	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}

//�� �ϰ��ӵ� ����
void GameTable::SetSpeed()
{
	if (Score > 100000)
		Speed = 200;
	else if (Score > 50000)
		Speed = 400;
	else if (Score > 10000)
		Speed = 600;
	else
		Speed = 800;
}

int GameTable::GetBest()
{
	ifstream is("BestScore.txt");	//���� �о����
	static int best;

	if (is.is_open())
	{
		is >> best;
	}
	else
	{
		ofstream os("BestScore.txt");//������ ������ �����
		os << 0;
		best = 0;
		os.close();
	}

	is.close();
	return best;
}

void GameTable::SetBest(int score)
{
	ofstream os("BestScore.txt");
	os << score;
	os.close();
}
