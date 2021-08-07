#pragma once

#include "main.h"
#define CREATE_X 20;
#define CREATE_Y 4;

class Block {
protected:
    int x; // 블럭의 x좌표
    int y; // 블럭의 y좌표
    int rotation; //회전 수
    int name; //이름
    int shape[4/*색칠된 모양의 좌표*/][2/*x, y 좌표*/];
public:
    Block(int, int);
    const static int SHAPE[7][4][4][2]; //블록 모양 , 회전 수, 
    int GetX();
    int GetY();
    int GetRotation();
    void PrintBlock();
    void RotationBlock();
    void ShiftBlock(int x, int y);
    void DeleteBlock();
    void FixBlock();
};

