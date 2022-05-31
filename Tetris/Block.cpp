#include "Block.h"

//�� ���
const int Block::SHAPE[7][4][4][2] = {
	//I
	{ { {0, -1}, {0, 0}, {0, 1}, {0, 2} },
	{ {-2, 0}, {-1, 0}, {0, 0}, {1, 0} },
	{ {0, -1}, {0, 0}, {0, 1}, {0, 2} },
	{ {-2, 0}, {-1, 0}, {0, 0}, {1, 0} } },
	//L
	{ { {0, -1}, {0, 0}, {0, 1}, {1, 1} },
	{ {-1, 0}, {0, 0}, {1, 0}, {-1, 1} },
	{ {-1, -1}, {0, -1}, {0, 0}, {0, 1} },
	{ {1, -1}, {-1, 0}, {0, 0}, {1, 0} } },
	//RL
	{ { {0, -1}, {0, 0}, {-1, 1}, {0, 1} },
	{ {-1, -1}, {-1, 0}, {0, 0}, {1, 0} },
	{ {0, -1}, {1, -1}, {0, 0}, {0, 1} },
	{ {-1, 0}, {0, 0}, {1, 0}, {1, 1} } },
	//T
	{ { {0, -1}, {-1, 0}, {0, 0}, {0, 1} },
	{ {0, -1}, {-1, 0}, {0, 0}, {1, 0} },
	{ {0, -1}, {0, 0}, {1, 0}, {0, 1} },
	{ {-1, 0}, {0, 0}, {1, 0}, {0, 1} } },
	//O
	{ { {0, 0}, {1, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, },
	//S
	{ { {0, 0}, {1, 0}, {-1, 1}, {0, 1} },
	{ {-1, -1}, {-1, 0}, {0, 0}, {0, 1} },
	{ {0, 0}, {1, 0}, {-1, 1}, {0, 1} },
	{ {-1, -1}, {-1, 0}, {0, 0}, {0, 1} } },
	//RS
	{ { {-1, 0}, {0, 0}, {0, 1}, {1, 1} },
	{ {0, -1}, {-1, 0}, {0, 0}, {-1, 1} },
	{ {-1, 0}, {0, 0}, {0, 1}, {1, 1} },
	{ {0, -1}, {-1, 0}, {0, 0}, {-1, 1} } }
};

//_x getter
int Block::GetBlock_x(void)
{
	return _x;
}

//_y getter
int Block::GetBlock_y(void)
{
	return _y;
}

//Block Ŭ���� ������
Block::Block(int name, int rotate)//�� ����, ȸ�� ��
	:_name(name), _rotate(rotate)
{
	_x = CREATE_X;				//������ġ ����
	_y = CREATE_Y;
	for (int i = 0; i < 4; i++)	//��� ����
	{
		for (int j = 0; j < 2; j++)
		{
			_shape[i][j] = SHAPE[name][rotate][i][j];
		}
	}
}

void Block::operator=(const Block &ref)
{
	_name = ref._name;

	_x = CREATE_X;
	_y = CREATE_Y;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			_shape[i][j] = ref._shape[i][j];
	}

	_rotate = ref._rotate;
}

//�� ���
void Block::PrintBlock() const
{
	for (int i = 0; i < 4; i++)
	{
		Cursor(_x + (_shape[i][0] * 2), _y + _shape[i][1]);
		cout << "��";
	}
}

//���� �� ���
void Block::PrintNextBlock() const
{
	for (int i = 0; i < 4; i++)
	{
		Cursor(GameTable::X + 32 + (_shape[i][0] * 2), GameTable::Y + 3 + _shape[i][1]);
		cout << "��";
	}
}

//�� ����
void Block::DeleteBlock() const
{
	for (int i = 0; i < 4; i++)
	{
		Cursor(_x + (_shape[i][0] * 2), _y + _shape[i][1]);
		cout << "  ";
	}
}

//x, y ��ŭ �̵�
void Block::ShiftBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (GameTable::IsBlock(_x + (_shape[i][0] * 2) + x, _y + _shape[i][1] + y)	//�̵��� ��ġ�� ���� ������ ���
			|| !GameTable::IsInTable_X(_x + (_shape[i][0] * 2) + x))				//���̺� ���� ������ ������ ���
			return;
	}

	DeleteBlock();	//������ġ�� �� ����
	_x += x;		//��ǥ�̵�
	_y += y;
	PrintBlock();		//�̵��� ��ġ �� ���
}

//�� �ϰ�
void Block::DownBottom()
{
	while (!FixBlock())
	{
		ShiftBlock(0, 1);
	}
}

//�� ȸ��
void Block::RotateBlock()
{
	int temp_shape[4][2];		//ȸ�� �� ���

	for (int i = 0; i < 4; i++)	//��� �ӽ�ȸ��
	{
		for (int j = 0; j < 2; j++)
		{
			temp_shape[i][j] = SHAPE[_name][(_rotate + 1) % 4][i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (GameTable::IsBlock(_x + (temp_shape[i][0] * 2), _y + temp_shape[i][1])	//ȸ���� ��ġ�� ���� ������ ���
			||!GameTable::IsInTable_X(_x + (temp_shape[i][0] * 2)))					//ȸ���� ��ġ�� ���ι����� ������ ���
			return;
	}

	DeleteBlock();

	for (int i = 0; i < 4; i++)	//��� ȸ��
	{
		for (int j = 0; j < 2; j++)
		{
			_shape[i][j] = temp_shape[i][j];
		}
	}
	_rotate = (_rotate + 1) % 4;

	PrintBlock();
}

//�� �ױ�
bool Block::FixBlock()
{
	for (int i = 0; i < 4; i++)	//�ٴڿ� ��Ҵ��� Ȯ��
	{
		if (GameTable::IsBlock(_x + (_shape[i][0] * 2), _y + _shape[i][1] + 1))
		{
			for (int j = 0; j < 4; j++)	//�� ���� ����
			{
				GameTable::Box[_y + _shape[j][1] - GameTable::Y + 2][(_x + (_shape[j][0] * 2) - GameTable::X) / 2] = FIX;
			}
			return true;
		}
	}
	return false;
}
