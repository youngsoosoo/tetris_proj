#pragma once

#include "main.h"
#define CREATE_X 20;
#define CREATE_Y 4;

class Block {
protected:
    int x; // ���� x��ǥ
    int y; // ���� y��ǥ
    int rotation; //ȸ�� ��
    int name; //�̸�
    int shape[4/*��ĥ�� ����� ��ǥ*/][2/*x, y ��ǥ*/];
public:
    Block(int, int);
    const static int SHAPE[7][4][4][2]; //��� ��� , ȸ�� ��, 
    int GetX();
    int GetY();
    int GetRotation();
    void PrintBlock();
    void RotationBlock();
    void ShiftBlock(int x, int y);
    void DeleteBlock();
    void FixBlock();
};

