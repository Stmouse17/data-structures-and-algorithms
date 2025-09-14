#include <stdio.h>

int Median(int A[], int B[], int n)
{
	int start1 = 0, start2 = 0;
	int end1 = n - 1, end2 = n - 1;
	while (start1 != end1 || start2 != end2)
	{
		int m1 = (start1 + end1) / 2;
		int m2 = (start2 + end2) / 2;
		if (A[m1] == B[m2])
		{
			return A[m1];
		}
		else if (A[m1] < B[m2])
		{
			if ((start1 + end1) % 2 == 0)
			{
				start1 = m1;
				end2 = m2;
			}
			else
			{
				start1 = m1 + 1;
				end2 = m2;
			}
		}
		else
		{
			if ((start1 + end1) % 2 == 0)
			{
				start2 = m2;
				end1 = m1;
			}
			else
			{
				start2 = m2 + 1;
				end1 = m1;
			}
		}
	}
	return A[start1] < B[start2] ? A[start1] : B[start2];
}

int main()
{
	printf("Sintream_ouse\n");
	int a[] = { 11,13,15,17,19 };
	int b[] = { 2,4,6,8,20 };
	int length = sizeof(a) / sizeof(a[0]);
	int mid = Median(a, b, length);
	printf("%d ", mid);
	return 0;
}
