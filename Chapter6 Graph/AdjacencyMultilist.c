#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20

//Suitable to undirected graph

typedef struct EBox
{
	int ivex, jvex;
	struct EBox* ilink, * jlink;
}EBox;

typedef struct VexBox
 {
	char data;
	EBox* firstedge;
} VexBox;

typedef struct
{
	VexBox adjmulist[MAXV];
	int vexnum, edgenum;
}AMLGraph;

int LocateVex_AML(AMLGraph* G, char* v)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->adjmulist[i].data == v)
			return i;
	}
	return -1;
}

void CreateAMLGraph(AMLGraph* G)
{
	char v1, v2;
	printf("Enter number of vertices and edges: ");
	scanf("%d %d", &G->vexnum, &G->edgenum);
	printf("Enter vertex information: ");
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf(" %c", &G->adjmulist[i].data);
		G->adjmulist[i].firstedge = NULL;
	}
	printf("Enter edege information (format: v1 v2):\n");
	for (int k = 0; k < G->edgenum; k++)
	{
		scanf(" %c %c", &v1, &v2);
		int i = LocateVex_AML(G, v1);
		int j = LocateVex_AML(G, v2);
		EBox* p = (EBox*)malloc(sizeof(EBox));
		p->ivex = i; p->jvex = j;
		p->ilink = G->adjmulist[i].firstedge;
		p->jlink = G->adjmulist[i].firstedge;
		G->adjmulist[i].firstedge = G->adjmulist[j].firstedge = p;
	}
}

int visited[MAXV];

void DFS_AML(AMLGraph* G, int v)
{
	printf("%c ", G->adjmulist[v].data);
	visited[v] = 1;
	for (EBox* p = G->adjmulist[v].firstedge; p; )
	{
		int w = (p->ivex == v) ? p->jvex : p->ivex;
		if (!visited[w])
			DFS_AML(G, w);
		p = (p->ivex == v) ? p->ilink : p->jlink;
	}
}

int main() {
	AMLGraph G;
	CreateAMLGraph(&G);
	printf("DFS: ");
	for (int i = 0; i < G.vexnum; i++) 
		visited[i] = 0;
	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i]) DFS_AML(&G, i);
	printf("\n");
	return 0;
}

//Test example
/*
	Enter number of vertices and edges: 4 4
	Enter vertex information: A B C D
	Enter edege information (format: v1 v2):
	A B
	A C
	B D
	C D
	DFS: A C D B
*/

