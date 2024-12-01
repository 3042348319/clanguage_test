#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void RadixSort(int arr[], int n);

void collect(int arr[], int count[], int arr1[10][10]);

void numset(int arr[]);

int arrmax(int arr[], int n);

int main()
{
	int arr[] = { 144,203,6,905,47,215,836,26,527,602 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i;
	RadixSort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void RadixSort(int arr[], int n)
{
	int max = arrmax(arr,n);//找出数组中的最大值
	int arr1[10][10] = {0};
	int count[10] = {0};//计数器，记录十个桶内的数字的个数
	int i;
	int j;
	for (j = 1; max / j > 0; j = j * 10)//从个位开始排序
	{
		for (i = 0; i < n; i++)
		{
			arr1[arr[i] / j % 10][count[arr[i] / j % 10]] = arr[i];
			count[arr[i] / j % 10]++;
		}
		collect(arr, count, arr1);//收集排好序的数字
		numset(count);//初始化
	}
}

void collect(int arr[], int count[], int arr1[10][10])
{
	int i;
	int j;
	int k = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < count[i]; j++)
		{
			arr[k] = arr1[i][j];
			k++;
		}
	}
}

void numset(int arr[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
}

int arrmax(int arr[], int n)
{
	int i;
	int max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}



