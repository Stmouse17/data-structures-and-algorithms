#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

/*
	Be cautious of using this recursive algorithm, as its spatial and temporal
	complexity increase exponentially, making it prone to stack overflow.
*/

int Ackermann1(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (m != 0 && n == 0)
		return Ackermann1(m - 1, 1);
	else
		return Ackermann1(m - 1, Ackermann1(m, n - 1));
}

typedef struct
{
    int m, n;
} Frame;

int Ackermann2(int m, int n) 
{
    Frame stack[MAX];
    int top = -1;
    stack[++top] = (Frame){ m, n };
    while (top >= 0) {
        Frame cur = stack[top--];
        m = cur.m;
        n = cur.n;
        if (m == 0) 
        {
            n = n + 1;
            if (top >= 0) stack[top].n = n;
        }
        else if (n == 0) 
        {
            stack[++top] = (Frame){ m - 1, 1 };
        }
        else 
        {
            stack[++top] = (Frame){ m - 1, -1 };    // ռλ
            stack[++top] = (Frame){ m, n - 1 };
        }
    }
    return n;
}

int main()
{
	printf("Sinream_ouse\n");
	printf("Ackermann1(2, 1) = %d\n", Ackermann1(2, 1));
	printf("Ackermann2(3, 2) = %d\n", Ackermann2(3, 2));
	return 0;
}
