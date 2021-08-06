#pragma once
#include "main.h"
#include "Block.h"

#define TABLE_WIDTH 12		//���̺� ����
#define TABLE_HEIGHT 20		//������ ����

class GameTable {
private:
	
public:
	static int BOX[TABLE_HEIGHT][TABLE_WIDTH];
   	static int x;	// ����
	static int y;	// ����
	static void PrintBox();	//������ ���
	static bool IsBlock(int, int); // ����� ���̺� �ȿ� �ִ��� ����
	static bool IsInTable(int);	// x��ǥ�� ���̺� �������� Ȯ��
};

