#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Direct insertion sort
//best time complexity: O(n)
//average time complexity: O(n^2)
//worst time complexity: O(n^2)

void DirectInsertSort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//Binary insertion sort
//best time complexity: O(n log n)
//average time complexity: O(n^2)
//worst time complexity: O(n^2)

int BinarySearch(int arr[], int key, int low, int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid + 1;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;	//return the position to insert
}

void BinaryInsertSort(int arr[], int n)
{
	int i, j, key, pos;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		pos = BinarySearch(arr, key, 0, i - 1);
		for (j = i - 1; j >= pos; j--)
			arr[j + 1] = arr[j];
		arr[pos] = key;
	}
}

void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr1[] = { 12, 11, 13, 5, 6 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	DirectInsertSort(arr1, n1);
	printf("Sorted array using Direct Insertion Sort: \n");
	PrintArray(arr1, n1);
	int arr2[] = { 17, 11, 13, 5, 6, 7, 4 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	BinaryInsertSort(arr2, n2);
	printf("Sorted array using Binary Insertion Sort: \n");
	PrintArray(arr2, n2);
	return 0;
}



