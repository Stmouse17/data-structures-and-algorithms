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

Node* Intersection(Node* La, Node* Lb)
{
	Node* pa = La->next;
	Node* pb = Lb->next;
	Node* Lc = La;
	Node* pc = Lc;
	Lc->data = 0;
	while (pa && pb)
	{
		if (pa->data = pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			Node* tmp = pb->next;
			free(pb);
			pb = tmp;
			Lc->data++;
		}
		else if (pa->data < pb->data)
		{
			Node* tmp = pa->next;
			free(pa);
			pa = tmp;
		}
		else
		{
			Node* tmp = pb->next;
			free(pb);
			pb = tmp;
		}
	}
	while (pa)	//注意中断条件，进程顺序执行，先保证进入条件更严格的循环或判断。
	{
		Node* tmp = pa->next;
		free(pa);
		pa = tmp;
	}
	while (pb)
	{
		Node* tmp = pb->next;
		free(pb);
		pb = tmp;
	}
	pc->next = NULL;
	free(Lb);
	return Lc;
}

int main()
{
	printf("Sintream_ouse\n");
	Node* La = InitList();
	Node* Lb = InitList();
	TailInsert(La, 1);
	TailInsert(La, 2);
	TailInsert(La, 3);
	TailInsert(La, 4);
	TailInsert(La, 5);
	TailInsert(La, 6);
	TailInsert(Lb, 2);
	TailInsert(Lb, 4);
	TailInsert(Lb, 5);
	TailInsert(Lb, 7);
	TailInsert(Lb, 8);
	Node* Lc = Intersection(La, Lb);
	PrintList(Lc);
	printf("%d ", Lc->data);
	return 0;
}