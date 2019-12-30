#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    char name[10];
    int age;
    int salary;
    char department[20];
} Employee;

void insert(Employee *, char *);
void delete_one(Employee *, char *);
int find(Employee *, char *);
void inform(Employee *, char *);
int avgBenefit(Employee *, char *);

int number;
Employee NullEmpolyee = {"", -1, -1, ""};

int main()
{
    char input[100]; //배열 선언
    char *word;  // 시작점 포인터 변수 선언
    Employee *people;
    int flag = 0, i;

    printf("사원 관리 프로그램을 위한 메모리를 할당합니다. \n");
    printf("set 메모리크기 입력 대기...\n");

    gets(input); // 구조체 메모리 크기 할당
    word = strtok(input, " ");

    if (word == NULL)
        return 0;

    if (strcmp(word, "set") == 0) {
        word = strtok(NULL, " ");
        number = atoi(word); //문자 => 정수로 변환
        people = (Employee*)malloc(sizeof(Employee) * number);
        flag = 1;
    }

    if (!flag)
        return 0;

    for (i = 0; i < number; i++) // 구조체 메모리 초기화 
        people[i] = NullEmpolyee;
    
    printf("-------------------\n");
    printf("사원 관리 프로그램 시작\n");
    printf("-------------------\n");
    printf("(1) 사원 등록 insert\n");
    printf("(2) 사원 정보 삭제 delete\n");
    printf("(3) 사원 정보 검색 find\n");
    printf("(4) 부서 평균 급여 조회 avg\n");
    printf("(5) 종료 exit\n");
    printf("-------------------\n");
    
    while (1) {
        gets(input); //프로그램 실행 명령어 입력
        word = strtok(input, " ");

        if (word == NULL)
            break;

        if (strcmp(word, "insert") == 0){
            insert(people, input);
            
        }
        else if (strcmp(word, "delete") == 0) {
            word = strtok(NULL, " ");
            delete_one(people, word);
        }

        else if (strcmp(word, "find") == 0){
            word = strtok(NULL, " ");
            printf("%d\n", find(people, word));
        }

        else if (strcmp(word, "inform") == 0) {
            word = strtok(NULL, " ");
            inform(people, word);
        }

        else if (strcmp(word, "avg") == 0) {
            word = strtok(NULL, " ");
            printf("%d\n", avgBenefit(people, word));
        }

        else if(strcmp(word, "exit") == 0){
            return 0;
            break;
        }

        else{
            printf("다시 입력해주세요.\n");
        }
    }

    free(people);
    return 0;
}


void insert(Employee *people, char *word) {
    int i;
    //비어있는 메모리 검색
    for (i = 0; i < number; i++) {
        if (strcmp(people[i].name, "") == 0)
            break;
    }

    if (i == number) {
        printf("메모리 부족\n");
        return;
    }

    word = strtok(NULL, " ");
    strcpy(people[i].name, word);

    word = strtok(NULL, " ");
    people[i].age = atoi(word);

    word = strtok(NULL, " ");
    people[i].salary = atoi(word);

    word = strtok(NULL, " ");
    strcpy(people[i].department, word);
}

void delete_one(Employee *people, char *word) {
    int i;
    //int count=0;

    for(i=0; i<number; i++){
        if(strcmp(people[i].name, word)==0){
            printf("%s 사원의 정보를 삭제했습니다.\n", word);
            strcpy(people[i].name, "");
            strcpy(people[i].department, "");
            people[i].age = -1;
            people[i].salary = -1;

            //count++;
        }
    }

    // for(int j=0; j<number-count; j++){
    //     if(strcmp(people[j].name, "") != 0){
    //           for(int i=0; i<number; i++){
    //             strcpy(people[i].name, people[j].name);
    //             strcpy(people[i].department, people[j].department);
    //             people[i].age = people[j].age;
    //             people[i].salary = people[j].salary;
    //         }
    //     }
    // }
    
}

int find(Employee *people, char *word) {
    int cnt =0;
    int i;

    for(i=0; i<number; i++){
        if(strcmp(people[i].name, word)==0){
            printf("%s 사원의 정보를 찾았습니다. \n", word);
            printf("성명: %s \n", people[i].name);
            printf("나이: %d \n", people[i].age);
            printf("급여: %d \n", people[i].salary);
            printf("부서: %s \n", people[i].department);
            cnt = 1;
            break;
        };
    };

    if(cnt==0){
        printf("%s 사원의 정보가 없습니다. \n", word);
        return -1;
    }

    return i;
}

void inform(Employee *people, char *word) {
    int i;
    int count =0;

    for(i=0; i<number; i++){
       
        if(strcmp(people[i].name, word)==0){
            printf("%d 세의 %s 사원\n",people[i].age, people[i].name);
            count++;
        }
    }
    printf("검색결과는 총 %d 개 입니다.\n", count);
}

int avgBenefit(Employee *people, char *word) {
    int i;
    int sum =0;
    int avg=0;
    int count=0;

    for(i=0; i<number; i++){
        if(strcmp(people[i].department, word)==0){
            sum += people[i].salary;
            count++;
        }
    }
    avg = sum/count;
    
    if(avg>0){
        printf("%s 부서에 속한 사원들의 급여 평균 : ", word);
        return avg;
    }
    else return 0;
}

