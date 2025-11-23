#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Radix sort (LSD) supports both positive and negative integers
/*
1. Divide the array into two parts: negative numbers and non-negative numbers.
2. For non-negative numbers, directly use radix sort (sorting by stable counting of each digit).
3. After taking the absolute value of negative numbers, sort them by radix, then reverse the order
   of the results and add a negative sign again (because a larger absolute value corresponds to a smaller negative number).
4.Finally, by placing the reversed negative numbers at the beginning and the non-negative numbers at the end,
  we obtain a sorted array (ascending order).
5.In practical engineering, each "bucket" in radix sort may be a linked queue(FIFO).
*/

void CountingSort(int arr[], int n, int exp)
{
	int* output = (int*)malloc(n * sizeof(int)); // output array
	if (!output)
		return;					// memory allocation failed
	int count[10] = { 0 };		// count array for digits 0-9
	for (int i = 0; i < n; i++)
	{
		int digit = (arr[i] / exp) % 10;	// extract digit
		count[digit]++;
	}
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];	
	/*
	After conversion, count[d] represents the total number of elements
	in the array that are less than or equal to digit d
	*/
	for (int i = n - 1; i >= 0; i--)
	{
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];	// place in output array from back to front
		count[digit]--;						// decrement count
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}

void RadixSort(int arr[], int n)
{
	if (n <= 1)
		return;
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	for (int exp = 1; max / exp > 0; exp *= 10)	// exp is the current digit place (1, 10, 100, ...)
		CountingSort(arr, n, exp);
}

void RadixSortWithNegatives(int arr[], int n)
{
	if (n <= 1)
		return;
	int* pos = (int*)malloc(n * sizeof(int));
	int* neg_abs = (int*)malloc(n * sizeof(int));
	if (!pos || !neg_abs)
	{
		free(pos);
		free(neg_abs);
		return;
	}
	int pos_count = 0, neg_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
			pos[pos_count++] = arr[i];
		else
			neg_abs[neg_count++] = -arr[i]; // store absolute value
	}
	if (pos_count > 0)
		RadixSort(pos, pos_count);
	if (neg_count > 0)
		RadixSort(neg_abs, neg_count);
	int idx = 0;
	// Place negative numbers in reverse order
	for (int i = neg_count - 1; i >= 0; i--)
		arr[idx++] = -neg_abs[i];
	// Place non-negative numbers
	for (int i = 0; i < pos_count; i++)
		arr[idx++] = pos[i];
	free(pos);
	free(neg_abs);
}
void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 176, -45, 77, -90, -872, 24, 2, 67 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array:\n");
	PrintArray(arr, n);
	RadixSortWithNegatives(arr, n);
	printf("Sorted array:\n");
	PrintArray(arr, n);
	return 0;
}

