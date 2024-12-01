#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void InsertSort(int arr[],unsigned int n)
{
	if (n < 2)//元素小于两个，没有排序的必要，直接返回
	{
		return;
	}
	int i, j;
	int sign;
	for (i = 1; i < n; i++)//每一次循环切换下一个标准数
	{
		sign = arr[i];//保存要插入的数,并将其作为比较的标准
		for (j = i; j > 0; j--)//从标准数的位置向前一一比较
		{
			if (sign >= arr[j - 1])//比较标准数之前的数是否比标准数小
			{
				break;//由于标准数之前都是排好的，所以只要遇到比它小或者是相等的就停止
			}
			arr[j] = arr[j - 1];//由于之前是排好的，那么之要上面的if没有执行，那遇到的数一定比标准大，就将它们都往前移一位
		}
		arr[j] = sign;//在上面循环的最后，j会减1，刚好就是空出来的位置，那么就将标准值赋给它，实现插入
	}
}

void print(int arr[],unsigned int n)//用于打印排好序的数组
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int sz;
	int arr[] = { 4,2,6,8,5,1,3,9,10,7 };
	sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	print(arr, sz);
	return 0;
}