#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11
#define EMPTY -1
#define DELETED -2

typedef struct
{
	int* data;
}HashTable;

void InitHashTable(HashTable* ht)
{
	ht->data = (int*)malloc(sizeof(int) * TABLE_SIZE);
	for (int i = 0; i < TABLE_SIZE; i++)
		ht->data[i] = EMPTY;
}

int	Hash(int key)	//Obtain the theoretical position of the keyword in the hashtable
{
	return key % TABLE_SIZE;
}

int InsertKey(HashTable* ht, int key)
{
	int i = Hash(key);
	int start = i;
	do
	{
		if (ht->data[i] == EMPTY || ht->data[i] == DELETED)
		{
			ht->data[i] = key;
			return 1;
		}
		if (ht->data[i] == key)
			return 0;
		i = (i + 1) % TABLE_SIZE;
	} while (i != start);
	return -1;
}

int SearchKey(HashTable* ht, int key)
{
	int i = Hash(key);
	int start = i;
	do
	{
		if (ht->data[i] == EMPTY)
			return -1;
		if (ht->data[i] == key)
			return i;
		i = (i + 1) % TABLE_SIZE;
	} while (i != start);
	return -1;
}

int DeleteKey(HashTable* ht, int key)
{
	int pos = SearchKey(ht, key);
	if (pos == -1)
		return 0;
	ht->data[pos] = DELETED;
	return 1;
}

void PrintHashTable(HashTable* ht)
{
	printf("Hash Table: \n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (ht->data[i] == EMPTY)
			printf("[%2d] : EMPTY\n", i);
		else if (ht->data[i] == DELETED)
			printf("[%2d] : DELETED\n", i);
		else
			printf("[%2d] : %d\n", i, ht->data[i]);
	}
}

int main() {
	HashTable ht;
	InitHashTable(&ht);
	InsertKey(&ht, 22);
	InsertKey(&ht, 33);
	InsertKey(&ht, 44);
	InsertKey(&ht, 55);
	InsertKey(&ht, 66);
	PrintHashTable(&ht);
	int key = 55;
	int pos = SearchKey(&ht, key);
	if (pos != -1)
		printf("\nKeyword %d in %d\n", key, pos);
	else
		printf("\nKeyword %d cannot be found\n", key);
	DeleteKey(&ht, 33);
	DeleteKey(&ht, 55);
	printf("\nAfter deletion£º\n");
	PrintHashTable(&ht);
	return 0;
}