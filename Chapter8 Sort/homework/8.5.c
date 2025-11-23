#include <stdio.h>

/*
Using the idea of ​​quicksort, search for the record
whose key is equal to key in the unordered array r[1..n].
If found, return the position; otherwise, output "not find".
*/

int Partition(int arr[], int l, int r)
{
	int pivot = arr[l];
	int i = l, j = r;
	while (i < j)
	{
		while (i < j && arr[j] >= pivot)
			j--;
		if (i < j)
			arr[i++] = arr[j];
		while (i < j && arr[i] <= pivot)
			i++;
		if (i < j)
			arr[j--] = arr[i];
	}
	arr[i] = pivot;
	return i;
}

int QuickSearch(int arr[], int n, int key)
{
	int l = 0, r = n - 1;
	while (l < r)
	{
		int p = Partition(arr, l, r);
		if (arr[p] == key)
			return p;
		else if (arr[p] > key)
			r = p - 1;
		else
			l = p + 1;
	}
	return -1;
}

int main()
{
	int arr[] = { 34, 7, 23, 32, 5, 62 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 23;
	int result = QuickSearch(arr, n, key);
	if (result != -1)
		printf("Element found at index: %d\n", result);
	else
		printf("Not find\n");
	return 0;
}