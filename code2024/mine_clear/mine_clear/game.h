#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define easy 10
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11

void menu();

void memset1(char field[ROWS][COLS], int row, int col);

void set_mine(char field[ROWS][COLS], int row, int col);

void memset2(char field[ROWS][COLS], int row, int col);

void set_digit(char field1[ROWS][COLS], char field2[ROWS][COLS], int row, int col);

void memset3(char display[ROW+1][COL+1], int row, int col);

void Display(char display[ROW+1][COL+1], int row, int col);

void drop(char display[ROW + 1][COL + 1], char field[ROWS][COLS], int x, int y);

void find_zero(char display[ROW + 1][COL + 1],char field[ROWS][COLS], int x, int y);

