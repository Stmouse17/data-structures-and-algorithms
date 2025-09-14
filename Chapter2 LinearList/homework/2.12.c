#include <stdio.h>

void Reverse(int arr[], int i, int j)
{
	while (i < j)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
}

void LeftShift(int arr[], int n, int p)
{
	if (p > 0 && p < n)
	{
		Reverse(arr, 0, n - 1);
		Reverse(arr, 0, n - 1 - p);
		Reverse(arr, n - p, n - 1);
	}
}

int main()
{
	printf("Sintream_ouse\n");
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(int);
	LeftShift(a, n, 4);
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}
