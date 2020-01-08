#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    1) binary search tree는 배열이 아니기때문에 구조체별 포인터변수(Tree)만 있어도 가능? tree는 array/list 두 가지로 나타낼 수 있다.
    구조체 타입 포인터란? 구조체를 가리키는 포인터
*/


typedef struct node * Tree; //구조체의 포인터 변수(Tree) 선언
typedef struct node * Node;
typedef int element;

struct node {
	int value;
	Node leftChild; //leftChild 노드의 포인터 변수 선언
	Node rightChild;
};

/*
typedef struct node{
    ...
} Node;

해당 예제에서는 포인터 변수를 미리 설정하지 않고 insert시 매칭
*/


Node insert(Node new, Tree tree);

void printTreePrefix(Tree t);
void printTreeInfix(Tree t);
void printTreePostfix(Tree t);
Node deleteNode(int value, Tree tree);
Node change(Tree tree);

int main(void) {
    printf("Enter a value of the root node: ");
    int value; //30...
    scanf("%d", &value);

    Tree root = (Tree)malloc(sizeof(struct node)); // 메모리 할당과 동시에 리턴되는 주소값을, 구조체 포인터 변수 root에 대입
    root->leftChild = NULL;
    root->rightChild = NULL;
    root->value = value; //root = 30

    char command;
    char printMode[10];

    scanf("%c", &command);

    while (command != 'e') {
        if (command == 'i') {
            scanf("%d", &value);

            Node new = (Node)malloc(sizeof(struct node)); //새로운 구조체 포인터를 newNode에 대입
            new->leftChild = NULL;
            new->rightChild = NULL;
            new->value = value;

            insert(new, root);
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
        else if (command == 'd') {
            scanf("%d", &value);
            deleteNode(value, root);
        }

        scanf("%c", &command);
    }

	return 0;
}

Node insert(Node new, Tree root) {
    int val = new->value;
    Tree * ptr = &new; //상위노드의 포인터에 new노드 연결

    if (root == NULL) {
        root = *ptr;
        root->leftChild = root -> rightChild = NULL;
        root->value = val;
    }
    else {
        printf("%d\n", root->value);
        if(root->value > val){    
            root->leftChild = insert(new, root->leftChild);
        }
        else if(root->value < val){
            root -> rightChild = insert(new, root->rightChild);
        }
        else{
            printf("same value error!\n");
        }
    }
    
    return root;
}

Node change(Tree tree){
    Node rnode = tree->rightChild;
    Node temp = tree;
    while(rnode != NULL){    
        temp = rnode;
        rnode = rnode->rightChild;
    } //;temp == target node
    tree->value = temp->value;
    
    while(tree != NULL){
        if(tree->rightChild == temp) break;
        tree = tree->rightChild;
    }
    return tree;
}

Node deleteNode (int val, Tree tree) {
    if (tree == NULL){
        printf("%d not found\n", val);
        return tree;
    }
    else if (val <tree->value) {
        tree->leftChild = deleteNode(val, tree->leftChild);
    }
    else if (val > tree->value) {
        tree->rightChild = deleteNode(val, tree->rightChild);
    }
    else if (val == tree->value) {
        printf("found!\n");
        // 1. The node has both left, right child
        if(tree->leftChild && tree->rightChild){
            Node temp  = change(tree);
            Node empty = temp->rightChild;
            temp->rightChild = NULL;
            free(empty);

        }
        else if(tree->leftChild == NULL){
            // 2. The node is a leaf node
            if(tree->rightChild == NULL){
                Node temp = NULL;
                free(tree);
                return temp;
            }
            // 3. The node has one right child
            else{
                Node temp = tree->rightChild;
                tree->value = temp->value;
                tree->rightChild = NULL;
                free(tree); 
                return temp;
            }
        }
        //4. The node has one left child  
        else if(tree->leftChild != NULL && tree->rightChild == NULL){
            Node temp = tree->leftChild;
            tree->value = temp->value;
            tree->leftChild = NULL;
            free(tree);
            return temp;
        }
        
    }
    return tree;

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

