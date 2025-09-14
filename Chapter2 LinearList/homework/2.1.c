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

Node* MergeList(Node* Ha, Node* Hb)
{
	Node* pa = Ha->next;
	Node* pb = Hb->next;
	Node* Hc = Ha;
	Node* pc = Hc;
	int count = 0;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pa = pa->next;
			Node* tmp = pb->next;
			free(pb);
			pb = tmp;
			count++;
		}
	}
	pc->next = pa ? pa : pb;
	Hc->data = Ha->data + Hb->data - count;
	free(Hb);
	return Hc;
}

int main()
{
	printf("Sinream_ouse\n");
	Node* Ha = InitList();
	Node* Hb = InitList();
	TailInsert(Ha, 1);
	TailInsert(Ha, 4);
	TailInsert(Ha, 7);
	TailInsert(Ha, 32);
	TailInsert(Ha, 255);
	TailInsert(Hb, 2);
	TailInsert(Hb, 3);
	TailInsert(Hb, 17);
	TailInsert(Hb, 32);
	TailInsert(Hb, 256);
	TailInsert(Hb, 257);
	Node* Hc = MergeList(Ha, Hb);
	PrintList(Hc);
	printf("%d", Hc->data);
	return 0;
}
