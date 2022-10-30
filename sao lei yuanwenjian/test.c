#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("******************\n");
	printf("**1.play  0.exit**\n");
	printf("******************\n");
}
void game()
{
	//雷的信息存储
	//布置好的雷信息
	//排查出的雷信息
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化数组
	initboard(mine,ROWS,COLS,'0');
	initboard(show,ROWS,COLS,'*');
	//打印棋盘
	//displayboard(mine,ROW,COL);
	displayboard(show,ROW,COL);
	//布置雷
	setmine(mine,ROW,COL);
	//displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine,show,ROW,COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("退出游戏\n"); break;
		default:printf("数据错误，请重新输入\n"); break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}