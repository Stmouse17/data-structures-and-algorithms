#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
Given the balance factor of each node,
calculate the height of the tree.
*/

typedef struct AVLNode
{
	int data;
	int bf;	//balance factor
	struct AVLNode* lchild, * rchild;
} AVLNode, *AVLTree;

int Height(AVLTree T)
{
	int level = 0;
	AVLNode* p = T;	//Avoid using T directly, because T may be changed outside the function
	while (p)
	{
		level++;
		if (p->bf < 0)
			p = p->rchild;
		else
			p = p->lchild;
	}
	return level;
}

int main()
{
	AVLTree root = (AVLTree)malloc(sizeof(AVLNode));
	root->bf = 1;
	root->lchild = (AVLTree)malloc(sizeof(AVLNode));
	root->lchild->bf = -1;
	root->lchild->lchild = NULL;
	root->lchild->rchild = NULL;
	root->rchild = (AVLTree)malloc(sizeof(AVLNode));
	root->rchild->bf = 0;
	root->rchild->lchild = NULL;
	root->rchild->rchild = NULL;
	int height = Height(root);
	printf("Height of the AVL tree: %d\n", height);
	// Free allocated memory
	free(root->lchild);
	free(root->rchild);
	free(root);
	return 0;
}