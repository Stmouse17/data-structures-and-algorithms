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

Node* Difference1(Node* Ha, Node* Hb)
{
	Node* pa = Ha->next;
	Node* pb = Hb->next;
	Node* Hc = Ha;
	Node* pc = Hc;
	Hc->data = 0;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			Node* tmp1 = pa->next;
			free(pa);
			pa = tmp1;
			Node* tmp2 = pb->next;
			free(pb);
			pb = tmp2;
		}
		else if (pa->data > pb->data)
		{
			Node* tmp = pb->next;
			free(pb);
			pb = tmp;
		}
		else
		{
			Node* tmp = pa->next;
			pa->next = pc->next;
			pc->next = pa;
			pc = pa;
			pa = tmp;
			Hc->data++;
		}
	}
	while (pa)
	{
		Node* tmp = pa->next;
		pa->next = pc->next;
		pc->next = pa;
		pc = pa;
		pa = tmp;
	}
	free(Hb);
	pc->next = NULL;
	return Hc;
}

Node* Difference2(Node* Ha, Node* Hb)	//改进版本，Hb不被更改，仅作参考，设置pre前驱方便删除
{										//Ha中的重复项
	Node* pa = Ha->next;
	Node* pb = Hb->next;
	Node* pre = Ha;
	int count = 0;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			count++;
			pre = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pb = pb->next;
		}
		else
		{
			pre->next = pa->next;
			free(pa);
			pa = pre->next;
		}
	}
	Ha->data = count;
	return Ha;
}

int main()
{
	printf("Sintream_ouse\n");
	Node* Ha = InitList();
	Node* Hb = InitList();
	TailInsert(Ha, 1);
	TailInsert(Ha, 3);
	TailInsert(Ha, 4);
	TailInsert(Ha, 6);
	TailInsert(Ha, 7);
	TailInsert(Ha, 12);
	TailInsert(Hb, 2);
	TailInsert(Hb, 3);
	TailInsert(Hb, 4);
	TailInsert(Hb, 6);
	TailInsert(Hb, 8);
	Node* Hc = Difference2(Ha, Hb);
	PrintList(Hc);
	printf("%d", Hc->data);
	return 0;
}
