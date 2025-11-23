#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//(1)Sequential list definition: An array is used to store records and keys.
typedef struct Node
{
	int key;
}Record;

//(2)Naive counting sort (stable): time O(n^2), space O(n)
//There are no duplicate elements in the table.

void NaiveCountingSort(Record in[], Record out[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		for (int j = 0; j < n; ++j)
			if (in[j].key < in[i].key)
				count++;
		out[count] = in[i];
	}
}

/*
(3) Number of key comparisons : Naive counting sort requires scanning the entire table
    for each element and making comparisons, which is approximately n* (n - 1) / 2 comparisons.
*/
/*Counting sorting within a continuous range
  time complexity: O(n + K), space complexity: O(K)
  The table may contain duplicate elements.
*/

void CountingSortByRange(Record in[], Record out[], int n, int K)
{
	int* count = (int*)calloc(K, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		if (in[i].key < 0 || in[i].key >= K)
		{
			fprintf(stderr, "Key out of range\n");
			free(count);
			return;
		}
		count[in[i].key]++;	// Count occurrences of each key
	}
		for (int i = 1; i < K; ++i)
			count[i] += count[i - 1]; // Cumulative count
		for (int i = n - 1; i >= 0; --i)
		{
			int k = in[i].key;
			out[count[k] - 1] = in[i];	// Place record in sorted position
			count[k]--;
		}
		free(count);
}

void PrintRecords(Record recs[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", recs[i].key);
	printf("\n");
}

/*
(4)Compared to simple selection sort: Naive counting sort has 
   the same number of comparisons as selection sort, жи(n^2),
   but counting sort directly puts the result into the output array (stable).
   If the range of keys is limited and can be optimized with an additional counting array,
   it can be reduced to O(n + k), making it superior to selection sort when k is small.
*/

int main()
{
	Record in[] = { {4}, {2}, {5}, {1}, {3} };
	int n = sizeof(in) / sizeof(in[0]);
	Record* out = (Record*)malloc(n * sizeof(Record));
	if (!out)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	printf("Input records:\n");
	PrintRecords(in, n);
	NaiveCountingSort(in, out, n);
	printf("Sorted records:\n");
	PrintRecords(out, n);
	free(out);
	return 0;
}