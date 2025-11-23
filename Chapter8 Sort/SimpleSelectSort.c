#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void SimpleSelectSort(int arr[], int n)
{
	int i, j, minIndex, temp;
	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		//Find the minimum element in unsorted array
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		//Swap the found minimum element with the first element
		if (minIndex != i)
		{
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

void PrintArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array: \n");
	PrintArray(arr, n);
	SimpleSelectSort(arr, n);
	printf("Sorted array: \n");
	PrintArray(arr, n);
	return 0;
}