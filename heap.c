#include <stdio.h>
#include <stdlib.h>

/*
	Min heap
	Heap 정렬에서 array[1]부터 사용
	array[0]은 사용하지 않음!
*/

#define MAX_ELEMENTS 10
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)


typedef struct{
	int key;
} element;

element heap[MAX_ELEMENTS];
int size = 0;
int i = 0;
// int j = 1;

void insert_min_heap(element item);
element delete_min_heap(void);

int main(void) {
	int input = 0;
	element item;

	while(input != -1) {
        scanf("%d", &input);

        if (input == 0) {
            item = delete_min_heap();
            printf("%d\n", item.key);
        }
        else {
            item.key = input;
            insert_min_heap(item);
        }
	}

	return 0;
}


void insert_min_heap(element item) {
	if(HEAP_FULL(size)){
		fprintf(stderr,"The heap is full.\n");
		exit(1);
	}
	
	++i;
	printf("size : %d\n", i);
	printf("item: %d\n", item);

	while((i != 1)&&(item.key < heap[i/2].key)){
		heap[i] = heap[i/2];
		i /=2;
	}
	heap[i] = item;
	size++;
	i = size;
	
	// Heap 출력
	for(int j=1; j <= size; j++){
		printf("%d\n", heap[j]);
	}
	printf("-----------\n");
	return;
}

element delete_min_heap(void) {
	element item, temp;
	int parent, child;
	
	if(HEAP_EMPTY(size)){
		fprintf(stderr,"The heap is empty.\n");
		exit(1);
	}

	item = heap[1];
	temp = heap[size--];
	parent = 1;
	child = 2;

	while(child <= size){
		if((child < size)&&(heap[child].key) > heap[child+1].key){
			child++;
		}
		if(temp.key <= heap[child].key) break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;


	// Heap 출력
	printf("Heap\n");
	for(int k=1; k <= size; k++){
		printf("%d\n", heap[k]);
	}
	printf("-----------\n");
	
	return item;
}



