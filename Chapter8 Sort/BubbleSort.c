#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(const int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (i)
			putchar(' ');
		printf("%d", arr[i]);
	}
	putchar('\n');
}

//Stable sorting, in-place sorting, 
//best case O(n), average/worst case O(n^2), extra space O(1).

void BubbleSort(int arr[], int n)
{
	if (n <= 1)
		return;
	for (int i = 0; i < n - 1; ++i)	
	{
		bool swapped = false;
		for (int j = 0; j < n - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;	// Array is already sorted
	}
}

//Each cycle moves the largest value from left to right to the right,
//and then moves the smallest value from right to left to the left.
//Best case O(n), average/worst case O(n^2)

void CocktailSort(int arr[], int n)
{
	if (n <= 1)
		return;
	int start = 0, end = n - 1;
	bool swapped = true;
	while (swapped && start < end)
	{
		swapped = false;
		for (int i = start; i < end; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		--end;	//The right end is already the largest; shrink the right boundary.
		swapped = false;
		for (int i = end; i > start; --i)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
				swapped = true;
			}
		}
		++start;	//The left end is already the smallest; shrink the left boundary.
	}
}

int main()
{
	int original[] = { 5, 1, 4, 2, 8, 3, 7, 6 };
	int n = sizeof(original) / sizeof(original[0]);
	int a1[sizeof(original) / sizeof(original[0])];
	int a2[sizeof(original) / sizeof(original[0])];
	//Copy the original array so that you can test the two sorting methods separately.
	memcpy(a1, original, sizeof(original));
	memcpy(a2, original, sizeof(original));
	printf("Original array: ");
	PrintArray(original, n);
	//Test one-way bubble sort
	BubbleSort(a1, n);
	printf("bubble sort result: ");
	PrintArray(a1, n);
	//Test the sorting of two-way bubbling (cocktail)
	CocktailSort(a2, n);
	printf("cocktail sort result: ");
	PrintArray(a2, n);
	return 0;
}