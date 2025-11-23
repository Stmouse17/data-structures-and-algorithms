#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Implement in-place quick sort

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition(int arr[], int low, int high)
{
	int pivotIndex = low + rand() % (high - low + 1);
	Swap(&arr[pivotIndex], &arr[high]);  //Random pivot placed at high 
	int pivot = arr[high];
	int i = low - 1;	//Lomuto partition
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() 
{
	srand((unsigned)time(NULL)); /* seed for random number generator */
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array: \n");
	PrintArray(arr, n);
	QuickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	PrintArray(arr, n);
	return 0;
}

