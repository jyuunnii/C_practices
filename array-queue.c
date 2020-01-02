#include<stdio.h>
#include<stdlib.h>

#define NullElement -1

/*
	Array형 Queue
*/

typedef struct queue * Queue; 
typedef int element;

struct queue {
	element * array;
	int size;
	int front;
	int rear;
};

Queue createQueue(int c)
{
	Queue Q = (Queue)malloc(sizeof(struct queue));

	Q->size = c;
	Q->front = -1;
	Q->rear = -1;
	Q->array = (element *)malloc(sizeof(element) * c);

	return Q;
}

int IsEmpty(Queue Q)
{
	if(Q->front == Q->rear){
		printf("Queue is empty!");
		return 1;
	}
	else return 0;
}

void enqueue(element X, Queue Q)
{
	if(Q->rear == Q->size-1)
	{
		printf("Queue is full! Fail to insert %d\n", X);
		return;
	}
	else{
		printf("%d inserting...\n", X);
		Q->array[++(Q->rear)]=X;
		printf("%d insert completed!\n", X);
	}
	
}

element dequeue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("No elements in queue!\n");
		return NullElement;
	}
	else return Q->array[++(Q->front)];
}

int main()
{
	Queue Q1 = createQueue(5);
    int result;

	enqueue(11,Q1);
	enqueue(22,Q1);
	enqueue(33,Q1);
	enqueue(44,Q1);
	enqueue(55,Q1);
	enqueue(66,Q1);

	result = dequeue(Q1);
	printf("%d\n", result);

	result = dequeue(Q1);
	printf("%d\n", result);

	result = dequeue(Q1);
	printf("%d\n", result);

	result = dequeue(Q1);
	printf("%d\n", result);

	result = dequeue(Q1);
	printf("%d\n", result);

	result = dequeue(Q1);
	printf("%d\n", result);

	system("pause");
}
