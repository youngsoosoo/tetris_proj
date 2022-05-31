#pragma once
#include "main.h"

//BOX ����, ���� ũ��
#define TABLE_WIDTH 12		//BOX ����
#define TABLE_HEIGHT 20		//BOX ����

//BLOCK�� ����
#define EMPTY 0		//�� ����
#define LINE 1		//�ڽ� �׵θ�
#define OVER 2		//���ӿ��� ���
#define FIX 10		//���κ�

class GameTable
{
public:
	const static int CBOX[TABLE_HEIGHT + 2][TABLE_WIDTH];	//���� �ڽ� (����)
	static int Box[TABLE_HEIGHT + 2][TABLE_WIDTH];			//���� �ڽ�
	static int NextBox[7][7];
	static int X;		//x��ǥ
	static int Y;		//y��ǥ
	static int Score;	//����
	static int Speed;	//�� �ϰ��ӵ�
	//�̸�(���� ��Ͽ�)

public:
	static void ResetBox();
	static void PrintBox();		//��Ʈ���� �ڽ� ���
	static void PrintNextBox();	//���� ���� �����ִ� �ڽ� ���
	static bool IsBlock(int, int);
	static bool IsInTable_X(int);
	static bool CheckLine(int);	//�� �� �ϼ��ƴ��� Ȯ��
	static bool DeleteLine();	//�� �� ����
	static void PrintScore();
	static void SetSpeed();		//�� �ϰ��ӵ� ����
	static bool IsOver();		//������ �Ѿ����� Ȯ��
	static void GameOver();		//���� ����
	static int GetBest();		//�ְ����� �޾ƿ���
	static void SetBest(int);	//�ְ����� ���
};
