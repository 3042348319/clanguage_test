#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void SelectSort_3(int arr[], int n);

int main()
{
	int arr[] = { 4,5,7,3,4,6,10,8,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort_3(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void SelectSort_3(int arr[], int n)
{
	int i, j;
	int max, min;
	int* p1 = &arr;
	int* p2 = &arr;
	for (i = 0; i < n/2; i++)
	{
		max = arr[n - i - 1];
		min = arr[i];
		for (j = i; j < n-i; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				p1 = &arr[j];
			}
		}
		*p1 = arr[i];
		arr[i] = min;
		for (j = i; j < n - i; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				p2 = &arr[j];
			}
		}
		*p2 = arr[n - i - 1];
		arr[n - i - 1] = max;
	}
}
