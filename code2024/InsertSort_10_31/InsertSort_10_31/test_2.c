#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void InsertSort_2(int arr[], int n, int sign)
{
	int i;
	int tmp;
	if (sign > n - 1)
	{
		return;
	}
	if (sign < 1)
	{
		InsertSort_2(arr, n, sign + 1);
	}
	for (i = sign; i >= 0; i--)
	{
		if (arr[i] < arr[i - 1])
		{
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
		}
	}
	InsertSort_2(arr, n, sign + 1);
}

//int main()
//{
//	int sz;
//	int arr[] = { 4,2,6,8,5,1,3,9,10,7 };
//	sz = sizeof(arr) / sizeof(arr[0]);
//	InsertSort_2(arr, sz, 0);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}