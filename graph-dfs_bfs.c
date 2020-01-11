#include <stdio.h>
/*
    BFS ---------------------
    지나온 노드 순서대로 출력
    queue 사용 FIFO (단, queue는 1부터 사용)
    start: starting vertex number
    loopCnt: for loop count 

    DFS ----------------------
    연결된 노드 따라 출력(recursive)
    v: starting vertex number
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
int count = 0; // recursiveness count

void dfs(int v, int loopCnt) {
    visit_dfs[v] = 1;
    count++; 

    // print DFS
    if(v == 0 ) printf("DFS:\n");

    printf("%d > ", v);

    if(count == loopCnt) printf("Finish\n");
    

    for(int j = 0; j < loopCnt; j++ ){ //v 행의 연결된 노드 확인
        if((graph[v][j] == 1)&&(visit_dfs[j] != 1)){ //j열이 1이면 recursive 수행
            dfs(j,loopCnt);
        }
    }
    
    return;
}

void bfs(int start, int loopCnt) {
    visit_dfs[start] = 1;
    queue[1] = 0; //start vertex = 0
    int k = 2; 

   for(int i=0; i<loopCnt; i++){ // i행의 노드에 연결된 노드 확인
       for(int j=start; j< loopCnt; j++){ //i행의 (loopCnt-start)개의 j열 검사
           //printf("%d", graph[i][j]); 
           if((graph[i][j] == 1)&&(visit_bfs[j] != 1)){ //1이고 방문기록이 없으면 queue에 insert, visit[j]=1
               queue[k] = j;
               k++;
               visit_bfs[j] = 1;
           }
       }   
        start++; 
   }
   
   //print BFS
   printf("BFS: \n");
   for(k=1; k<11; k++){
        printf("%d > ", queue[k]);
   }
   printf("Finish\n");

   return;
}

int main() {
    dfs(0, 10);
    printf("\n");
    bfs(0, 10);
}
