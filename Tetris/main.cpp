#include "main.h"

int main(void)
{
	Init();		//�ʱ⼳��

	while (true) 
	{
		system("cls");		//ȭ�� �ʱ�ȭ
		int sel = Menu();	//�޴� ȣ��, ����

		if (sel == 6)	//��������
		{
			Cursor(10, 30);
			return 0;
		}

		switch (sel)
		{
		case 0:			//���ӽ���
			GameStart();
			break;
		case 2:			//�ְ�����
			BestScore();
			break;
		case 4:			//��������
			GameInfo();
			break;
		default:
			break;
		}
	}
}
