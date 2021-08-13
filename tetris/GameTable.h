#pragma once
#include "main.h"
#include "Block.h"

#define TABLE_WIDTH 12		//���̺� ����
#define TABLE_HEIGHT 24		//������ ����
#define WALL 1
#define LINE 2
#define BLOCK 3
#define UNDER 4
#define BLANK 0


class GameTable {
private:
	
public:
	static int BOX[TABLE_HEIGHT][TABLE_WIDTH];
   	static int x;	// ����
	static int y;	// ����
	static int score;	//������ ����
	static void PrintBox();	//������ ���
	static bool IsBlock(int, int); // ����� ���̺� �ȿ� �ִ��� ����
	static bool IsInTable(int);	// x��ǥ�� ���̺� �������� Ȯ��
	static void ResetTable();	// ���̺� ����
	static bool FullBlock();	// ��� ������ �����ִ��� Ȯ��
	static bool DeleteBlockLine(); // �� ����
	static bool GameOver();		//���� ����
	static void TableScore();			// ���� ǥ��
	static void NextBlockView();		//���� �� ǥ��
	//static bool IsInBottom(int);	//�ٴڿ� ��Ҵ��� Ȯ��
};

