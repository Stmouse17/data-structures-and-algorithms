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

int visited[MAXV]; // Visited array
int found = 0; // Flag to indicate if path is found

void DFS(ALGraph* G, int v, int j)
{
	visited[v] = 1; // Mark the current vertex as visited
	if (v == j)
	{
		found = 1; // Path found
		return;
	}
	ArcNode* p = G->vertices[v].first;
	while (p != NULL && !found)
	{
		if (!visited[p->adjvex])
		{
			DFS(G, p->adjvex, j);
		}
		p = p->next;
	}
}

int isPath(ALGraph* G, int i, int j)
{
	int k;
	for (k = 0; k < G->vexnum; k++)
		visited[k] = 0; // Initialize visited array
	found = 0; // Reset found flag
	DFS(G, i, j); // Start DFS from vertex i
	return found; // Return whether path is found
}

int main()
{
	ALGraph G;
	int i, j;
	// Example graph initialization
	G.vexnum = 5;
	G.arcnum = 6;
	G.vertices[0].data = 'A'; G.vertices[0].first = NULL;
	G.vertices[1].data = 'B'; G.vertices[1].first = NULL;
	G.vertices[2].data = 'C'; G.vertices[2].first = NULL;
	G.vertices[3].data = 'D'; G.vertices[3].first = NULL;
	G.vertices[4].data = 'E'; G.vertices[4].first = NULL;
	// Manually adding edges for demonstration
	ArcNode* p;
	p = (ArcNode*)malloc(sizeof(ArcNode)); p->adjvex = 1; p->next = G.vertices[0].first; G.vertices[0].first = p; // A->B
	p = (ArcNode*)malloc(sizeof(ArcNode)); p->adjvex = 2; p->next = G.vertices[0].first; G.vertices[0].first = p; // A->C
	p = (ArcNode*)malloc(sizeof(ArcNode)); p->adjvex = 3; p->next = G.vertices[1].first; G.vertices[1].first = p; // B->D
	p = (ArcNode*)malloc(sizeof(ArcNode)); p->adjvex = 4; p->next = G.vertices[2].first; G.vertices[2].first = p; // C->E
	p = (ArcNode*)malloc(sizeof(ArcNode)); p->adjvex = 3; p->next = G.vertices[4].first; G.vertices[4].first = p; // E->D
	p = (ArcNode*)malloc(sizeof(ArcNode)); p->adjvex = 0; p->next = G.vertices[3].first; G.vertices[3].first = p; // D->A
	// Check if there is a path from vertex 0 (A) to vertex 3 (D)
	i = 0; // A
	j = 3; // D
	if (isPath(&G, i, j))
		printf("There is a path from %c to %c.\n", G.vertices[i].data, G.vertices[j].data);
	else
		printf("There is no path from %c to %c.\n", G.vertices[i].data, G.vertices[j].data);
	return 0;
}
