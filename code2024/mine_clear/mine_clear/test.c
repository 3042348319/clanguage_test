#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include"game.h"
#include"debug.h"

void game()
{
    char field1[ROWS][COLS];//地雷位置
    memset1(field1, ROW, COL);
    set_mine(field1, ROW, COL);
    print(field1, ROW, COL);//检测

    char field2[ROWS][COLS];
    memset2(field2, ROW, COL);
    set_digit(field1, field2, ROW, COL);
    print(field2, ROW, COL);

    char display[ROW+1][COL+1];//用于展示的雷区
    memset3(display, ROW, COL);
    puts("扫雷");
    Display(display, ROW, COL);//展示

    do
    {
        puts("请输入坐标：");
        int x, y;
        scanf("%d%d", &x, &y);
        drop(field2, display, x, y);
    } while (1);
}

int main()
{
    srand((unsigned int)time(NULL));

    menu();
    int n;

    do
    {
        scanf("%d", &n);
        if (n == 1)
        {
            puts("扫雷");
            game();
        }
        else if (n == 2)
        {
            puts("退出游戏");
            break;
        }
        else
        {
            puts("输入错误");
        }
    } while (1);

    return 0;
}