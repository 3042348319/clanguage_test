#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void ShellSort(int arr[], int n);

void groupsort(int arr[], int step_length,int first,int n);

int main()
{
	int arr[] = { 4,6,5,10,8,9,2,3,1,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void ShellSort(int arr[], int n)
{
	int i;
	int j;
	for (i = n/2; i > 0; i = i / 2)
	{
		for (j = 0; j < i; j++)
		{
			groupsort(arr, i,j,n);
		}
	}
}

void groupsort(int arr[], int step_length,int first,int n)
{
	if (n < 2)
	{
		return;
	}
	int i;
	int j;
	int sign;
	for (i = step_length+first; i < n; i = i + step_length)
	{
		sign = arr[i];
		for (j = i-step_length; j >=0; j = j - step_length)
		{
			if (arr[j] <= sign)
			{
				break;//这里用break可以起到截断的作用，退出循环后的j就是要插入位置的j
			}
			arr[j + step_length] = arr[j];
		}
		arr[j+step_length] = sign;
	}
}