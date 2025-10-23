#include "game.h"

void Init(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	printf("---------------------ɨ����Ϸ--------------------\n");
	int i = 0;
	for (i = 0; i <= row; i++)//��ӡ����ʾ����
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ����ʾ����
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("---------------------ɨ����Ϸ--------------------\n");
}

void setmine(char Mine[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			count--;
		}
	}
}

void find_mine(char Mine[ROWS][COLS], char See[ROWS][COLS], int row, int col, int x, int y)
{
	int i = 0;
	int j = 0;
	int count_mine = 0;
	for (i = -1; i <= 1; i++)//���ҾŹ������׵�����
	{
		for (j = -1; j <= 1; j++)
		{
			if (Mine[x + i][y + j] == '1')
			{
				count_mine++;
			}
		}
	}
	if (See[x][y] != '*')
	{
		printf("����ѡ��������������\n");
		return;
	}
	else
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			See[x][y] = count_mine + '0';//+'0'ʹcount_mine�ַ���
		}
		else
		{
			printf("�������������Ч\n");
			return;
		}
	}
}

void extend(char Mine[ROWS][COLS], char See[ROWS][COLS], int row, int col, int x, int y)
{
	if (x < 1 || x > ROW || y < 1 || y > COL)
	{
		return;
	}
	else if (See[x][y] == ' ')
	{
		return;
	}
	int i = 0;
	int j = 0;
	int count_mine = 0;
	for (i = -1; i <= 1; i++)//�����Ӳ��ҾŹ������׵�����
	{
		for (j = -1; j <= 1; j++)
		{
			if (Mine[x + i][y + j] == '1')
			{
				count_mine++;
			}
		} 
	}
	if (count_mine == 0)
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				See[x][y] = ' ';
				extend(Mine, See, ROW, COL, x + i, y + j);
			}
		}
	}
	else
	{
		See[x][y] = count_mine + '0';
		return;
	}
}

int Win(char See[ROWS][COLS], char Mine[ROWS][COLS])
{
	int count = 0;//������*��ʣ������
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (See[i][j] == '*' || (Mine[i][j] == '1' && See[i][j] == 'M'))
			{
				count++;
			}
		}
	}
	if (count == COUNT)
	{
		return 1;
	}
	return 0;
}

void sign(char See[ROWS][COLS], int row, int col)
{
	printf("������Ҫ��ǵ�����,���볷�ر�ǣ��������Ӧ�����꼴�ɳ���\n");
	int x = 0, y = 0;
	scanf("%d%d", &x, &y);
	if (x < 1 || x > row || y < 1 || y > col)
	{
		printf("��������ȷ������\n");
		return;
	}
	if (See[x][y] == '*')
	{
		See[x][y] = 'M';
	}
	else if (See[x][y] == 'M')
	{
		See[x][y] = '*';
	}
	else
	{
		printf("��ֻ�ܱ��*��λ�û��߳������\n");
	}
}