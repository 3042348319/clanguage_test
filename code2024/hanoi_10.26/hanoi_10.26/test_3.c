#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void bubble_sort(int arr[])
{
	int i;
	int j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//int main()
//{
//	int arr[10];
//	int i;
//	for (i = 0; i <= 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	bubble_sort(arr);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
