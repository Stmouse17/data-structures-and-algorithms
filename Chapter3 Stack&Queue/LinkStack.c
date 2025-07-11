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
	top->data = 0;	//ͷָ��������������������¼Ԫ�ظ���
	top->next = NULL;
	return top;
}

void Push(Node* top, int data)	//ͷ�巨�ı�ʽ
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