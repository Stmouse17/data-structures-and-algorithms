#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int LocateVex(ALGraph* G, char v)
{
	for (int i = 0; i < G->vexnum; i++)
		if (G->vertices[i].data == v)
			return i;
	return -1;
}

void InsertVex(ALGraph* G, char v)
{
	if (G->vexnum >= MAXV)
		return;
	G->vertices[G->vexnum].data = v;
	G->vertices[G->vexnum].first = NULL;
	G->vexnum++;
}

void InsertArc(ALGraph* G, char v, char w)
{
	int i = LocateVex(G, v);
	int j = LocateVex(G, w);
	if (i == -1 || j == -1)
		return;
	ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));
	p1->adjvex = j;
	p1->next = G->vertices[i].first;
	G->vertices[i].first = p1;
	ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
	p2->adjvex = i;
	p2->next = G->vertices[j].first;
	G->vertices[j].first = p2;
	G->arcnum++;
}

void DeleteArc(ALGraph* G, char v, char w)
{
	int i = LocateVex(G, v);
	int j = LocateVex(G, w);
	if (i == -1 || j == -1)
		return;
	ArcNode* p = G->vertices[i].first, * pre = NULL;
	while (p)
	{
		if (p->adjvex == j)
		{
			if (pre)
				pre->next = p->next;
			else
				G->vertices[i].first = p->next;
			free(p);
			break;
		}
		pre = p;
		p = p->next;
	}
	p = G->vertices[j].first;
	pre = NULL;
	while (p)
	{
		if (p->adjvex == i)
		{
			if (pre)
				pre->next = p->next;
			else
				G->vertices[j].first = p->next;
			free(p);
			break;
		}
		pre = p;
		p = p->next;
	}
	G->arcnum--;
}

void DeleteVex(ALGraph* G, char v)
{
	int k = LocateVex(G, v);
	if (k == -1)
		return;
	ArcNode* p = G->vertices[k].first;
	while (p)
	{
		DeleteArc(G, v, G->vertices[p->adjvex].data);
		p = G->vertices[k].first;
	}
	for (int i = k; i < G->vexnum - 1; i++)
	{
		G->vertices[i] = G->vertices[i + 1];
	}
	for (int i = 0; i < G->vexnum - 1; i++)
	{
		ArcNode* q = G->vertices[i].first;
		while (q)
		{
			if (q->adjvex > k)
				q->adjvex--;
			q = q->next;
		}
	}
	G->vexnum--;
}

void PrintALGraph(ALGraph* G)
{
	printf("Adjacency List:\n");
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("%c: ", G->vertices[i].data);
		ArcNode* p = G->vertices[i].first;
		while (p)
		{
			printf("-> %c", G->vertices[p->adjvex].data);
			p = p->next;
		}
		printf("\n");
	}
}

int main()
{
	ALGraph G;
	G.vexnum = 0;
	G.arcnum = 0;
	InsertVex(&G, 'A');
	InsertVex(&G, 'B');
	InsertVex(&G, 'C');
	InsertVex(&G, 'D');
	InsertArc(&G, 'A', 'B');
	InsertArc(&G, 'A', 'C');
	InsertArc(&G, 'B', 'D');
	PrintALGraph(&G);
	printf("\nDelete edge A-C£º\n");
	DeleteArc(&G, 'A', 'C');
	PrintALGraph(&G);
	printf("\nDelete vertex B£º\n");
	DeleteVex(&G, 'B');
	PrintALGraph(&G);
	return 0;
}