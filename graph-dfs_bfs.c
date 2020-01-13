#include <stdio.h>
/*
    Graph Search? 하나의 vertex에서 시작해 모든 vertice를 한 번 씩 방문하는 것 
    => 방문여부를 반드시 확인 visit[]
    => 확인하지 않으면 무한 루프 빠질 수 있음
    
    BFS (Breadth First Search)---------------------
    시작 v에서 가까운 v를 먼저 방문하고 먼 v를 나중에 방문하는 순회
    사용예: 두 노드 사이의 최단경로, 임의의 경로를 찾는 경우
    방문한 노드를 차례대로 저장하고 꺼낼 수 있는 자료구조인 Queue 사용(FIFO)
   
    DFS (Depth First Search)----------------------
    시작 v에서 한 방향으로 갈 수 있을만큼 계속 가다가 더이상 갈 수 없으면 backtracking해서 다른 방향으로 다시 탐색
    사용예: 모든 노드를 방문해야하는 경우
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

 //v: starting vertex number, loopCnt: for-loop count 
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
