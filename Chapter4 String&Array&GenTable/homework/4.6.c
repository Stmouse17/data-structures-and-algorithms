#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Reorder(int A[], int n)
{
	int i = 0;
	int j = n - 1;
	int temp;
	while (i < j)
	{
		while (i < j && A[i] > 0)
			i++;
		while (i < j && A[j] <= 0)
			j--;
		if (i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
}

int main()
{
	int A[] = { 1, -2, 3, -4, 5, -6, -7, 8 };
	int n = sizeof(A) / sizeof(A[0]);
	Reorder(A, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}
