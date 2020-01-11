#include <stdio.h>
/*
    BFS ---------------------
    지나온 노드 순서대로 출력
    queue 사용 FIFO (단, queue는 1부터 사용)
    v: starting vertex number
    loopCnt: for loop count 

    DFS ----------------------
    연결된 노드 따라 출력
    recursive algorithm
*/

int graph[10][10] =
    {{0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};
int visit_dfs[10] = {0,0,0,0,0,0,0,0,0,0};
int visit_bfs[10] = {0,0,0,0,0,0,0,0,0,0};
int queue[11];
int count = 0; 

void dfs(int v, int loopCnt) {
    visit_dfs[v] = 1;
    count++; // recursiveness count

    // print DFS
    if(v == 0 ) printf("DFS:");

    printf("%d > ", v);

    if(count == loopCnt) printf("Finish\n");
    

    for(int j = 0; j < loopCnt; j++ ){ //v 행의 연결된 노드 확인
        if((graph[v][j] == 1)&&(visit_dfs[j] != 1)){ //j열이 1이면 recursive 수행
            dfs(j,loopCnt);
        }
    }
    
    return;
}

void bfs(int v, int loopCnt) {
    int front = -1;
    int rear = -1;

    rear++;
    queue[rear] = v; //start vertex = 0
    visit_dfs[v] = 1;
    printf("BFS:");
    printf("%d > ", v);

    while(front < rear){
        front++;
        int i = queue[front]; //front 값을 1 올리고, 다음 노드 값(i행)으로 queue[front] 대입

        for(int j=1; j< loopCnt; j++){ 
           if((graph[i][j] == 1)&&(visit_bfs[j] != 1)){ //값이 1이고 방문기록이 없으면
               rear++;
               queue[rear] = j; 
               visit_bfs[j] = 1;

               printf("%d > ", j);
           }
       }   
  
    }

    printf("Finish\n");
   return;
}

int main() {
    dfs(0, 10);
    printf("\n");
    bfs(0, 10);
}
