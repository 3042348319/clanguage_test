
#include<stdio.h>
#include<stdbool.h>
#include"game.h"

void menu()
{
	printf("*************欢迎来到三子棋游戏**************\n");
		printf("1,start\n   2,exit\n");
}

void initboard(char board[ROW][COL], int row, int col)//棋盘初始化
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void diseplay(char board[ROW][COL],int row,int col)
{
	
	int i;
	int n;
	for (n = 0; n < ROW; n++)
	{
		for (i = 0; i < ROW; i++)
		{
			printf(" %c ", board[n][i]);
			if (i != ROW - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (n != ROW - 1)
		{
			for (i = 0; i < ROW; i++)
			{
				printf("---");
				if (i != ROW - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void drop_player(char board[ROW][COL], int row, int col)
{
	if (row <= ROW && row > 0 && col <= COL && col > 0)
	{
		if (board[row - 1][col - 1] == ' ')
		{
			board[row - 1][col - 1] = '*';
		}
		else
		{
			printf("不能在此处下棋\n");
			printf("请重新下棋\n");
			scanf("%d %d", &row, &col);
			return drop_player(board, row, col);
		}
	}
	else
	{
		printf("不能在此处下棋\n");
		printf("请重新下棋\n");
		scanf("%d %d", &row, &col);
		return drop_player(board, row, col);
	}
}

void drop_computer(char board[ROW][COL],int row,int col,int step)
{
	while (1)
	{
		if (step > 0)
		{
			break;
		}
		if (board[row][col] == ' ')
		{
			board[row][col] = '#';
			return;
		}
		else
		{
			random(&row, &col);
		}
	}
	
	int i;
	int j;
	int count = 0;
	int count2 = 0;
	for (i = 0; i < ROW; i++)
	{
		count = 0;
		count2 = 0;
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == '*')
			{
				count = count + i + j+2;
				count2++;
			}
			if (j == COL - 1)
			{
				for (j = 0; j < COL; j++)
				{
					if ((count + i + j + 2 == 9 || count + i + j + 2 == 12 || count + i + j + 2 == 15) && board[i][j] == ' ' && count2 == 2)
					{
						board[i][j] = '#';
						return;
					}
				}
			}
		}
		count = 0;
		count2 = 0;
		if (i == ROW - 1)
		{
			for (i = 0; i < ROW; i++)
			{

				for (j = 0; j < COL; j++)
				{
					if ((count + i + j + 2 == 9 || count + i + j + 2 == 12 || count + i + j + 2 == 15) && board[i][j] == ' ' && count2 == 2)
					{
						board[i][j] = '#';
						return;
					}
					if (board[i][j] == '*')
					{
						count = count + i + j + 2;
						count2++;
						break;
						/*if (count > 2)
						{
							count--;
						}*/
					}
				}
			}
		}
	}
	step--;
	drop_computer(board, ROW, COL, step);
}

int win(char board[ROW][COL], int row, int col)
{
	int count = 0;
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				break;
			}
			if (j != COL)
			{
				if (board[i][j] == board[i][j + 1])
				{
					count++;
				}
			}
		}
		if (count == 2)
		{
			return board[i][1];
		}
		count = 0;
	}
	for (i = 0; i < COL; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			if (j != ROW)
			{
				if (board[j][i] == ' ')
				{
					break;
				}
				if (board[j][i] == board[j+1][i])
				{
					count++;
				}
			}
		}
		if (count == 2)
		{
			return board[1][i];
		}
		count = 0;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[2][2];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
	{
		return board[2][0];
	}
	
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				break;
			}
			else if (i == ROW - 1 && j == COL - 1&&board[i][j]!=' ')
			{
				return ' ';
			}
		}
	}
}

void random(int* row, int* col)
{
	srand((unsigned int)time(NULL));
	*row = rand() % ROW;
	*col = rand() % COL;
}