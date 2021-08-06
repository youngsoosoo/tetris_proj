#pragma once
#include "main.h"
#include "Block.h"

#define TABLE_WIDTH 12		//테이블 가로
#define TABLE_HEIGHT 20		//테이플 세로

class GameTable {
private:
	
public:
	static int BOX[TABLE_HEIGHT][TABLE_WIDTH];
   	static int x;	// 가로
	static int y;	// 세로
	static void PrintBox();	//게임판 출력
	static bool IsBlock(int, int); // 블록이 테이블 안에 있는지 유무
	static bool IsInTable(int);	// x좌표가 테이블 범위인지 확인
};

