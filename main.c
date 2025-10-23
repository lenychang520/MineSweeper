#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("***********1. 开始游戏  **********\n");	
	printf("***********0. 退出游戏  **********\n");
	printf("**********************************\n");
}

void game()
{
	srand((unsigned int)time(NULL));
	char Mine[ROWS][COLS] = { 0 };//雷场图
	char See[ROWS][COLS] = { 0 };//用户视图
	//初始化棋盘
	Init(Mine, ROWS, COLS, '0');
	Init(See, ROWS, COLS, '*');
	//布雷
	setmine(Mine, ROW, COL);
	//排雷
	printf("该条提示只显示一次。在后续排雷时，如果你想给某个坐标做标记，只需输入0 0，即可进入标记模式\n");
	while (1)
	{
		DisplayBoard(See, ROW, COL);
		printf("请输入要操作的区域的坐标\n");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x == 0 && y == 0)
		{
			sign(See, ROW, COL);
			continue;
		}
		find_mine(Mine, See, ROW, COL, x, y);//此处的n已经失去了它的意义
		extend(Mine, See, ROW, COL, x, y);
		int ret = Win(See, Mine);
		if (ret == 1)
		{
			printf("恭喜你排完了所有的雷！\n");
			break;
		}
		else if (Mine[x][y] == '1')
		{
			printf("很遗憾，你被炸死了\n");
			break;
		}
	}
}

int main()
{
	//开始界面
	int input = 0;
	do
	{
		printf("请输入对应的数字以开始游戏\n");
		menu();
		scanf("%d", &input);
		if (1 == input)
		{
			game();
		}
		else if (input != 0)
		{
			printf("请输入正确的数字以开始或退出游戏\n");
		}

	} while (input);
	return 0;
}