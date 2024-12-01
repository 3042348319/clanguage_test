#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void menu();

void initboard(char board[ROW][COL], int row, int col);

void diseplay(char board[ROW][COL], int row, int col);

void drop_player(char board[ROW][COL], int row, int col);

void drop_computer(char board[ROW][COL], int row, int col,int stepth);

int win(char board[ROW][COL], int row, int col);

void random(int* row, int* col);