#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode
{
	int key;
	int height;
	struct AVLNode* left;
	struct AVLNode* right;
} AVLNode;

int getHeight(AVLNode* node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

int getBalance(AVLNode* node)
{
	if (node == NULL)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

int getMax(int a, int b)
{
	return (a > b) ? a : b;
}

AVLNode* rightRotate(AVLNode* y)	
{
	AVLNode* x = y->left;
	AVLNode* T2 = x->right;
	x->right = y;	
	y->left = T2;	
	y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
	return x;
}

AVLNode* leftRotate(AVLNode* x)
{
	AVLNode* y = x->right;
	AVLNode* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}

AVLNode* InsertNode(AVLNode* node, int key)
{
	if (node == NULL)
	{
		AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
		newNode->key = key;
		newNode->left = newNode->right = NULL;
		newNode->height = 1;
		return newNode;
	}
	if (key < node->key)
		node->left = InsertNode(node->left, key);
	else if (key > node->key)
		node->right = InsertNode(node->right, key);
	else
		return node;
	node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)	// LL case
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)	// RR case
		return leftRotate(node);
	if (balance > 1 && key > node->left->key)	// LR case
	{
		node->left = leftRotate(node->left);	// First left rotate the left child
		return rightRotate(node);				// Then right rotate the node
	}
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);	// First right rotate the right child
		return leftRotate(node);					// Then left rotate the node
	}
	return node;
}

void InOrderTraversal(AVLNode* root)
{
	if (root != NULL)
	{
		InOrderTraversal(root->left);
		printf("%d ", root->key);
		InOrderTraversal(root->right);
	}
}

int main()
{
	AVLNode* root = NULL;
	int data[] = { 10, 20, 30, 40, 50, 25 };
	int n = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
		root = InsertNode(root, data[i]);
	}
	printf("\n\nsequence from smallest to largest£©: ");
	InOrderTraversal(root);
	printf("\n");
	return 0;
}

//I spent an afternoon studying this algorithm.