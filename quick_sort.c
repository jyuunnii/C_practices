#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b, swap) swap=a;a=b;b=swap

/*
	Quick sort algorithm 오름차순 정렬
	time complexity: O(nlogn)

	1) if(left<right): 정렬할 범위가 2개이상의 데이터이면 -> Quick sort 실행조건 성립
	2) 1st Do-while문: low, high가 교차할때까지 반복
	3) 2nd Do-while문: list[low]가 pivot보다 작으면 low++(left를 오른쪽으로 1칸씩 이동)
	4) 3rd Do-while문: list[high]가 pivot보다 크면 high--(right를 왼쪽으로 1칸씩 이동)
	5) 1st SWAP: 1st Do-while문 실행동안 low와 high가 교차하지 않으면 SWAP
	6) 2nd SWAP: 1st Dp-while문 빠져나오면 left, high SWAP
	7) recursiveness
*/


void quicksort(int list[], int left, int right);
void show(int list[], int num);

int main(void) {
	int list[1000];
	int input;
	int num;
	int i;
	scanf("%d", &num);
	
	for (i = 0; i < num; i++) {
		scanf("%d", &input);
		list[i] = input;
		printf("inserting...%d\n", list[i]);
	}

	quicksort(list, 0, num-1);
	show(list, num);
	//system("pause");
	return 0;
}

void quicksort(int list[], int left, int right) {
	int pivot, low, high;
	int temp;
	if(left < right){
		low = left;
		high = right+1;
		pivot = list[left];

		do{
			do{
				low++;
			}while(list[low] < pivot);
			do{
				high--;
			}while(list[high] > pivot);

			if(low<high){
				SWAP(list[low], list[high], temp);
			} 
		}while(low < high);

		SWAP(list[left], list[high], temp);
		quicksort(list, left, high-1);
		quicksort(list, high+1, right);
	}
}

void show(int list[], int num) {
	int rank[num];
	int t = 1;
	for(int j = num-1; j>=0; j--) {
		if(list[j]==list[j+1]){ //list 역순으로 스캔하기 때문에
			rank[j] = rank[j+1];
			printf("%d등: ",rank[j]);
		}
		else{
			rank[j] = t;
			printf("%d등: ",rank[j]);
		}
		t++;
		printf("%d\n", list[j]);
	}
}

