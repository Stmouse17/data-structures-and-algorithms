#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

BiTNode* CreateTree()
{
    // create a binary tree as below:
    //         A
    //        / \
    //       B   C
    //      /   / \
    //     D   E   F
    BiTree A = (BiTree)malloc(sizeof(BiTNode));
    BiTree B = (BiTree)malloc(sizeof(BiTNode));
    BiTree C = (BiTree)malloc(sizeof(BiTNode));
    BiTree D = (BiTree)malloc(sizeof(BiTNode));
    BiTree E = (BiTree)malloc(sizeof(BiTNode));
    BiTree F = (BiTree)malloc(sizeof(BiTNode));
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

void PrintPath(char path[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%c ", path[i]);
    printf("\n");
}

void PrintRootToLeaf(BiTree T, char path[], int len)
{
    if (!T)
        return;
    path[len++] = T->data;
    if (!T->lchild && !T->rchild)
        PrintPath(path, len);
    PrintRootToLeaf(T->lchild, path, len);
    PrintRootToLeaf(T->rchild, path, len);
}          

int main()
{
    BiTree T = CreateTree();
    char path[100];
    PrintRootToLeaf(T, path, 0);
    return 0;
}
