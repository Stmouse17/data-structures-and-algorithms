#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define MAXEDGE 100
#define TRUE 1
#define FALSE 0

typedef struct EdgeNode 
{
	int adjvex;
	struct EdgeNode* next;
	int weight;
}EdgeNode;

typedef struct VexNode 
{
	char data;	//event
	EdgeNode* firstedge;
	int in; // in-degree
}VexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList vertices;
	int vexnum, edgenum;
}ALGraph;

void CreateAOEGraph(ALGraph* G)
{
    int i, j, k, w;
    EdgeNode* e;
    printf("Enter the number of events and activities:");
    scanf("%d %d", &G->vexnum, &G->edgenum);
    for (i = 0; i < G->vexnum; i++)
    {
        printf("Enter event %d:", i);
        getchar(); // consume newline
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstedge = NULL;
        G->vertices[i].in = 0;
    }
    printf("Enter the activities (start_event end_event duration):\n");
    for (k = 0; k < G->edgenum; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->weight = w;
        e->next = G->vertices[i].firstedge;
        G->vertices[i].firstedge = e;
        G->vertices[j].in++;
    }
}

int TopologicalOrder(ALGraph* G, int* topo, int* ve)  
{
    int i, count = 0;   
    int* stack = (int*)malloc(G->vexnum * sizeof(int));
    int top = 0;
    EdgeNode* e;
    for (i = 0; i < G->vexnum; i++)
    {
        ve[i] = 0;
        if (G->vertices[i].in == 0)
            stack[top++] = i;
    }
    while (top != 0)
    {
        i = stack[--top];
        topo[count++] = i;
        for (e = G->vertices[i].firstedge; e; e = e->next)
        {
            if (--G->vertices[e->adjvex].in == 0)
                stack[top++] = e->adjvex;
            if (ve[i] + e->weight > ve[e->adjvex])
                ve[e->adjvex] = ve[i] + e->weight;
        }
    }
    free(stack);
    if (count < G->vexnum)
    {
        printf("The graph has a cycle!\n");
        return FALSE;
    }
    else
        return TRUE;
}

void CriticalPath(ALGraph* G)
{
    int topo[MAXVEX];   // topological order
    int ve[MAXVEX];     // earliest event time
    int vl[MAXVEX];     // latest event time
    int i, k;           
    EdgeNode* e;
    if (!TopologicalOrder(G, topo, ve))
        return;
    for (i = 0; i < G->vexnum; i++)
        vl[i] = ve[G->vexnum - 1];  // initialize vl to the maximum ve
    for (i = G->vexnum - 1; i >= 0; i--)    // reverse topological order
    {
        for (e = G->vertices[topo[i]].firstedge; e; e = e->next)    // traverse all outgoing edges
        {
            if (vl[e->adjvex] - e->weight < vl[topo[i]])
                vl[topo[i]] = vl[e->adjvex] - e->weight;
        }
    }
    printf("\nThe earliest(ve) and latest(vl) occurrence times of event vertices:\n");
    for (i = 0; i < G->vexnum; i++)
        printf("Event %c: ve=%2d, vl=%2d\n", G->vertices[i].data, ve[i], vl[i]);
    printf("\nThe earliest(e) and latest(l) start times of the activity:\n");
    printf("activity\tstart->end\tduration\t e \t l \tIsCritical\n");
    for (i = 0; i < G->vexnum; i++)
    {
        for (e = G->vertices[i].firstedge; e; e = e->next)  // traverse all outgoing edges
        {
            int ee = ve[i];
            int el = vl[e->adjvex] - e->weight;
            printf("  %c%c\t\t %c->%c\t\t   %d\t\t%d\t%d\t",
                G->vertices[i].data, G->vertices[e->adjvex].data,
                G->vertices[i].data, G->vertices[e->adjvex].data,
                e->weight, ee, el);
            if (ee == el)   // critical activity(no rest)
                printf(" Yes\n");
            else
                printf(" No\n");
        }
    }
}

int main()
{
    ALGraph G;
    CreateAOEGraph(&G);
    CriticalPath(&G);
    return 0;
}

//Test case
/*
    Enter the number of events and activities:6 8
    Enter event 0:A
    Enter event 1:B
    Enter event 2:C
    Enter event 3:D
    Enter event 4:E
    Enter event 5:F
    Enter the activities (start_event end_event duration):
    0 1 3
    0 2 2
    1 3 2
    1 4 3
    2 3 4
    3 5 3
    4 5 2
    2 4 1

    The earliest(ve) and latest(vl) occurrence times of event vertices:
    Event A: ve= 0, vl= 0
    Event B: ve= 3, vl= 4
    Event C: ve= 2, vl= 2
    Event D: ve= 6, vl= 6
    Event E: ve= 6, vl= 7
    Event F: ve= 9, vl= 9

    The earliest(e) and latest(l) start times of the activity:
    activity        start->end      duration         e       l      IsCritical
     AC             A->C              2            0       0        Yes
     AB             A->B              3            0       1        No
     BE             B->E              3            3       4        No
     BD             B->D              2            3       4        No
     CE             C->E              1            2       6        No
     CD             C->D              4            2       2        Yes
     DF             D->F              3            6       6        Yes
     EF             E->F              2            6       7        No
*/




