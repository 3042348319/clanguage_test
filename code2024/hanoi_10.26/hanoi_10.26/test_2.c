#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void a(int arr[])
{
	printf("%d",arr[-1]);
}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	a(arr + 1);
	return 0;
}