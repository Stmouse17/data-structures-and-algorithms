#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Perform heapification (max heap) on the subtree rooted at node i

void Heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		Swap(&arr[i], &arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{
	int i;
	//The index of the last non-leaf node = n/2 - 1
	for (i = n / 2 - 1; i >= 0; i--)	//First, build the array into a max heap.
		Heapify(arr, n, i);
	/*
	Swap the top(maximum value) of the heap to the end
	one by one to reduce the size of the heap,
	and then heapify it again.
	*/
	for (i = n - 1; i > 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
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
	int arr[] = { 17, 11, 14, 5, 6, 7, 1, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array: \n");
	PrintArray(arr, n);
	HeapSort(arr, n);
	printf("Sorted array: \n");
	PrintArray(arr, n);
	return 0;
}
