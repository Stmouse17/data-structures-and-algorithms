#include <stdio.h>

/*
Reorganize n sequentially stored records (with integer keys)
so that all records with negative keys precede those with non-negative keys.
*/

void PartitonNegative(int a[], int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && a[i] < 0)
			i++;
		while (i < j && a[j] >= 0)
			j--;
		if (i < j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 12, -7, -3, 4, -1, 0, 5, -9 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("Original array:\n");
	PrintArray(a, n);
	PartitonNegative(a, n);
	printf("Reorganized array:\n");
	PrintArray(a, n);
	return 0;
}