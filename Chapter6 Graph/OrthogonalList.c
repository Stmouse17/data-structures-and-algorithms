#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20

//Suitable for directed graph

typedef struct ArcBox
{
	int tailvex, headvex;
	struct ArcBox* hlink, * tlink;
}ArcBox;

typedef struct VexNode
{
	char data;
	ArcBox* firstin, * firstout;
}VexNode_OL;

typedef struct
{
	VexNode_OL xlist[MAXV];
	int vexnum, arcnum;
}OLGraph;

int LocateVex_OL(OLGraph* G, char v)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->xlist[i].data == v)
			return i;
	}
	return -1;
}

void CreateOLGraph(OLGraph* G)
{
	char v1, v2;
	printf("Enter number of vertices and directed edges: ");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	printf("Enter vertex information: ");
	for (int i = 0; i < G->vexnum; i++)
	{
		scanf(" %c", &G->xlist[i].data);
		G->xlist[i].firstin = G->xlist[i].firstout = NULL;
	}
	printf("Enter directed edege information (format: v1->v2):\n");
	for (int k = 0; k < G->arcnum; k++)
	{
		scanf(" %c %c", &v1, &v2);
		int i = LocateVex_OL(G, v1);
		int j = LocateVex_OL(G, v2);
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = i; p->headvex = j;
		p->tlink = G->xlist[i].firstout;	//HeadInsert of adjacency list
		p->hlink = G->xlist[j].firstin;		//HeadInsert of inverse adjacency list
		G->xlist[i].firstout = p;
		G->xlist[j].firstin = p;
	}
}

int visited[MAXV];

void DFS_OL(OLGraph* G, int v)
{
	printf("%c ", G->xlist[v].data);
	visited[v] = 1;
	for (ArcBox* p = G->xlist[v].firstout; p; p = p->tlink)
	{
		if (!visited[p->headvex])
			DFS_OL(G, p->headvex);
	}
}

int main()
{
	OLGraph G;
	CreateOLGraph(&G);
	for (int i = 0; i < MAXV; i++)
		visited[i] = 0;
	printf("DFS: ");
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			DFS_OL(&G, i);
	}
	printf("\n");
	return 0;
}

//Test example
/*
	Enter number of vertices and directed edges: 4 4
	Enter vertex information: A B C D
	Enter directed edege information (format: v1->v2):
	A B
	A C
	B D
	C D
	DFS: A C D B
*/
