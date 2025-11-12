#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;	

typedef struct RBTNode
{
	int data;
	Color color;
	struct RBTNode* left, * right, * parent;
}RBTNode;

RBTNode* NULL_NODE;	//global sentinel NULL_NODE pointer

void InitializeNULLNode()
{
	static RBTNode sentinel;
	NULL_NODE = &sentinel;
	NULL_NODE->color = BLACK;
	NULL_NODE->left = NULL_NODE->right = NULL_NODE->parent = NULL_NODE;
}

void LeftRotate(RBTNode** root, RBTNode* x)
{
	RBTNode* y = x->right;
	x->right = y->left;
	if (y->left != NULL_NODE)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL_NODE)
		*root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void RightRotate(RBTNode** root, RBTNode* y)
{
	RBTNode* x = y->left;
	y->left = x->right;
	if (x->right != NULL_NODE)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == NULL_NODE)
		*root = x;
	else if (y == y->parent->right)
		y->parent->right = x;
	else
		y->parent->left = x;
	x->right = y;
	y->parent = x;
}

void InsertFixup(RBTNode** root, RBTNode* z)
{
	while (z->parent->color == RED)	// Double red violation
	{
		if (z->parent == z->parent->parent->left)
		{
			RBTNode* y = z->parent->parent->right;	// y is uncle node of z
			if (y->color == RED)	// z's uncle node is red
			{
				z->parent->color = BLACK;	// parent node turn black
				y->color = BLACK;			// uncle node turn balck
				z->parent->parent->color = RED;	// grandparent node turn red
				z = z->parent->parent;		// adjust target tansfer to the grandparent of z
			}
			else
			{
				if (z == z->parent->right)	// LR case
				{
					z = z->parent;
					LeftRotate(root, z);	// first, leftrotate the left child of the grandparent node (*)
				}
				z->parent->color = BLACK;	// parent node turn black
				z->parent->parent->color = RED;	// grandparent node turn red
				// if it's case LL, only need to rightrotate once.
				// if LR, also need to rightrotate the grandparent node on the basis of previous one (*)
				RightRotate(root, z->parent->parent);	
			}
		}
		else
		{
			RBTNode* y = z->parent->parent->left;
			if (y->color == RED)	// z's uncle node is red
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)	// RL case
				{
					z = z->parent;
					RightRotate(root, z);	// tips: pay attention to the changed topology
				}							// the change of the pointer is very magical (v_v)
				z->parent->color = BLACK; 
				z->parent->parent->color = RED;
				LeftRotate(root, z->parent->parent);	// RR case only need once leftrotate
			}
		}
	}
	(*root)->color = BLACK;	// Insert the root node and turn black directly
	// Don't adjust when the parent node of the inserted node isn't red
}

void InsertNode(RBTNode** root, int data)
{
	RBTNode* z = (RBTNode*)malloc(sizeof(RBTNode));
	if (z == NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}
	z->data = data;
	z->left = z->right = NULL_NODE;
	z->color = RED;
	RBTNode* y = NULL_NODE;
	RBTNode* x = *root;
	while (x != NULL_NODE)	// Find the parent node that inserted the node
	{
		y = x;
		if (z->data < x->data)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL_NODE)
		*root = z;
	else if (z->data < y->data)
		y->left = z;
	else
		y->right = z;
	InsertFixup(root, z);
}

RBTNode* FindMin(RBTNode* node)
{
	while (node->left != NULL_NODE)
		node = node->left;
	return node;
}

void Transplant(RBTNode** root, RBTNode* u, RBTNode* v)	// replace subtree u with v 
{
	if (u->parent == NULL)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

void DeleteFixup(RBTNode** root, RBTNode* x)
{
	while (x != *root && x->color == BLACK)	// the delected node has no children and is black
	{
		if (x == x->parent->left)
		{
			RBTNode* w = x->parent->right;
			if (w->color == RED)	// sibling is red
			{
				// sibling and parent change color
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(root, x->parent);	// rotate in the direction where the node needs to be delected
				w = x->parent->right;
			}
			//sibling is black
			if (w->left->color == BLACK && w->right->color == BLACK)	// sibling is black and has no red children
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)	//RL case
				{
					w->left->color = BLACK;
					w->color = RED;
					RightRotate(root, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;	//RR case
				x->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotate(root, x->parent);
				x = *root;	//adjust accomplished, jump out the cycle
			}
		}
		else
		{
			RBTNode* w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RightRotate(root, x->parent);
				w = x->parent->left;	//?
			}
			if (w->right->color == BLACK && w->left->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)	//LR case
				{
					w->right->color = BLACK;
					w->color = RED;
					LeftRotate(root, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				RightRotate(root, x->parent);
				x = *root;
			}
		}
	}
	x->color = BLACK;
}

void DeleteNode(RBTNode** root, RBTNode* z) 
{
	RBTNode* y = z;
	RBTNode* x;
	Color yOriginalColor = y->color;
	if (z->left == NULL_NODE)	//deleted node has only one rightchild or no children
	{
		x = z->right;
		Transplant(root, z, z->right);
	}
	else if (z->right == NULL_NODE)	//deleteed node has only one leftchild
	{
		x = z->left;
		Transplant(root, z, z->left);
	}
	else							//deleted node has two children. convert into the previous two situations
	{
		y = FindMin(z->right);
		yOriginalColor = y->color;
		x = y->right;
		if (y->parent == z)
			x->parent = y;
		else 
		{
			Transplant(root, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(root, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	free(z);
	if (yOriginalColor == BLACK) 
		DeleteFixup(root, x);
}

// Search node
RBTNode* Search(RBTNode* root, int key)
{
	if (root == NULL_NODE || root == NULL)
		return NULL;
	if (key < root->data)
		return Search(root->left, key);
	else if (key > root->data)
		return Search(root->right, key);
	else
		return root;
}

// InOrder Traversal
void Inorder(RBTNode* root)
{
	if (root == NULL_NODE || root == NULL)
		return;
	Inorder(root->left);
	printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
	Inorder(root->right);
}

int main()
{
	InitializeNULLNode();
	RBTNode* root = NULL_NODE;
	InsertNode(&root, 10);
	InsertNode(&root, 5);
	InsertNode(&root, 15);
	InsertNode(&root, 1);
	InsertNode(&root, 7);
	InsertNode(&root, 12);
	InsertNode(&root, 18);
	printf("InOrder Traversal(1)£º\n");
	Inorder(root);
	printf("\n");
	RBTNode* node = Search(root, 7);
	if (node)
		DeleteNode(&root, node);
	printf("InOrder Traversal(2)£º\n");
	Inorder(root);
	printf("\n");
	return 0;
}
