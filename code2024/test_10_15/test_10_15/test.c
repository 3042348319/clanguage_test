#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	int left, right, sz;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	sz = sizeof(arr) / sizeof(arr[0]);
	left = 0;
	right = sz - 1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了,下标是%d",mid);
			break;
		}
	}
	if (left > right)
		printf("没找到");
	return 0;
}