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
} MGraph;

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

typedef struct
{
	int u, v;	//The two vertices of an edge
	int w;		//The weight of an edge
}Edge;

//Find the root of the heap 
int FindRoot(int parent[], int x)
{
	if (parent[x] != x)
		parent[x] = FindRoot(parent, parent[x]);	//Recursive to the end of the root
	return parent[x];
}

void UnionSet(int parent[], int x, int y)
{
	int x_root = FindRoot(parent, x);
	int y_root = FindRoot(parent, y);
	if (x_root != y_root)	//vertex_x and vertex_y aren't in the same set
		//Connect vertex_x and vertex_y to form an edge to merge two sets
		parent[y_root] = x_root;	
}

void Kruskal(MGraph G)
{
	Edge UDEdges[MAXV * MAXV];	//Store all undirected edges
	int k = 0;	//undirected edgenum
	//Extract all edges of a triangle from the adjacency matrix
	for (int i = 0; i < G.vexnum; i++)
		for (int j = i + 1; j < G.vexnum; j++)
			if (G.edges[i][j] != INF)
				UDEdges[k++] = (Edge){ i, j, G.edges[i][j] };
	for (int i = 0; i < k - 1; i++)	//BubbleSort
		for (int j = 0; j < k - 1 - i; j++)
			if (UDEdges[j].w > UDEdges[j + 1].w)
			{
				Edge tmp = UDEdges[j];
				UDEdges[j] = UDEdges[j + 1];
				UDEdges[j + 1] = tmp;
			}
	int parent[MAXV];	//Store the predecessor vertices of vertex_i 
	for (int i = 0; i < G.vexnum; i++)	//Initialize array parent[]
		parent[i] = i;	//At the beginning, all vertices independently form a heap(set), with the root being itself
	printf("Edges in the Minimum Spanning Tree:\n");
	int count = 0;	//The number of selected edges
	//Traverse all edges in the UDEdges[], select G.vexnum - 1 edges to form the MST
	for (int i = 0; i < k && count < G.vexnum - 1; i++)
	{
		int u = UDEdges[i].u;
		int v = UDEdges[i].v;
		int w = UDEdges[i].w;
		int u_root = FindRoot(parent, u);
		int v_root = FindRoot(parent, v);
		if (u != v)	//vertex_u and vertex_v aren't in the same set
		{
			printf("(%d, %d) weight: %d\n", u, v, w);	//Add this edge to the MST
			UnionSet(parent, u_root, v_root);
			count++;
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
	Kruskal(G);
	return 0;
}

//Test example (MSVC Visual Studio 2022)
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
	(3, 5) weight: 2
	(1, 4) weight: 3
	(2, 5) weight: 4
	(0, 3) weight: 5
*/


