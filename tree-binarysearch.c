#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node * Tree;
typedef struct node * Node;
typedef int element;

struct node {
	int value;
	Node leftChild; //포인터 변수
	Node rightChild;
};

Node insert(Node new, Tree tree);

void printTreePrefix(Tree t);
void printTreeInfix(Tree t);
void printTreePostfix(Tree t);

int main(void) {
    printf("Enter a value of the root node: ");
    int value; //30...
    scanf("%d", &value);

    Tree root = (Tree)malloc(sizeof(struct node)); //실질적인 메모리 할당
    root->leftChild = NULL;
    root->rightChild = NULL;
    root->value = value; //root = 30

    char command;
    char printMode[10];

    scanf("%c", &command);

    while (command != 'e') {
        if (command == 'i') {
            scanf("%d", &value);

            Node newNode = (Node)malloc(sizeof(struct node));
            newNode->leftChild = NULL;
            newNode->rightChild = NULL;
            newNode->value = value;

            insert(newNode, root);
        }
        else if (command == 'p') {
            scanf("%s", printMode);
            if (strcmp(printMode, "pre") == 0) {
                printTreePrefix(root);
            }
            else if (strcmp(printMode, "in") == 0) {
                printTreeInfix(root);
            }
            else if (strcmp(printMode, "post") == 0) {
                printTreePostfix(root);
            }

            printf("\n");
        }

        scanf("%c", &command);
    }

	return 0;
}

Node insert(Node newNode, Tree root) {
    int new = newNode->value;
    Tree * ptr = &newNode; //구조체 포인터 변수 선언
    if (root == NULL) {
        root = *ptr;
        root->leftChild = root -> rightChild = NULL;
        root->value = new;
    }
    else {
        printf("%d\n", root->value);
        if(root->value > new){    
            root->leftChild = insert(newNode, root->leftChild);
        }
        else if(root->value < new){
            root -> rightChild = insert(newNode, root->rightChild);
        }
        else{
            printf("same value error!\n");
        }
    }
    
    return root;
}

void printTreePrefix (Node t) {
    if (t == NULL)
        return;

    printf(" %d", t->value);
    printTreePrefix(t->leftChild);
    printTreePrefix(t->rightChild);
}

void printTreeInfix (Node t) {
    if (t == NULL)
        return;

    printTreeInfix(t->leftChild);
    printf(" %d", t->value);
    printTreeInfix(t->rightChild);
}

void printTreePostfix (Node t) {
    if (t == NULL)
        return;

    printTreePostfix(t->leftChild);
    printTreePostfix(t->rightChild);
    printf(" %d", t->value);
}

