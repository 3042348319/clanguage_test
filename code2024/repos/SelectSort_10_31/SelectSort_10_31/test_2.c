#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void selectsort(int arr[], int n)
{
	int i;
	int sign = arr[0];
	int* p = &arr;
	if (n == 1)
	{
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (arr[i] < sign)
		{
			sign = arr[i];
			p = &arr[i];
		}
	}
	*p = arr[0];
	arr[0] = sign;
	selectsort(arr + 1, n-1);
}

int main()
{
	int arr[] = { 4,5,7,3,4,6,10,8,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectsort(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}