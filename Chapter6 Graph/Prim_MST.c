#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXV 100
#define INF INT_MAX

typedef struct
{
	int vexnum;
	int edgenum;
	int edges[MAXV][MAXV];
}MGraph;

void CreateGraph(MGraph* G, int vexnum, int edgenum)
{
	G->vexnum = vexnum;
	G->edgenum = edgenum;
	int u, v, w;
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
			G->edges[i][j] = (i == j) ? 0 : INF;
	}
	printf("Enter edges (format: start_vertex end_vertex weight): \n");
	for (int k = 0; k < G->edgenum; k++)
	{
		scanf("%d %d %d", &u, &v, &w);
		G->edges[u][v] = w;
		G->edges[v][u] = w;
	}
}

void Prim(MGraph G, int start)	
{
	int lowcost[MAXV];	//lowcost stores the minimum cost to connect vertexes outside the MST to the MST
	int visited[MAXV];	//visited[i] = 1 means vertex i is included in the MST
	int parent[MAXV];	//parent[i] stores the parent vertex of vertex i in the MST
	for (int i = 0; i < G.vexnum; i++)	
	{
		lowcost[i] = G.edges[start][i];
		visited[i] = 0; 
		parent[i] = start;
	}
	visited[start] = 1;
	printf("Edges in the Minimum Spanning Tree:\n");
	for (int i = 1; i < G.vexnum; i++)	//MST has vexnum - 1 edges
	{
		int min = INF;	//find the vertex with the minimum lowcost
		int k = -1;		//k stores the index of that vertex
		for (int j = 0; j < G.vexnum; j++)	//search all vertexes
		{
			if (!visited[j] && lowcost[j] < min)	//if vertex j is not in MST and has a smaller lowcost
			{
				min = lowcost[j];
				k = j;
			}
		}
		if (k == -1)	//no more vertex can be added to MST
			return;
		printf("(%d, %d) weight: %d\n", parent[k], k, min);
		visited[k] = 1;
		for (int j = 0; j < G.vexnum; j++)	
		{
			if (!visited[j] && G.edges[k][j] < lowcost[j])	
			{
				lowcost[j] = G.edges[k][j];
				parent[j] = k;
			}
		}
	}
}

int main()
{
	MGraph G;
	int vexnum, edgenum;
	printf("Enter number of vertices and edges: ");
	scanf("%d %d", &vexnum, &edgenum);
	CreateGraph(&G, vexnum, edgenum);
	Prim(G, 0);
	return 0;
}

//Test example
/*
	Enter number of vertices and edges: 6 10
	Enter edges (format: start_vertex end_vertex weight):
	0 1 6
	0 2 1
	0 3 5
	1 2 5
	1 4 3
	2 3 5
	2 4 6
	2 5 4
	3 5 2
	4 5 6
	Edges in the Minimum Spanning Tree:
	(0, 2) weight: 1
	(2, 5) weight: 4
	(5, 3) weight: 2
	(2, 1) weight: 5
	(1, 4) weight: 3
*/


