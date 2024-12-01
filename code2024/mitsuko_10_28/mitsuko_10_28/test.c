#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include"game.h"

void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	diseplay(board, ROW, COL);
	int ret=0;
	int count=0;

	int row, col;
	do
	{
		printf("玩家下棋：\n");
		printf("请输入坐标：\n");
		scanf("%d %d", &row, &col);
		drop_player(board, row, col);
		diseplay(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret == ' ' || ret == '*' || ret == '#')
		{
			break;
		}

		random(&row, &col);
		printf("电脑下棋\n");
		drop_computer(board, row, col,count);
		count++;
		diseplay(board, ROW, COL);

		ret=win(board,ROW,COL);
		if (ret == ' '||ret=='*'||ret=='#')
		{
			break;
		}
	} while (1);

	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else if (ret == ' ')
	{
		printf("平局\n");
	}
}

int main()
{
	int n;
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("开始游戏\n");
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误！\n");
		}
	} while (n != 1 && n != 2);

	if (n == 2)//退出程序
	{
		return 0;
	}

	if (n == 1)
	{
		game();
	}
	return 0;
}