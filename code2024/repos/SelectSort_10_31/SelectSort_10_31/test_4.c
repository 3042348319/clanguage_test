#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void SelectSort_4(int arr[], int n);

void swap(int* a, int* b);

int main()
{
	int arr[] = { 4,5,7,3,4,6,10,8,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort_4(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void SelectSort_4(int arr[], int n)
{
	int max=0, min=0;
	int left = 0;
	int right = n - 1;
	int i;
	while (left < right)
	{
		for (i = left; i < n-left; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		swap(&arr[left], &arr[min]);
		if (left == max)
		{
			max = min;
		}
		swap(&arr[right], &arr[max]);
		left++;
		right--;
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
