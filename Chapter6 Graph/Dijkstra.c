#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct
{
	int n;	//number of vertices
	int edges[MAX_VERTICES][MAX_VERTICES];
}Graph;	//adjacency matrix representation of a graph

void Dijkstra(Graph* G, int start)
{
	int n = G->n;
	int dist[MAX_VERTICES];	//distance from start to each vertex
	int visited[MAX_VERTICES];	//visited flag for each vertex
	int path[MAX_VERTICES];	//record predecessor vertices for outputting paths
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
	for (int i = 1; i < n; i++)	//Find n-1 shortest paths
	{
		int min = INF;
		int u = -1;	//vertex with the smallest distance
		//Find the unvisited vertex with the smallest distance
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dist[j] < min)	
			{
				min = dist[j];
				u = j;
			}
		}
		if (u == -1)
			break;	//All reachable vertices have been visited
		visited[u] = 1;	//Mark vertex u as visited
		//Update distances for vertices adjacent to u
		for (int v = 0; v < n; v++)	
		{
			if (!visited[v] && G->edges[u][v] != INF && dist[u] + G->edges[u][v] < dist[v])	
			{
				dist[v] = dist[u] + G->edges[u][v];
				path[v] = u;
			}
		}
	}
	//Output the shortest paths and their distances
	printf("Shortest paths from vertex %d:\n", start);
	for (int i = 0; i < n; i++)
	{
		printf("To vertex %d: Distance = ", i);
		if (dist[i] == INF)
			printf("INF, Path = None\n");
		else
		{
			printf("%d, Path = ", dist[i]);
			//Reconstruct the path
			int stack[MAX_VERTICES], top = 0, temp = i;
			while (temp != -1)	
			{
				stack[top++] = temp;
				temp = path[temp];	
			}
			for (int k = top - 1; k >= 0; k--)
			{
				printf("%d ", stack[k]);
				if (k)
					printf(" -> ");	//Arrow between vertices
			}
			printf("\n");
		}
	}
}

int main() {
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
	Dijkstra(&G, start);
	return 0;
}

//Test example
/*
	Shortest paths from vertex 0:
	To vertex 0: Distance = 0, Path = 0
	To vertex 1: Distance = 7, Path = 0  -> 1
	To vertex 2: Distance = 9, Path = 0  -> 2
	To vertex 3: Distance = 20, Path = 0  -> 2  -> 3
	To vertex 4: Distance = 20, Path = 0  -> 2  -> 5  -> 4
	To vertex 5: Distance = 11, Path = 0  -> 2  -> 5
*/