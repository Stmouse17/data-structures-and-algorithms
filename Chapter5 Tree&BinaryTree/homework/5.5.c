#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct 
{
	char data;
	struct BTNode* lchild, * rchild;
}BTNode, *BiTree;

typedef struct
{
	BTNode* data[MAXSIZE];
	int front, rear;
}Queue;

void InitQueue(Queue* q)
{
	q->front = q->rear = 0;
}

int IsEmpty(Queue* q)
{
	return q->front == q->rear;
}

void EnQueue(Queue* q, BTNode* t)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("Queue is full!\n");
		return;
	}
	q->data[q->rear++] = t;
}

 BTNode* DeQueue(Queue* q)
{
	if (IsEmpty(q))
	{
		printf("Queue is empty!\n");
		return;
	}
	return q->data[q->front++];
}

 //The function is used to construct a usecase binary tree

BTNode* CreateTree() 
{
    // create a binary tree as below:
    //         A
    //        / \
    //       B   C
    //      /   / \
    //     D   E   F
    BiTree A = (BiTree)malloc(sizeof(BTNode));
    BiTree B = (BiTree)malloc(sizeof(BTNode));
    BiTree C = (BiTree)malloc(sizeof(BTNode));
    BiTree D = (BiTree)malloc(sizeof(BTNode));
    BiTree E = (BiTree)malloc(sizeof(BTNode));
    BiTree F = (BiTree)malloc(sizeof(BTNode));
    A->data = 'A'; B->data = 'B'; C->data = 'C';
    D->data = 'D'; E->data = 'E'; F->data = 'F';
    A->lchild = B; A->rchild = C;
    B->lchild = D; B->rchild = NULL;
    C->lchild = E; C->rchild = F;
    D->lchild = D->rchild = NULL;
    E->lchild = E->rchild = NULL;
    F->lchild = F->rchild = NULL;
    return A;
 }

int MaxWidth(BiTree T)
{
    if (T == NULL)
        return 0;
    Queue q;
    InitQueue(&q);
    EnQueue(&q, T);
    int MaxWidth = 0;
    while (!IsEmpty(&q))
    {
        int LevelWidth = (q.rear - q.front + MAXSIZE) % MAXSIZE;    // number of nodes at current level
        if (LevelWidth > MaxWidth)
            MaxWidth = LevelWidth;  //update MaxWidth if current level width is greater
        for (int i = 0; i < LevelWidth; i++)
        {
            BiTree node = DeQueue(&q);
            if (node->lchild)
                EnQueue(&q, node->lchild);
            if (node->rchild)
                EnQueue(&q, node->rchild);
        }
    }
    return MaxWidth;
}

int main()
{
    BiTree T = CreateTree();
    int width = MaxWidth(T);
    printf("MaxWidth = %d\n", width);
    return 0;
}

