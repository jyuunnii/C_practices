#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*
	dynamic 구조체: Linked list의 구조체는 value, next를 가짐
	value == 데이터
	next == 포인터
	Linked list의 노드들은 chain 식으로 연결됨, 노드 == 구조체

	static array 구조체: array-stack
	stack의 구조체는 개발자가 임의로 설정 size, top, pointer (배열 사이즈 predefined)
*/

typedef struct node* pNode; //node 구조체 자체를 가리키는 pNode(node의 포인터 변수)
typedef pNode Head; // head 구조체
typedef pNode Node; //구조체 하나하나
typedef int bool;

struct node {
	int value;
	Node next;
};

bool insert(int position, Head L, Node tempNode) {
	Node prev = L; 

	//prev->value == position 찾는 loop
	//return position_node(==prev)
	while (prev->value != position) {
		if (prev->next == NULL) {
			free(tempNode);
			return FALSE; //해당 value를 가진 노드 없음
		}
		else {
			prev = prev->next;
		}
	}

	tempNode->next = prev->next;
	prev->next = tempNode;
	printf("inserted\n");

	return TRUE;
}

bool delete_one(int target, Head L) {
	if (L->next == NULL) {
		return FALSE;
	}
	Node prev = L;

	if(prev->value == target){
		free(prev);
	}

	while((prev->next)->value != target){
		if(prev->next == NULL){
			return FALSE;
		}
		else{
			prev = prev->next;
			if(prev->next == NULL) return FALSE;
		}
		
	}


	Node temp = prev->next;
	prev->next = temp->next;

	printf("%d deleted! \n", temp->value);
	free(temp);
	

	return TRUE;
}

int findPrev(int target, Head L) {
	if (L->next == NULL) {
		return -1;
	}

	Node prev = L;
	
	while((prev->next)->value != target){
		if(prev->next == NULL){
			return FALSE;
		}
		else{
			prev = prev->next;
			if(prev->next == NULL) return -1;
		}
	}

	printf("Found! \n");

	return prev->value;
}

void show(Head L) {
	Node c = L;
	while (c->next != NULL) {
		printf("%d\n", (c->next)->value);
		c = c->next;
	}
	printf("\n");
}

void deleteList(Head L) {
	while (L->next != NULL) {
		Node temp = L;
		temp->next = L -> next;
		printf("delete %d\n", L->value );
		free(L);
		L = temp->next;
	}
	printf("delete %d\n", L->value);
	free(L);
}

int main()
{
	Node header = (Node)malloc(sizeof(struct node)); //시작노드 header
	header->value = 0;
	header->next = NULL;

	char command;

	scanf(" %c", &command);

	while (command != 'e') {
		if (command == 'i') {

			int input; // 7
			int position; // insert 'tempNode' right next to target node which has position in value
			scanf("%d %d", &input, &position);

			//input 담을 노드 temp 형성
			Node tempNode = (Node)malloc(sizeof(struct node));
			tempNode->value = input;
			tempNode->next = NULL; 

			if (!insert(position, header, tempNode)) {
				printf("Insert error. The %d isn't in the list.\n", position);
			}
		}

		else if (command == 'd') {
			int input;
			scanf("%d", &input);
			if (!delete_one(input, header)) {
				printf("Delete error. The %d isn't in the list.\n", input);
			}
		}

		else if (command == 'f') {
			int input;
			scanf("%d", &input);
			int res = findPrev(input, header);
			switch (res) {
			case -1:
				printf("Find error. The %d isn't in the list.\n", input);
				break;
			case 0:
				printf("The %d is next of the header.\n", input);
				break;
			default:
				printf("The %d is next of the %d.\n", input, res);
				break;
			}
		}
		else if (command == 's') {
			show(header);
		}
		scanf(" %c", &command);
	}

	deleteList(header);

	return 0;
}

