#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NullElement -1

/*
	Array 형 Stack
*/

typedef struct stack * Stack; //stack의 포인터 변수 == Stack(데이터타입: 포인터 변수형)
typedef int element;

struct stack {
	element * array; //포인터 변수 선언 == int * array
	int size;
	int top;
};

Stack createStack(int c){
	Stack S = (Stack) malloc(sizeof(struct stack)); //실질적인 메모리 할당
	
	S->size = c; // S->size == *(S).size
	S->top = -1; //스택 초기화 및 비우기
	S->array = (int *) malloc(sizeof(int)*c); //미리 선언한 포인터 변수에 대입

	return S;
}

void push(element X, Stack S) {
	if (S->top == S->size - 1) {
		printf("Stack is full! Fail to push %d\n", X);
	}
	else {
		printf("%d pushing...\n", X);
		S->array[++(S->top)] = X;
		printf("%d push completed!\n", X);
	}
}

element pop(Stack S) {
	if (S->top < 0) {
		printf("Stack is empty!\n");
		return NullElement;
	}
	else {
		return S->array[(S->top)--];
	}
}

int main()
{	
	Stack s1 = createStack(5);
	int result;

	push(11, s1);
	push(22, s1);
	push(33, s1);
	push(44, s1);
	push(55, s1);
	push(66, s1); //overflow

	result = pop(s1);
	printf("%d\n", result);

	result = pop(s1);
	printf("%d\n", result);

	result = pop(s1);
	printf("%d\n", result);

	result = pop(s1);
	printf("%d\n", result);

	result = pop(s1);
	printf("%d\n", result);

	result = pop(s1);
	printf("%d\n", result);

	system("pause");
}
