#include <stdio.h>
#define MAX 100
#define BLOCKS 3

//Time complexity: O(sqrt(n))
//ASL:log(n/s + 1) + s/2, s is the block size

typedef struct
{
	int key;	// The maximum key in the block
	int start, end;
}Index;

int SequentialSearch(int a[], int n, int key)
{
	a[0] = key;
	int i = n;
	while (a[i] != key)
		i--;
	return i;
}

int BlockSearch(int a[], Index index[], int m, int key)
{
	int i = 0;
	for (i = 0; i < m; i++)
		if (key <= index[i].key)
			break;
	if (i == m)
		return -1;
	return SequentialSearch(a + index[i].start - 1, index[i].end - index[i].start + 1, key) + index[i].start - 1;

}

int main()
{
	int a[MAX] = { 0, 12, 18, 25, 37, 45, 50, 60, 75, 90, 100 };
	Index index[BLOCKS] = {
		{25, 1, 3},
		{60, 4, 7},
		{100, 8, 10}
	};
	int key = 75;
	int pos = BlockSearch(a, index, BLOCKS, key);
	if (pos)
		printf("Search successful, key %d found at position %d\n", key, pos);
	else
		printf("Search failed, key %d not found\n", key);
	return 0;
}