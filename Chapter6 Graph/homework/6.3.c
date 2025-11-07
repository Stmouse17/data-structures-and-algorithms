#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXV 100
#define INF INT_MAX

typedef struct
{
	int n;
	int edges[MAXV][MAXV];
}Graph;

int LongestOfShortestPaths(Graph* G, int start)
{
	int n = G->n;
	int dist[MAXV];
	int visited[MAXV];
	int path[MAXV];
	for (int i = 0; i < n; i++)
	{
		dist[i] = G->edges[start][i];
		visited[i] = 0;
		if (dist[i] != INF && i != start)
			path[i] = start;
		else
			path[i] = -1;
	}
	visited[start] = 1;
	dist[start] = 0;
	for (int i = 1; i < n; i++)
	{
		int min = INF;
		int u = -1;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}
		if (u == -1)
			break;
		visited[u] = 1;
		for (int v = 0; v < n; v++)
		{
			if (!visited[v] && G->edges[u][v] != INF && dist[u] + G->edges[u][v] < dist[v])
			{
				dist[v] = dist[u] + G->edges[u][v];
				path[v] = u;
			}
		}
	}
	//Choose the longest path among all shortest paths
	int maxDist = -1;
	int farthestVertex = -1;
	for (int i = 0; i < n; i++)	
	{
		if (i != start && dist[i] != INF && dist[i] > maxDist)
		{
			maxDist = dist[i];
			farthestVertex = i;
		}
	}
	return farthestVertex;
}

int main()
{
	Graph G;
	int n = 6;
	G.n = n;
	int matrix[6][6] = {
		{0, 7, 9, INF, INF, 14},
		{7, 0, 10, 15, INF, INF},
		{9, 10, 0, 11, INF, 2},
		{INF, 15, 11, 0, 6, INF},
		{INF, INF, INF, 6, 0, 9},
		{14, INF, 2, INF, 9, 0}
	};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G.edges[i][j] = matrix[i][j];
	int start = 0;
	int farthestVertex = LongestOfShortestPaths(&G, start);
	printf("The vertex farthest from vertex %d is vertex %d.\n", start, farthestVertex);
	return 0;
}



