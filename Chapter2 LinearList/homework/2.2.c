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
	list = list->next;
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("NULL\n");
}

Node* MergeList1(Node* Ha, Node* Hb)
{
	Node* pa = Ha->next;
	Node* pb = Hb->next;
	Node* Hc = Ha;
	Node* pc = Hc;
	Node* node = NULL;
	Hc->next = NULL;
	Hc->data = Ha->data + Hb->data;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			node = pa;
			pa = pa->next;
		}
		else if (pa->data >= pb->data)
		{
			node = pb;
			pb = pb->next;
		}
		node->next = Hc->next;
		Hc->next = node;
	}
	while (pb)
	{
		node = pb;
		pb = pb->next;
		node->next = Hc->next;
		Hc->next = node;
	}
	while (pa)
	{
		node = pa;
		pa = pa->next;
		node->next = Hc->next;
		Hc->next = node;
	}
	free(Hb);
	return Hc;
}

Node* MergeList2(Node* Ha, Node* Hb)
{
	Node* pa = Ha->next;
	Node* pb = Hb->next;
	Node* Hc = Ha;
	Node* pc = Hc;
	Node* node = NULL;
	Hc->next = NULL;
	Hc->data = Ha->data + Hb->data;
	while (pa || pb)
	{
		if (!pa)
		{
			node = pb;
			pb = pb->next;
		}
		else if (!pb)
		{
			node = pa;
			pa = pa->next;
		}
		else if (pa->data < pb->data)
		{
			node = pa;
			pa = pa->next;
		}
		else if (pa->data >= pb->data)
		{
			node = pb;
			pb = pb->next;
		}
		node->next = Hc->next;
		Hc->next = node;
	}
	free(Hb);
	return Hc;
}

int main()
{
	printf("Sinteam_ouse\n");
	Node* Ha = InitList();
	Node* Hb = InitList();
	TailInsert(Ha, 1);
	TailInsert(Ha, 4);
	TailInsert(Ha, 7);
	TailInsert(Ha, 7);
	TailInsert(Ha, 25);
	TailInsert(Ha, 101);
	TailInsert(Hb, 2);
	TailInsert(Hb, 4);
	TailInsert(Hb, 8);
	TailInsert(Hb, 32);
	TailInsert(Hb, 117);
	Node* Hc = MergeList(Ha, Hb);
	PrintList(Hc);
	printf("%d ", Hc->data);
	return 0;
}
