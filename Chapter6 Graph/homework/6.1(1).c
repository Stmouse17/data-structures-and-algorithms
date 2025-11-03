#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 20
#define INF 0

typedef struct
{
	char vexs[MAXV];
	int arcs[MAXV][MAXV];
	int vexnum, arcnum;
} MGraph;

int LocateVex(MGraph* G, char v)
{
	for (int i = 0; i < G->vexnum; i++)
		if (G->vexs[i] == v)
			return i;
	return -1;
}

void InsertVex(MGraph* G, char v)
{
	if (G->vexnum >= MAXV)
		return;
	G->vexs[G->vexnum] = v;
	for (int i = 0; i <= G->vexnum; i++)
	{
		G->arcs[G->vexnum][i] = INF;
		G->arcs[i][G->vexnum] = INF;
	}
	G->vexnum++;
}

void DeleteVex(MGraph* G, char v)
{
	int index = LocateVex(G, v);
	if (index == -1)
		return;
	int count = 0;
	for (int j = 0; j < G->vexnum; j++)
		if (G->arcs[index][j] != INF)
			count++;
	for (int i = index; i < G->vexnum - 1; i++)
		G->vexs[i] = G->vexs[i + 1];
	for (int i = index; i < G->vexnum - 1; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = G->arcs[i + 1][j];
	}
	for (int j = index; j < G->vexnum - 1; j++)
	{
		for (int i = 0; i < G->vexnum; i++)
			G->arcs[i][j] = G->arcs[i][j + 1];
	}
	G->vexnum--;
	G->arcnum -= count;
}

void InsertArc(MGraph* G, char v, char w)
{
	int i = LocateVex(G, v);
	int j = LocateVex(G, w);
	if (i == -1 || j == -1) return;
	G->arcs[i][j] = 1;
	G->arcs[j][i] = 1;
	G->arcnum++;
}

void DeleteArc(MGraph* G, char v, char w)
{
	int i = LocateVex(G, v);
	int j = LocateVex(G, w);
	if (i == -1 || j == -1) return;
	G->arcs[i][j] = INF;
	G->arcs[j][i] = INF;
	G->arcnum--;
}

void PrintMGraph(MGraph* G)
{
	for (int i = 0; i < G->vexnum; i++) 
	{
		for (int j = 0; j < G->vexnum; j++)
			printf("%2d ", G->arcs[i][j]);
		printf("\n");
	}
}
int main() {
	MGraph G;
	G.vexnum = 0;
	G.arcnum = 0;
	memset(G.arcs, 0, sizeof(G.arcs));
	InsertVex(&G, 'A');
	InsertVex(&G, 'B');
	InsertVex(&G, 'C');
	InsertVex(&G, 'D');
	InsertArc(&G, 'A', 'B');
	InsertArc(&G, 'A', 'C');
	InsertArc(&G, 'B', 'D');
	PrintMGraph(&G);
	printf("\n");
	DeleteVex(&G, 'B');
	PrintMGraph(&G);
	printf("\n");
	DeleteArc(&G, 'A', 'C');
	PrintMGraph(&G);
	return 0;
}