#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("***********1. ��ʼ��Ϸ  **********\n");	
	printf("***********0. �˳���Ϸ  **********\n");
	printf("**********************************\n");
}

void game()
{
	srand((unsigned int)time(NULL));
	char Mine[ROWS][COLS] = { 0 };//�׳�ͼ
	char See[ROWS][COLS] = { 0 };//�û���ͼ
	//��ʼ������
	Init(Mine, ROWS, COLS, '0');
	Init(See, ROWS, COLS, '*');
	//����
	setmine(Mine, ROW, COL);
	//����
	printf("������ʾֻ��ʾһ�Ρ��ں�������ʱ����������ĳ����������ǣ�ֻ������0 0�����ɽ�����ģʽ\n");
	while (1)
	{
		DisplayBoard(See, ROW, COL);
		printf("������Ҫ���������������\n");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x == 0 && y == 0)
		{
			sign(See, ROW, COL);
			continue;
		}
		find_mine(Mine, See, ROW, COL, x, y);//�˴���n�Ѿ�ʧȥ����������
		extend(Mine, See, ROW, COL, x, y);
		int ret = Win(See, Mine);
		if (ret == 1)
		{
			printf("��ϲ�����������е��ף�\n");
			break;
		}
		else if (Mine[x][y] == '1')
		{
			printf("���ź����㱻ը����\n");
			break;
		}
	}
}

int main()
{
	//��ʼ����
	int input = 0;
	do
	{
		printf("�������Ӧ�������Կ�ʼ��Ϸ\n");
		menu();
		scanf("%d", &input);
		if (1 == input)
		{
			game();
		}
		else if (input != 0)
		{
			printf("��������ȷ�������Կ�ʼ���˳���Ϸ\n");
		}

	} while (input);
	return 0;
}