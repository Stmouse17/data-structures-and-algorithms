#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;	// Size of left subarray
	int n2 = right - mid;		// Size of right subarray
	int * L = (int *)malloc(n1 * sizeof(int)); // Create left subarray
	int * R = (int *)malloc(n2 * sizeof(int)); // Create right subarray
	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	int i = 0, j = 0, k = left;
	// Merge the subarrays back into arr
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	// Copy remaining elements
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}

void MergeSortIterative(int arr[], int n)
{
	for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2)	// curr_size: size of subarrays to be merged
	{
		for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size)	
		{
			int mid = (left_start + curr_size - 1 < n - 1) ? left_start + curr_size - 1 : n - 1;
			int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? left_start + 2 * curr_size - 1 : n - 1;
			Merge(arr, left_start, mid, right_end);
		}
	}
}

void MergeSortRecursive(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSortRecursive(arr, left, mid);
		MergeSortRecursive(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr1[] = { 17, 12, 14, 5, 6, 7 };
	int arr2[] = { 14, 17, 12, 5, 6, 7 };
	int arr_size = sizeof(arr1) / sizeof(arr1[0]);
	printf("Given array for Iterative Merge Sort is \n");
	PrintArray(arr1, arr_size);
	MergeSortIterative(arr1, arr_size);
	printf("\nSorted array by Iterative Merge Sort is \n");
	PrintArray(arr1, arr_size);
	printf("\nGiven array for Recursive Merge Sort is \n");
	PrintArray(arr2, arr_size);
	MergeSortRecursive(arr2, 0, arr_size - 1);
	printf("\nSorted array by Recursive Merge Sort is \n");
	PrintArray(arr2, arr_size);
	return 0;
}