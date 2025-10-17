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

/*
  The idea of subsequent traversal
  Traverse the two left and right subtrees under the root node first to obtain the longest path under tne secondary nodes
  Then compare the sum of the longest paths of the left and right subtrees with the current maximum value
  Using the number of edges to represent the longest path length
*/

int LongestPath(BiTree T, int* maxlen)
{
    if (!T)
        return 0;
    int left = LongestPath(T->lchild, maxlen);  
    int right = LongestPath(T->rchild, maxlen); 
    if (left + right > *maxlen)                
        *maxlen = left + right;
    return (left > right ? left : right) + 1;
}

int main()
{
    BiTree T = CreateTree();
    int max_path_len = 0;
    LongestPath(T, &max_path_len);
    printf("The length of the longest path is: %d\n", max_path_len);   
    return 0;
}