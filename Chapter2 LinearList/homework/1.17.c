#include <stdio.h>
#include <math.h>

int Partition(int a[], int n)
{
	int left = 0, right = n - 1;
	int l = 0, r = n - 1;
	int S1 = 0, S2 = 0;
	int k = n / 2;
	int pivot = 0;
	while (l != k - 1)
	{
		int pivot = a[l];
		while (l < r)
		{
			while (r > l && a[r] >= pivot)	//确保r>l避免stack overflow
				r--;
			a[l] = a[r];
			while (r > l && a[l] <= pivot)	//确保r>l避免stack overflow
				l++;
			a[r] = a[l];
		}
		a[l] = pivot;
		if (l < k - 1)
		{
			left = ++l;		//更新数组起止点避免stack overflow
			r = right;
		}
		else if (l > k - 1)
		{
			right = ++r;	//更新数组起止点避免stack overflow
			l = left;
		}
	}
	for (int i = 0; i < k; i++)
		S1 += a[i];
	for (int j = k; j < n; j++)
		S2 += a[j];
	return abs(S1 - S2);
}

int main()
{
	printf("Sintream_ouse\n");
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int final = Partition(arr, length);
	printf("%d ", final);
	return 0;
}