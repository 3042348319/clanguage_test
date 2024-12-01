#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	srand((unsigned)time(NULL));
	printf("欢迎来到猜数字游戏\n");
	int max=0, min=1;
	printf("请选择你要的难度:\n1:菜鸟\n2:简单\n3:普通\n4:困难\n5:地狱\n");
	int nandu;
	scanf("%d", &nandu);
	Sleep(1000);
	printf("开始猜数字吧\n");
	switch (nandu)
	{
	case 1:
		max = 10;
		break;
	case 2:
		max = 100;
		break;
	case 3:
		max = 1000;
		break;
	case 4:
		max = 10000;
		break;
	case 5:
		max = 100000;
		break;
	default:
		printf("shabi，没有这个难度\n");
	}//难度选择

	int shuzi, range;
	range = max - min + 1;
	shuzi = min + rand() % range;//生成被猜的数字；

	int shuru;
	
	do
	{
		scanf("%d", &shuru);
		if (shuru < shuzi && shuru >= min)
		{
			printf("太小了\n");
		}
		else if (shuru > shuzi && shuru <= max)
		{
			printf("太大了\n");
		}
		else if (shuru < min || shuru > max)
		{
			printf("输入的什么鬼！！\n");
		}
		else if(shuru == shuzi)
			printf("诶哟，不错哟\n");
	} while (shuru != shuzi);
	return 0;
}