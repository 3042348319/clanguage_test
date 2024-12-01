#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void BucketSort(int arr[], int n);

void bubble(int arr[], int n);

void swap(int* a, int* b);

int main()
{
	int arr[] = { 4,6,5,10,8,9,2,3,1,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BucketSort(arr, sz);
	return 0;
}

void BucketSort(int arr[], int n)
{
	int arr1[5];
	int arr2[5];
	int i;
	int j=0;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] >= 0 && arr[i] <= 5)
		{
			arr1[j] = arr[i];
			j++;
			continue;
		}
		if (arr[i] > 5 && arr[i] <= 10)
		{
			arr2[k] = arr[i];
			k++;
			continue;
		}
	}
	bubble(arr1, 5);
	bubble(arr2, 5);

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
}

void bubble(int arr[], int n)
{
	int i;
	int j;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
