#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

void HeapSort(int arr1[], int arr2[]);



int main()
{
	int arr1[] = { 4,2,10,21,25,3,8,9,1 };
	int arr2[] = { 6,18,14,30,40,44,7,0,22 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	HeapSort(arr1, arr2);
	return 0;
}

void HeapSort(int arr1[], int arr2[])
{

}