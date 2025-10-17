#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20

typedef struct ArcNode
{
	int adjvex;	// Index of the adjacent vertex
	struct ArcNode* next;
}ArcNode;

typedef struct VNode
{
	char data;
	ArcNode* first;
}VNode, AdjList[MAXV];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

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

void DFS_AL(ALGraph* G, int v)
{
	printf("%c ", G->vertices[v].data);
	visited[v] = 1;
	for (ArcNode* p = G->vertices[v].first; p; p = p->next)
	{       
		if (!visited[p->adjvex])
			DFS_AL(G, p->adjvex);
	}
}

void BFS_AL(ALGraph* G, int v)
{
	int queue[MAXV], front = 0, rear = 0;
	printf("%c ", G->vertices[v].data);
	visited[v] = 1;
	queue[rear++] = v;
	while (front != rear)
	{
		int i = queue[front++];
		for (ArcNode* p = G->vertices[i].first; p; p = p->next)
		{
			if (!visited[p->adjvex])
			{
				printf("%c ", G->vertices[p->adjvex].data);
				visited[p->adjvex] = 1;
				queue[rear++] = p->adjvex;
			}
		}
	}
}

int main()
{
	ALGraph G;
	CreateALGraph(&G);
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	printf("DFS: ");
	//Considering that this graph may be a non-connected graph
	//It's necessary traverse all nodes
	for (int i = 0; i < G.vexnum; i++)	
	{
		if (!visited[i])
			DFS_AL(&G, i);
	}
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	printf("\nBFS: ");
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			BFS_AL(&G, i);
	}
	printf("\n");
	return 0;
}

//Test example
/*
	Enter number of vertices and edges: 4 4
	Enter vertex data: A B C D
	Enter edges (format: v1 v2):
	A B
	A C
	C D
	B D
	DFS: A C D B
	BFS: A C B D
*/
//The difference between the output of adjacency matrix and C and D transposition
//is due to the use od headinsertion method in CreateALGraph to construct undirected graph