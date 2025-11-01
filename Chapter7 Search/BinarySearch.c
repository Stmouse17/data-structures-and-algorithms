#include <stdio.h>

//Time complexity: O(log n)
//ASL: log(n + 1) - 1 (n > 50)

int BinarySearch(int arr[], int size, int key) 
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		// Check if key is present at mid
		if (arr[mid] == key)
			return mid; // key found
		// If key is greater, ignore left half
		else if (arr[mid] < key) 
			left = mid + 1;
		// If key is smaller, ignore right half
		else 
			right = mid - 1;
	}
	return -1; // key not found
}

int main()
{
	int arr[] = {2, 3, 4, 10, 40};
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 10;
	int result = BinarySearch(arr, size, key);
	if (result != -1) 
		printf("Element found at index %d\n", result);
	else 
		printf("Element not found in array\n");
	return 0;
}