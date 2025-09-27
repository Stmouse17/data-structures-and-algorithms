#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 100

//Parental representation of tree

typedef struct
{
	int data;
	int parent;
}PNode;

typedef struct
{
	PNode nodes[MAXSIZE];
	int root;
	int number;
}PTree;

//The child representation of tree

typedef struct
{
	int data;
	CNode* next;
}CNode;

typedef struct
{
	int data;
	CNode* firstchild;
}CBox;

typedef struct
{
	CBox nodes[MAXSIZE];
	int root;
	int number;
}CTree;

//Child-sibling representation of tree(Binary LinkList)

typedef struct
{
	int data;
	CSNode* firstchild;
	CSNode* rightsibling;
}CSNode;

