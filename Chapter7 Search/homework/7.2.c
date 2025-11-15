#include <stdio.h>
#include <stdlib.h>

//Judge whether it's a BST

typedef struct Node
{
	int data;
	struct Node* lchild, * rchild;
}Node;

Node* NewNode(int data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->lchild = p->rchild = NULL;
	return p;
}

int preValue = -10000;	//Precursor values ​​used for inorder traversal checks

int IsBST(Node* root)
{
	if (root == NULL)
		return 1;
	if (!IsBST(root->lchild))
		return 0;
	if (root->data <= preValue)
		return 0;
	preValue = root->data;
	return IsBST(root->rchild);
}

int main()
{
	/*
	Construct a simple BST
			  8
            /   \
           3    10
          / \     \
         1   6     14
	*/
	Node* root = NewNode(8);
	root->lchild = NewNode(3);
	root->rchild = NewNode(10);
	root->lchild->lchild = NewNode(1);
	root->lchild->rchild = NewNode(6);
	root->rchild->rchild = NewNode(14);
	if (IsBST(root))
		printf("This binary tree is a BST\n");
	else
		printf("This binary tree isn't a BST\n");
	return 0;
}