#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int data;
    int count;  // count of duplicates
    struct BSTNode* lchild, * rchild;
} BSTNode, *BSTree;

BSTree InsertOrCount(BSTree T, int key)
{
    if (!T)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->count = 1;
        T->lchild = T->rchild = NULL;
        return T;
    }
    if (T->data == key)
        T->count++;
    else if (key < T->data)
        T->lchild = InsertOrCount(T->lchild, key);
    else
        T->rchild = InsertOrCount(T->rchild, key);
    return T;
}

void InOrderPrint(BSTree T)
{
    if (T)
    {
        InOrderPrint(T->lchild);
        printf("Value: %d, Count: %d\n", T->data, T->count);
        InOrderPrint(T->rchild);
    }
}

int main()
{
    BSTree tree = NULL;
    int values[] = { 5, 3, 7, 3, 5, 8, 5 };
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
    {
        tree = InsertOrCount(tree, values[i]);
    }
    InOrderPrint(tree);
    // Free memory (not shown here for brevity)
    return 0;
}