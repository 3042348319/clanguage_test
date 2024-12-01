#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void radixsort(int arr[], int n);

int arrmax(int arr[], int n);

void _radixsort(int arr[], int n, int iexp);

void copy(int result[], int arr[], int n);

int main()
{
	int arr[] = { 144,203,6,905,47,215,836,26,527,602 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	radixsort(arr, sz);
	return 0;
}

void radixsort(int arr[], int n)
{
	int imax = arrmax(arr, n);

	int iexp;

	for (iexp = 1; imax / iexp > 0; iexp *= 10)
	{
		_radixsort(arr, n, iexp);
		int yy;
		printf("exp=%-5d  ", iexp);
		for (yy = 0; yy < n; yy++)
		{
			printf("%2d ", arr[yy]);
			printf("\n");
		}
	}
}

void _radixsort(int arr[], int n, int iexp)
{
	int bucket[10] = { 0 };
	int result[n];
	int i;
	
	for (i = 0; i < n; i++)
	{
		bucket[arr[i] / iexp % 10] = arr[i];
	}

	for (i = 0; i < n - 1; i++)
	{
		bucket[i + 1] += bucket[i];
	}

	for (i = n - 1; i >= 0; i--)
	{
		int exp = arr[i] / iexp % 10;
		result[bucket[exp] - 1] = arr[i];
		bucket[exp]--;
	}

	copy(result, arr, n);
}

void copy(int result[], int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = result[i];
	}
}


