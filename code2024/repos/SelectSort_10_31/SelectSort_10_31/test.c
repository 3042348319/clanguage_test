#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void SelectSort(int arr[],int n)
{
	int i;
	int j;
	int sign;
	int* p=&arr;
	for (j = 0; j < n; j++)
	{
		sign = arr[j];
		for (i = j; i < n; i++)
		{
			if (sign > arr[i])
			{
				sign = arr[i];
				p = &arr[i];
			}
		}
		*p = arr[j];
		arr[j] = sign;
	}
}

int main()
{
	int arr[] = { 4,5,7,3,4,6,10,8,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr,sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}