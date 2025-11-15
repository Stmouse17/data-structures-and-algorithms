#include <stdio.h>

int BinarySearchRecursive(int a[], int key, int low, int high)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (a[mid] == key)
		return mid;
	else if (a[mid] > key)
		return BinarySearchRecursive(a, key, low, mid - 1);
	else
		return BinarySearchRecursive(a, key, mid + 1, high);
}

int main()
{
	int assent_table[] = { 1, 3, 5, 7, 9, 11, 13 };
	int length = sizeof(assent_table) / sizeof(assent_table[0]);
	int key = 7;
	//int key = 8;
	int pos = BinarySearchRecursive(assent_table, key, 0, length - 1);
	if (pos != -1)
		printf("keyword: %d, position: %d\n", key, pos);
	else
		printf("Search failed");
	return 0;
}