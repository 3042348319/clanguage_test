#define _CRT_SECURE_NO_WARNINGS	
#include "game.h"
void menu()
{
    printf("***********welcome to mine clear***********\n");
    printf("************1.play*************\n");
    printf("************2.exit*************\n");
}

void memset1(char field[ROWS][COLS], int row, int col)
{
    int i;
    int j;
    for (i = 1; i <= ROW; i++)
    {
        for (j = 1; j <= COL; j++)
        {
            field[i][j] = ' ';
        }
    }
    for (i = 0; i < ROWS; i++)
    {
        field[0][i] = '#';
        field[i][0] = '#';
        field[ROWS - 1][i] = '#';
        field[i][ROWS - 1] = '#';

    }
}

void set_mine(char field[ROWS][COLS], int row, int col)
{
    int i = easy;
    while (i--)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        field[x][y] = '*';
    }
}

void memset2(char field[ROWS][COLS], int row, int col)
{
    int i, j;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            field[i][j] = '0';
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        field[0][i] = 'a';
        field[i][0] = 'a';
        field[ROWS - 1][i] = 'a';
        field[i][ROWS - 1] = 'a';
    }
}

void set_digit(char field1[ROWS][COLS], char field2[ROWS][COLS], int row, int col)
{
    int i, j;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            if (field1[i][j] == '*')
            {
                field2[i][j] = '*';
                if (field2[i + 1][j] != '*')
                    field2[i + 1][j] += 1;
                if (field2[i - 1][j] != '*')
                    field2[i - 1][j] += 1;
                if (field2[i + 1][j + 1] != '*')
                    field2[i + 1][j + 1] += 1;
                if (field2[i + 1][j - 1] != '*')
                    field2[i + 1][j - 1] += 1;
                if (field2[i - 1][j + 1] != '*')
                    field2[i - 1][j + 1] += 1;
                if (field2[i - 1][j - 1] != '*')
                    field2[i - 1][j - 1] += 1;
                if (field2[i][j + 1] != '*')
                    field2[i][j + 1] += 1;
                if (field2[i][j - 1] != '*')
                    field2[i][j - 1] += 1;
            }
        }
    }
}

void memset3(char display[ROW+1][COL+1], int row, int col)
{
    int i, j;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            display[i][j] = ' ';
        }
    }

    for (i = 0; i < ROW + 1; i++)
    {
        display[i][0] = '0';
        display[i][0] += i;

        display[0][i] = '0';
        display[0][i] += i;
    }
}

void Display(char display[ROW+1][COL+1], int row, int col)
{
    int i, j;
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            printf(" %c ", display[i][j]);
            printf("|");
        }
        printf("\n");
        for (j = 0; j <= col; j++)
        {
            printf("---");
            printf("|");
        }
        printf("\n");
    }
}

void find_zero(char display[ROW+1][COL+1], char field[ROWS][COLS], int x, int y)
{
    if (field[x][y] != '0')
    {
        display[x][y] = field[x][y];
        return;
    }
    else if (field[x][y] == '0')
    {
        if (field[x + 1][y] == '0')
        {
            display[x + 1][y] = field[x + 1][y];
            return find_zero(display, field, x + 1, y);
        }
        else if (field[x+1][y] > '0' && field[x+1][y] <= '8')
        {
            display[x + 1][y] = field[x + 1][y];
        }
        if (field[x - 1][y] == '0')
        {
            display[x - 1][y] = field[x - 1][y];
            return find_zero(display, field, x - 1, y);
        }
        else if (field[x - 1][y] > '0' && field[x - 1][y] <= '8')
        {
            display[x - 1][y] = field[x - 1][y];
        }
    }
}

void drop(char display[ROW + 1][COL + 1], char field[ROWS][COLS], int x, int y)
{
    if (field[x][y] == '*')
    {
        display[x][y] = field[x][y];
        puts("ÓÎÏ·Ê§°Ü");
        return;
    }
    else
    {
        find_zero(display,field, x, y);
    }
}
