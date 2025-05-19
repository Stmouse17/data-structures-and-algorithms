#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* InitList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return list;
}

void TailInsert(Node* list, int data)
{
	Node* head = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	while (list->next)
	{
		list = list->next;
	}
	list->next = node;
	head->data++;
}

void PrintList(Node* list)
{
	Node* origin = list;
	list = list->next;
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("NULL ");
	printf("%d\n", origin->data);
}

void Decompose(Node* Ha, Node* Hb, Node* Hc)
{
	Node* pa = Ha->next;
	while (pa)
	{
		Node* tmp = pa->next;
		if (pa->data < 0)
		{
			pa->next = Hb->next;
			Hb->next = pa;
			Hb->data++;
		}
		else
		{
			pa->next = Hc->next;
			Hc->next = pa;
			Hc->data++;
		}
		pa = tmp;
	}
	free(Ha);
}

int main()
{
	printf("Sintream_ouse\n");
	Node* Ha = InitList();
	Node* Hb = InitList();
	Node* Hc = InitList();
	TailInsert(Ha, -7);
	TailInsert(Ha, -4);
	TailInsert(Ha, -1);
	TailInsert(Ha, 2);
	TailInsert(Ha, 5);
	TailInsert(Ha, 7);
	TailInsert(Ha, 17);
	Decompose(Ha, Hb, Hc);
	PrintList(Hb);
	PrintList(Hc);
	return 0;
}
