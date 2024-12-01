#define _CRT_SECURE_NO_WARNINGS
#include"debug.h"
void print(char arr[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}