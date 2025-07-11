#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	Node* next;
}Node;

Node* initLinkStack()
{
	Node* top = (Node*)malloc(sizeof(Node));
	top->data = 0;	//头指针数据域作计数器，记录元素个数
	top->next = NULL;
	return top;
}

void Push(Node* top, int data)	//头插法的变式
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = top->next;
	top->next = node;
	top->data++;
}

int Pop(Node* top)
{
	int reception = top->next->data;
	Node* tmp = top->next;
	top->next = top->next->next;
	free(tmp);
	top->data--;
	return reception;
}