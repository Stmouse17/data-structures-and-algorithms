#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//If you have any questions, just ask Copilot.

int IsEqual(int** a, int m, int n)
{
	int i, j, k, p;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (a[i][j] == a[i][k])
				{
					printf("no");
					return 0;
				}
			}
			for (p = i + 1; p < m; p++)
			{
				for (k = 0; k < n; k++)
				{
					if (a[i][j] == a[p][k])
					{
						printf("no");
						return 0;
					}
				}
			}
		}
	}
	printf("yes");
	return 1;
}

int main()
{
	int m, n, i, j;
	if (scanf("%d%d", &m, &n) != 2 || m <= 0 || n <= 0) {
        printf("Invalid input\n");
        return 1;
    }
	int** a = (int**)malloc(m * sizeof(int*));
	if (!a) {
        printf("Memory allocation failed\n");
        return 1;
    }
	for (i = 0; i < m; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
		if (!a[i]) {
            printf("Memory allocation failed\n");
            for (j = 0; j < i; j++) free(a[j]);
            free(a);
            return 1;
        }
		for (j = 0; j < n; j++)
		{
			if (scanf("%d", &a[i][j]) != 1) {
                printf("Invalid matrix input\n");
                for (int k = 0; k <= i; k++) free(a[k]);
                free(a);
                return 1;
            }
		}
	}
	IsEqual(a, m, n);
	for (i = 0; i < m; i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}