#include <stdio.h>
#define INF 99999
#define MAXV 10

void floyd(int n, int dist[MAXV][MAXV], int path[MAXV][MAXV]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j && dist[i][j] < INF)
                path[i][j] = j;
            else
                path[i][j] = -1; 
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k]; 
                }
            }
        }
    }
}

void printMatrix(int n, int dist[MAXV][MAXV]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void printPath(int start, int end, int path[MAXV][MAXV]) {
    if (path[start][end] == -1) {
        printf("No reachable from %d to %d\n", start, end);
        return;
    }

    printf("The short path from %d to %d: %d", start, end, start);
    while (start != end) {
        start = path[start][end];
        printf(" -> %d", start);
    }
    printf("\n");
}

int main() {
    int n = 4;
    int dist[MAXV][MAXV] = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    int path[MAXV][MAXV];
    printf("Original distance matrix: \n");
    printMatrix(n, dist);
    floyd(n, dist, path);
    printf("\nShortest path distance matrix: \n");
    printMatrix(n, dist);
    printf("\nexample paths: \n"); 
    printPath(0, 3, path);
    printPath(0, 2, path);
    printPath(1, 3, path);
    return 0;
}

//Test example
/*
    Original distance matrix:
          0      5    INF     10
        INF      0      3    INF
        INF    INF      0      1
        INF    INF    INF      0

    Shortest path distance matrix:
        0      5      8      9
        INF      0      3      4
        INF    INF      0      1
        INF    INF    INF      0

    example paths:
    The short path from 0 to 3: 0 -> 1 -> 2 -> 3
    The short path from 0 to 2: 0 -> 1 -> 2
    The short path from 1 to 3: 1 -> 2 -> 3
*/
