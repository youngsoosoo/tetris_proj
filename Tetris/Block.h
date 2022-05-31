#pragma once
#include "main.h"

//�� ���� ��ġ
#define CREATE_X 20
#define CREATE_Y 5

//��Ʈ���� ��
class Block
{
private:
	int _name;			//�� �̸�
	int _x;				//x��ǥ
	int _y;				//y��ǥ
	int _shape[4][2];	//�� ��� ��ǥ
	int _rotate;		//�� ȸ�� ��

public:
	const static int SHAPE[7][4][4][2];

public:
	Block(int, int);
	void operator=(const Block&);
	int GetBlock_x(void);
	int GetBlock_y(void);
	void PrintBlock() const;
	void PrintNextBlock() const;
	void DeleteBlock() const;
	void ShiftBlock(int, int);
	void DownBottom();
	void RotateBlock();
	bool FixBlock();		//fix -> true , down -> false
};
