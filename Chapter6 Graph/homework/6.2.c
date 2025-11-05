#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100

typedef struct ArcNode
{
    int adjvex;            
    struct ArcNode* next;  
} ArcNode;

typedef struct
{
    char data;     
    ArcNode* first;
} VNode;

typedef struct
{
    VNode adjList[MAXV];
    int vexnum, arcnum;  
} ALGraph;

typedef struct
{
    int data[MAXV];
    int top;
} Stack;

void InitStack(Stack* S)
{
    S->top = -1;
}

int StackEmpty(Stack S)
{
    return S.top == -1;
}

void Push(Stack* S, int x)
{
    if (S->top == MAXV - 1)
        return;
    S->data[++S->top] = x;
}

int Pop(Stack* S)
{
    if (S->top == -1)
        return -1;
    return S->data[S->top--];
}

int GetTop(Stack S)
{
    if (S.top == -1)
        return -1;
    return S.data[S.top];
}

void CreateALGraph(ALGraph* G)
{
    int i, j, k;
    char v1, v2;
    ArcNode* p;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    printf("Enter vertex data:\n");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("Vertex %d: ", i);
        scanf(" %c", &G->adjList[i].data);
        G->adjList[i].first = NULL;
    }
    printf("Enter edges (format: v1 v2):\n");
    for (k = 0; k < G->arcnum; k++)
    {
        scanf(" %c %c", &v1, &v2);
        int vi = -1, vj = -1;
        for (i = 0; i < G->vexnum; i++)
        {
            if (G->adjList[i].data == v1)
                vi = i;
            if (G->adjList[i].data == v2)
                vj = i;
        }
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = vj;
        p->next = G->adjList[vi].first;
        G->adjList[vi].first = p;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = vi;
        p->next = G->adjList[vj].first;
        G->adjList[vj].first = p;
    }
}

void DFS_NonRecursive(ALGraph G, int v)
{
    int visited[MAXV] = { 0 };
    Stack S;
    InitStack(&S);
    printf("DFS Traversal starting from vertex %c: ", G.adjList[v].data);
    Push(&S, v);
    visited[v] = 1;
    printf("%c ", G.adjList[v].data);
    while (!StackEmpty(S))
    {
        int w = GetTop(S);
        ArcNode* p = G.adjList[w].first;
        while (p && visited[p->adjvex]) // Find an unvisited adjacent vertex 
            p = p->next;
        if (p)
        {
            Push(&S, p->adjvex);
            visited[p->adjvex] = 1;
            printf("%c ", G.adjList[p->adjvex].data);
        }
        else
            Pop(&S);
    }
    printf("\n");
}

int main()
{
    ALGraph G;
    CreateALGraph(&G);
    int start;
    printf("Enter starting vertex index (0 to %d): ", G.vexnum - 1);
    scanf("%d", &start);
    DFS_NonRecursive(G, start);
    return 0;
}

//Test example:
/*
    Enter number of vertices and edges: 5 6
    Enter vertex data:
    Vertex 0: A
    Vertex 1: B
    Vertex 2: C
    Vertex 3: D
    Vertex 4: E
    Enter edges (format: v1 v2):
    A B
    A C
    B D
    B E
    C D
    D E
    Enter starting vertex index (0 to 4): 0
    DFS Traversal starting from vertex A: A C D E B
*/