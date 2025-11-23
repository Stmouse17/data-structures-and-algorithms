#include <stdio.h>
#include <stdlib.h>

/*
In a doubly linked list with a head node, use double-bubble sort 
(cocktail sort)to arrange the records in ascending order.
*/

typedef struct Node
{
	int key;
	struct Node* prev, * next;
}Node;

Node* CreateNode(int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

Node* BuildList(int a[], int n)
{
	Node* head = CreateNode(0); // head node
	Node* tail = head;
	for (int i = 0; i < n; i++)
	{
		Node* newNode = CreateNode(a[i]);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	return head;
}

void PrintList(Node* head)
{
	Node* p = head->next;
	while (p)
	{
		printf("%d ", p->key);
		p = p->next;
	}
	printf("\n");
}

void CocktailSort(Node* head)
{
	if (!head || !head->next)
		return;
	int swapped = 1;	// flag to check if any swapping happened
	Node* start = head->next, * end = NULL;
	//What is the function of 'end'?
	//It marks the boundary of the unsorted section at the end of the list.
	while (swapped)
	{
		swapped = 0;
		// Forward pass
		Node* p = start;
		while (p->next != end && p->next)	
		{
			if (p->key > p->next->key)
			{
				int tmp = p->key;
				p->key = p->next->key;
				p->next->key = tmp;
				swapped = 1;
			}
			p = p->next;
		}
		end = p; // Update the end marker
		if (!swapped)
			break;
		swapped = 0;
		// Backward pass
		while (p->prev != head)
		{
			if (p->prev->key > p->key)
			{
				int tmp = p->key;
				p->key = p->prev->key;
				p->prev->key = tmp;
				swapped = 1;
			}
			p = p->prev;
		}
		start = head->next; // Update the start marker
	}
}

int main()
{
	int a[] = { 7, 6, 1, 8, 5, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	Node* head = BuildList(a, n);
	printf("Original: ");
	PrintList(head);
	CocktailSort(head);
	printf("Sorted:   ");
	PrintList(head);
	return 0;
}