#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define TRUE 1
#define FALSE 0

//adjacency List
typedef struct ArcNode
{
	int adjvex;	// The index of the adjacent vertex
	struct ArcNode* next;
}ArcNode;

typedef struct VertexNode
{
	char data;
	int in;	// The in-degree of the vertex
	ArcNode* firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList vertices;
	int vexnum, edgenum;
}ALGraph;

void CreateALGraph(ALGraph* G)
{
	int i, j, k;
	ArcNode* e;
	printf("Enter the number of vertices and edges(use ' ' to separate):");
	scanf("%d %d", &G->vexnum, &G->edgenum);
	for (i = 0; i < G->vexnum; i++)	// Initialize vertices
	{
		printf("Enter vertex %d data:", i);
		getchar(); // To consume the newline character
		// Why use getchar () here?
		// Because when you input the number of vertices and edges, you press Enter, which leaves a newline character in the input buffer.
		// I see, Thank you£¡
		scanf("%c", &G->vertices[i].data);
		G->vertices[i].in = 0;
		G->vertices[i].firstedge = NULL;
	}
	printf("Enter the starting and ending vertex indices for each edge:\n");
	for (k = 0; k < G->edgenum; k++)
	{
		scanf("%d %d", &i, &j);
		e = (ArcNode*)malloc(sizeof(ArcNode));
		e->adjvex = j;
		e->next = G->vertices[i].firstedge;
		G->vertices[i].firstedge = e;
		G->vertices[j].in++;
	}
}

int TopologicalSort(ALGraph* G)
{
	int i, k, gettop;
	ArcNode* e;
	int count = 0;	// Count of output vertices
	int* stack = (int*)malloc(G->vexnum * sizeof(int));
	int top = 0;	// Stack top pointer
	for (i = 0; i < G->vexnum; i++)	// Initialize stack with vertices of in-degree 0
		if (G->vertices[i].in == 0)
			stack[top++] = i;
	printf("The topological order is:\n");
	while (top != 0)
	{
		gettop = stack[--top];
		printf("%c ", G->vertices[gettop].data);
		count++;
		for (e = G->vertices[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--G->vertices[k].in))	// If in-degree becomes 0, push onto stack
				stack[top++] = k;
		}
	}
	free(stack);
	if (count < G->vexnum)
	{
		printf("There is a cycle in the graph!\n");
		return FALSE;
	}
	else
		return TRUE;
}

int main()
{
	ALGraph G;
	CreateALGraph(&G);
	TopologicalSort(&G);
	return 0;
}

//Test case
/*
	Enter the number of vertices and edges(use ' ' to separate):6 6
	Enter vertex 0 data:A
	Enter vertex 1 data:B
	Enter vertex 2 data:C
	Enter vertex 3 data:D
	Enter vertex 4 data:E
	Enter vertex 5 data:F
	Enter the starting and ending vertex indices for each edge:
	0 1
	0 2
	1 3
	2 3
	3 4
	4 5
	The topological order is:
	A B C D E F
*/