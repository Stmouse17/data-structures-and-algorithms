#define MAXSIZE 100

//Here,SqQueue == CycleQueue.

typedef struct SqOueue
{
	int* base;
	int head;
	int rear;
}SqQueue;

void InitSqQueue(SqQueue* q)
{
	q->base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!q->base)
		exit(0);
	q->head = q->rear = 0;
}

void InsertSqQueue(SqQueue* q, int e)
{
	if ((q->rear + 1) % MAXSIZE == q->head)
	{
		printf("Queue is full");
		return;
	}
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

void DeleteSqQueue(SqQueue* q, int* e)
{
	if (q->head == q->rear)
	{
		printf("Queue is empty");
		return;
	}
	*e = q->base[q->head];
	q->head = (q->head + 1) % MAXSIZE;
}