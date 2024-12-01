#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include"fac.h"

int fibo(int x1,int x2,int n)
{
	int z = x1 + x2;
	if (n <= 2)
	{
		return 0;
	}
	else
	{
		return z + fibo(x2,z,n-1);
	}
}

int fib(int x1, int x2, int n)
{
	int z = x1 + x2;
	if (n < 3)
	{
		return x2;
	}
	else
	{
		return fib(x2, z, n - 1);
	}
}
int main()
{
	int x1, x2, n;
	scanf("%d%d%d", &x1, &x2, &n);
	int ret = fibo(x1, x2, n) + x1 + x2;
	int Fib = fib(x1, x2, n);
	printf("%d %d", ret,Fib);
	return 0;
}