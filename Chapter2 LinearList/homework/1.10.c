#include <stdio.h>
#define SIZE 17

void DeleteItem(int* arr, int item)
{
	int k = 0;
	
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] != item)
		{
			arr[k] = arr[i];
			k++;
		}
	}
	for (int j = k; j < SIZE; j++)
		arr[j] = 0;
}

int main()
{
	int a[SIZE] = { 1,3,5,5,9,10,44,77,3,3,5,3,78,117 };
	DeleteItem(a, 3);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	return 0;
}