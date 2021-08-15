#include "main.h"
using namespace std;

int main(void)
{
	init();		//초기설정

	while (true)
	{
		system("cls");		//화면 초기화
		int sel = Menu();	//메뉴 호출, 선택

		if (sel == 6)	//게임종료
			return 0;

		switch (sel)
		{
		case 0:			//게임시작
			GameStart();
			break;
		case 2:			//스코어
			ScoreInfo();
			break;
		case 4:			//게임정보
			GameInfo();
			break;
		default:
			break;
		}
	}
}
