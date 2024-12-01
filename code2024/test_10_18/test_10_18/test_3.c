#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

int facadd(int n)
{
	int i, j = 1;
	if (n >= 1)
	{
		for (i = 1; i <= n; i++)
		{
			j *= i;
		}
		return j + facadd(n - 1);
	}
	else
	{
		return 0;
	}
}
//求1！—n！的和

int fac(int n)
{
	if (n >= 1)
	{
		return n * fac(n - 1);
	}
	else
		return 1;
}
//求n！

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = facadd(n);
//	int jie = fac(n);
//	printf("%d %d", ret,jie);
//	return 0;
//}