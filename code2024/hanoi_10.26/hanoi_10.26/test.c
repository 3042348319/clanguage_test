#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void move(char x, char y)
{
	printf("从%c柱上拿一个盘子到%c柱上\n", x, y);
}

void hanoi(int n, char one, char two, char three)//one指起始点，three指目标点，two是上一个盘的目标点
{
	if (n == 1)
	{
		move(one, three);
	}
	else
	{
		hanoi(n - 1, one, three, two);//改变目标点
		move(one, three);
		hanoi(n - 1, two, one, three);//改变起始点
	}
}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//}