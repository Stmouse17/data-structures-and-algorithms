#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20
#define INFINITY 65535

typedef struct
{
	char vexs[MAXV];
	int arcs[MAXV][MAXV];
	int vexnum, arcnum;
}MGraph;

int LocateVex(MGraph* G, char v)
{
	for (int i = 0; i < G->vexnum; i++)
		if (G->vexs[i] == v)
			return i;
	return -1;
}

void CreateMGraph(MGraph* G)
{
	char v1, v2;
	printf("Enter number of vertices and edges: ");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	printf("Enter vertex information: ");
	for (int i = 0; i < G->vexnum; i++)
		scanf(" %c", &G->vexs[i]);
	for (int i = 0; i < G->vexnum; i++)
		for (int j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = (i == j) ? 0 : INFINITY;
	printf("Enter edege information (format: v1 v2):\n");
	for (int k = 0; k < G->arcnum; k++)
	{
		scanf(" %c %c", &v1, &v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G->arcs[i][j] = G->arcs[j][i] = 1; // Undirected graph
	}
}

int visited[MAXV];

void DFS_MGraph(MGraph* G, int v)	//v is the index of the starting vertex
{
	printf("%c ", G->vexs[v]);
	visited[v] = 1;
	for (int j = 0; j < G->vexnum; j++)
		if (G->arcs[v][j] != INFINITY && !visited[j])
			DFS_MGraph(G, j);
}

void DFSTraverse(MGraph* G)	
{
	for (int v = 0; v < G->vexnum; v++)
		visited[v] = 0;
	for (int v = 0; v < G->vexnum; v++)
		if (!visited[v])
			DFS_MGraph(G, v);
}

void BFS_MGraph(MGraph* G, int v)
{
	int queue[MAXV], front = 0, rear = 0;
	printf("%c ", G->vexs[v], 1);
	visited[v] = 1;
	queue[rear++] = v;
	while (front != rear)
	{
		int i = queue[front++];
		for (int j = 0; j < G->vexnum; j++)
		{
			if (G->arcs[i][j] != INFINITY && !visited[j])
			{
				printf("%c ", G->vexs[j]);
				visited[j] = 1;
				queue[rear++] = j;
			}
		}
	}
}

int main()
{
	MGraph G;
	CreateMGraph(&G);
	printf("DFS: ");
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	DFS_MGraph(&G, 0);
	printf("\nBFS: ");
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	BFS_MGraph(&G, 0);
	printf("\n");
	return 0;
}