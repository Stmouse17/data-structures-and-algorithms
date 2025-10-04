#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Using array to build an Huffman Tree

typedef struct
{
	int weight;
	int lchild, rchild;
	int parent;
}HNode;

HNode* CreateHuffmanTree(HNode* T, int w[], int n)	//w[] is the weight array, n is the number of leaf nodes
{
	int m = 2 * n - 1;	//Total number of nodes in the Huffman Tree
	int m1, m2;	//Indices of the two nodes with the smallest weights
	//Copilot knows all things? WTF
	T = (HNode*)malloc((m + 1) * sizeof(HNode));
	if (!T)
	{
		printf("Memory allocation failed!\n");
		exit(-1);
	}
	for (int i = 1; i <= n; i++)
	{
		T[i].weight = w[i - 1];
		T[i].lchild = T[i].rchild = T[i].parent = 0;
	}
	for (int i = n + 1; i <= m; i++)
	{
		T[i].weight = 0;
		T[i].lchild = T[i].rchild = T[i].parent = 0;
	}
	for (int i = n + 1; i <= m; i++)
	{
		m1 = m2 = 0;
		for (int j = 1; j < i; j++)
		{
			if (T[j].parent == 0)	//Node j is not yet part of the tree
			{
				if (m1 == 0 || T[j].weight < T[m1].weight)
				{
					m2 = m1;
					m1 = j;
				}
				else if (m2 == 0 || T[j].weight < T[m2].weight)
				{
					m2 = j;
				}
			}
		}
		T[m1].parent = T[m2].parent = i;
		T[i].lchild = m1;
		T[i].rchild = m2;
		T[i].weight = T[m1].weight + T[m2].weight;
	}
	return T;
}

void PrintHuffmanTree(HNode* T, int n)
{
	int m = 2 * n - 1;
	printf("Index\tWeight\tLChild\tRChild\tParent\n");
	for (int i = 1; i <= m; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", i, T[i].weight, T[i].lchild, T[i].rchild, T[i].parent);
	}
}

typedef char** HCode;	// Huffman code type，表示字符串数组

void CreateHuffmanCode(HNode* T, HCode *C, int n)
{
	int s = n - 1;
	int p = 0;
	*C = (HCode)malloc((n + 1) * sizeof(char*));	// C[0] 不使用
	if (!*C)
	{
		printf("Memory allocation failed!\n");
		exit(-1);
	}
	char* cd = (char*)malloc(n * sizeof(char));
	if (!cd)
	{
		printf("Memory allocation failed!\n");
		exit(-1);
	}
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++)
	{
		s = n - 1;
		for (int c = i, p = T[i].parent; p != 0; c = p, p = T[p].parent)
		{
			if (T[p].lchild == c)
				cd[--s] = '0';
			else
				cd[--s] = '1';
		}
		(*C)[i] = (char*)malloc((n - s) * sizeof(char));
		if (!(*C)[i])
		{
			printf("Memory allocation failed!\n");
			exit(-1);
		}
		strcpy((*C)[i], &cd[s]);
	}
	free(cd);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %s\n", T[i].weight, (*C)[i]);
		printf("\n");
	}
}

int main()
{
	int w[] = { 5, 29, 7, 8, 14, 23, 3, 11, 17, 4 };
	int n = sizeof(w) / sizeof(w[0]);
	HNode* T = NULL;
	T = CreateHuffmanTree(T, w, n);
	HCode C = NULL;
	PrintHuffmanTree(T, n);
	CreateHuffmanCode(T, &C, n);
	free(T);
	for (int i = 1; i <= n; i++)
		free(C[i]);
	free(C);
	return 0;
}
