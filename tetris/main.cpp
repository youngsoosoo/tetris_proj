#include "main.h"

int main(void)
{
	init();		//�ʱ⼳��

	while (true)
	{
		system("cls");		//ȭ�� �ʱ�ȭ
		int sel = Menu();	//�޴� ȣ��, ����

		if (sel == 6)	//��������
			return 0;

		switch (sel)
		{
		case 0:			//���ӽ���
			GameStart();
			break;
		case 2:			//���ھ�
			ScoreInfo();
			break;
		case 4:			//��������
			GameInfo();
			break;
		default:
			break;
		}
	}
}
