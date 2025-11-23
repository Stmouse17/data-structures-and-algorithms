#include <stdio.h>

/*
There are n buckets, each containing one weight, which is red, white, or blue.
The task is to scan the buckets once (each color is checked only once),
and only swap operations are allowed to place the red weight first,
the white weight in the center, and the blue weight last.(Dutch flag problem)
*/
//An expert provided an explanation.(https://www.cnblogs.com/junyuhuang/p/4390780.html)

void DutchFlagSort(int a[], int n)
{
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high)
	{
		if (a[mid] == 0)	//Red
		{
			int tmp = a[low];
			a[low] = a[mid];
			a[mid] = tmp;
			low++;
			mid++;
		}
		else if (a[mid] == 1)//While
		{
			mid++;
		}
		else
		{
			int tmp = a[mid];
			a[mid] = a[high];
			a[high] = tmp;
			high--;
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
	int a[] = { 2,0,1,2,1,0,0,1,2,0,1 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("Before sorting:\n");
	PrintArray(a, n);
	DutchFlagSort(a, n);
	printf("After sorting:\n");
	PrintArray(a, n);
	return 0;
}