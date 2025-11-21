#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
*Shell Sort Example (using Knuth interval sequence h = 3*h + 1)
*Time complexity (varies depending on the sequence):
 Knuth sequence is approximately O(n^(3/2)) (empirical value)
*Note: Shell sort is an improvement on insertion sort,
 performing insertion sort within groups of 1 by interval h.
*Shell sort is not a stable sorting algorithm.
*/

void ShellSort(int arr[], int n)
{
	int h = 1;
	while (h < n / 3)
		h = 3 * h + 1; // Knuth interval sequence
	while (h > 0)
	{
		for (int i = h; i < n; ++i)
		{
			int temp = arr[i];
			int j = i;
			while (j >= h && arr[j - h] > temp)
			{
				arr[j] = arr[j - h];
				j -= h;
			}
			arr[j] = temp;
		}
		h = h / 3;
	}
}

void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d%s", arr[i], (i == n - 1) ? "\n" : " ");
}

int main()
{
	int arr[] = { 23, 12, 1, 8, 34, 54, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting£º");
	PrintArray(arr, n);
	ShellSort(arr, n);
	printf("After sorting£º");
	PrintArray(arr, n);
	return 0;
}