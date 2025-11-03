#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// using binary list to implement binary search tree

typedef struct BSTNode
{
	int key;
	struct BSTNode* left, * right;
}BSTNode, *BSTree;

BSTNode* CreateNode(int key)
{
	BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

BSTree InsertBST(BSTree root, int key)
{
	if (root == NULL)
		root = CreateNode(key);
	else if (key < root->key)
		root->left = InsertBST(root->left, key);
	else if (key > root->key)
		root->right = InsertBST(root->right, key);
	return root;
}

BSTNode* SearchBST(BSTree root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	else if (key < root->key)
		return SearchBST(root->left, key);
	else
		return SearchBST(root->right, key);
}

BSTNode* FindMin(BSTree root)
{
	while (root && root->left != NULL)
		root = root->left;
	return root;
}

BSTree DeleteBST(BSTree root, int key)
{
	if (root == NULL)
		return NULL;
	if (key < root->key)
		root->left = DeleteBST(root->left, key);
	else if (key > root->key)
		root->right = DeleteBST(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			BSTNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			BSTNode* temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			BSTNode* temp = FindMin(root->right);
			root->key = temp->key;
			root->right = DeleteBST(root->right, temp->key);
		}
	}
	return root;
}

void InOrderTraversal(BSTree root)
{
	if (root != NULL)
	{
		InOrderTraversal(root->left);
		printf("%d ", root->key);
		InOrderTraversal(root->right);
	}
}

int main() {
	BSTree tree = NULL;
	int keys[] = { 45, 24, 53, 12, 37, 93, 81 };
	int n = sizeof(keys) / sizeof(keys[0]);
	printf("Constructing BST \n");
	for (int i = 0; i < n; i++) {
		tree = InsertBST(tree, keys[i]);
	}
	printf("In-order Traversal of BST: \n");
	InOrderTraversal(tree);
	printf("\n");
	// Search for a node
	int target = 37;
	BSTNode* result = SearchBST(tree, target);
	if (result)
		printf("Search Successful: %d\n", result->key);
	else
		printf("Search Failed");
	// Insert a node
	tree = InsertBST(tree, 66);
	InOrderTraversal(tree);
	printf("\n");
	// Delete a node
	tree = DeleteBST(tree, 24);
	InOrderTraversal(tree);
	printf("\n");
	return 0;
}