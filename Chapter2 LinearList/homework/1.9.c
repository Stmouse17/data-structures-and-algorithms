#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* InitList()
{
	Node* H = (Node*)malloc(sizeof(Node));
	H->data = 0;
	H->next = H;
	H->pre = H;
	return H;
}

void PrintList(Node* H)
{
	Node* node = H->next;
	while (node != H)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("NULL\n");

}

void TailInsert(Node* H, int data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	Node* node = H;
	while (node->next != H)
	{
		node = node->next;
	}
	n->next = H;
	n->pre = node;
	node->next = n;
	H->pre = n;
	H->data++;
}

void Exchange(Node* H, int data)
{
	Node* p = H->next;
	while (p->data != data)
		p = p->next;
	Node* q = p->pre;
	q->pre->next = p;
	p->next->pre = q;
	p->pre = q->pre;
	q->next = p->next;
	q->pre = p;
	p->next = q;
}

int main()
{
	printf("Sintream_uose\n");
	Node* H = InitList();
	TailInsert(H, 1);
	TailInsert(H, 2);
	TailInsert(H, 3);
	TailInsert(H, 4);
	TailInsert(H, 5);
	TailInsert(H, 6);
	TailInsert(H, 7);
	Exchange(H, 6);
	PrintList(H);
	return 0;
}