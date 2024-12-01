#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void QuickSort(int arr[],unsigned int n)
{
	if (n < 2)
	{
		return;
	}
	int sign = arr[0];
	int left = 0;
	int right = n - 1;
	int move = 2;

	while (left < right)
	{
		if (move == 2)
		{
			if (arr[right] >= sign)
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
			if (arr[left] <= sign)
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
	arr[left] = sign;

	QuickSort(arr, left);
	QuickSort(arr + 1 + left, n-left-1);
}

int main()
{
	unsigned int sz;
	int arr[10] = { 4,7,5,2,9,10,6,8,1,3 };
	sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}