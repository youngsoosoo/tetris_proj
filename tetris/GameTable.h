#pragma once
#include "main.h"
#include "Block.h"

#define TABLE_WIDTH 12		//테이블 가로
#define TABLE_HEIGHT 20		//테이플 세로
#define WALL 1
#define FIX 2
#define BLOCK 3
#define UNDER 4
#define BLANK 0


class GameTable {
private:
	
public:
	static int BOX[TABLE_HEIGHT][TABLE_WIDTH];
   	static int x;	// 가로
	static int y;	// 세로
	static void PrintBox();	//게임판 출력
	static bool IsBlock(int, int); // 블록이 테이블 안에 있는지 유무
	static bool IsInTable(int);	// x좌표가 테이블 범위인지 확인
	static void ResetTable();	// 테이블 리셋
	static bool FullBlock();	// 블록 라인이 꽉차있는지 확인
	static void DeleteBlockLine(); // 블럭 삭제
	//static bool IsInBottom(int);	//바닥에 닿았는지 확인
};

