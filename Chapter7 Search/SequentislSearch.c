#include <stdio.h>

//Time complexity: O(n)
//ASL: (n+1)/2

int SequentialSearch(int a[], int n, int key)
{
	a[0] = key;
	int i = n;
	while (a[i] != key)
		i--;
	return i;	//if return 0, not found; else return position
}

int main() 
{
    int a[11] = { 0, 23, 45, 12, 67, 34, 89, 10, 55, 77, 90 };
    int key = 34;
    int pos = SequentialSearch(a, 10, key);
    if (pos)
        printf("Search successful, position: %d\n", pos);
    else
        printf("Search failed, key not found.\n");
    return 0;
}