#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//'1'-'0'=1(前面是字符，后面是数字)
int getminecount(char mine[ROWS][COLS],int x,int y)
{
	//mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1]
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j] - '0';
		}
	}
	return sum;
}

void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows;i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easycount;
	while(count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<ROW*COL-easycount)
	{
		printf("请输入要排查的坐标>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//坐标合法
		{
			if (mine[x][y] == '1')//1.踩雷
			{
				printf("很遗憾，你被炸死了\n");
				displayboard(mine, row, col);
				break;
			}
			else//2.不是雷
			{
				//计算xy坐标周围的雷
				int count=getminecount(mine,x,y);
				show[x][y] = count + '0';
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if (win == ROW * COL - easycount)
	{
		printf("恭喜你，排雷成功\n");
		displayboard(mine, ROW, COL);
	}
}

