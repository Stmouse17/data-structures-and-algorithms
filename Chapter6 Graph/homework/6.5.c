/*
Use the adjacency table storage structure
to write an algorithm to determine
whether there is a simple path
with a length of k between two arbitrarily
given vertices in the unoriented graph.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* next;
} ArcNode;

typedef struct VNode
{
	char data;
	ArcNode* first;
} VNode, AdjList[MAXV];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
} ALGraph;

int LocateVex_AL(ALGraph* G, char v)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->vertices[i].data == v)
			return i;
	}
	return -1;
}

void CreateALGraph(ALGraph* G)
{
	char v1, v2;
	printf("Enter number of vertices and edges: ");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	printf("Enter vertex data: ");
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf(" %c", &G->vertices[i].data);
		G->vertices[i].first = NULL;
	}
	printf("Enter edges (format: v1 v2):\n");
	for (int k = 0; k < G->arcnum; k++)
	{
		scanf(" %c %c", &v1, &v2);
		int i = LocateVex_AL(G, v1);
		int j = LocateVex_AL(G, v2);
		ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->next = G->vertices[i].first;	//HeadInsert
		G->vertices[i].first = p1;
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = i;
		p2->next = G->vertices[j].first;	//HeadInsert
		G->vertices[j].first = p2;	//Undirected graph
	}
}

int visited[MAXV];

int PathLen_k(ALGraph* G, int i, int j, int k)
{
	if (i == j && k == 0)
		return 1;
	else if (k > 0)
	{
		visited[i] = 1;
		for (ArcNode* p = G->vertices[i].first; p; p = p->next)
		{
			int v = p->adjvex;
			if (!visited[v])
				if (PathLen_k(G, v, j, k - 1))
					return 1;
		}
		visited[i] = 0;	//Backtrack, because this vertex may be used in other paths
	}
	return 0;
}

int main()
{
	ALGraph G;
	CreateALGraph(&G);
	char start, end;
	int k;
	printf("Enter start vertex, end vertex and path length k: ");
	scanf(" %c %c %d", &start, &end, &k);
	int i = LocateVex_AL(&G, start);
	int j = LocateVex_AL(&G, end);
	for (int m = 0; m < G.vexnum; m++)
		visited[m] = 0;
	if (PathLen_k(&G, i, j, k))
		printf("There is a simple path of length %d between %c and %c.\n", k, start, end);
	else
		printf("There is no simple path of length %d between %c and %c.\n", k, start, end);
	return 0;
}

//Test example
/*
	Enter number of vertices and edges: 5 6
	Enter vertex data: A B C D E
	Enter edges (format: v1 v2):
	A B
	A C
	B D
	C D
	C E
	D E
	Enter start vertex, end vertex and path length k: A E 3
	There is a simple path of length 3 between A and E.
*/

