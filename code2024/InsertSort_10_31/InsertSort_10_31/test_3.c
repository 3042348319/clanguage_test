#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void quicksort(int arr[], int n);

void InsertSort(int arr[], int n);

int Seek_Standard(int arr[], int n);


int main()
{
	int arr[] = { 4,6,5,10,8,9,2,3,1,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void quicksort(int arr[], int n)
{
	if (n <= 10)
	{
		return InsertSort(arr, n);
	}

	int left, right;
	left = 0;
	right = n - 1;
	int move = 2;
	int sign = Seek_Standard(arr,n);
	
	while (left < right)
	{
		if (move == 2)
		{
			if (arr[right] > sign)
			{
				right--;
				continue;
			}
			arr[left] = arr[right];
			left++;
			move = 1;
			continue;
		}

		if (move == 1)
		{
			if (arr[left] < sign)
			{
				left++;
				continue;
			}
			arr[right] = arr[left];
			right--;
			move = 2;
			continue;
		}
	}

	quicksort(arr, left);
	quicksort(arr + left + 1, n - left - 1);
}

int Seek_Standard(int arr[], int n)
{
	int Step = n / 10;
	int i, j;
	int sign;
	int arr2[10];
	for (i = 0, j = 0; i < n && j < 10; i = i + Step,j++)
	{
		arr2[j] = arr[i];
	}

	for (i = 1; i < n; i++)
	{
		sign = arr2[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] <= sign)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = sign;
	}
	return arr[5];
}
