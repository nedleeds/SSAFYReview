#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
// 고려사항
1. 갔던 점을 또 가게 되는가? (찾았던 점을 또 찾게 되는가????) <- usedDFS로 해결
2. 2차원 맵(주의 사항) : 맵을 벗어나는 좌표가 계산되는가?
*/

/*
Flood Fill
2차원 맵에서 탐색하며 정보들을 계산하여 채워나가는 방식
상하좌우로 이동이 가능하다.

첫 줄에 맵의 크기(N)
이어진 N개의 줄에 걸쳐 N개의 숫자들이 주어지며, 맵에 대한 정보가 주어짐
5
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
*/

/*
공통점
완전 탐색이다(모든 점을 확인할 수 있다.)
- > 모든 점을 1번씩만 들리면 땡 : 아무거나 사용해도 OK

차이점
DFS : 길든 짧든 일단 모든 경로를 다 만들어야 하는 상황
BFS : 제일 적은 node를 들려가는 방법을 구해야 하는 상황
*/


struct Node {
    int row;
    int col;
};


// 다양한 경로를 모두 해보는 알고리즘 : DFS

int MAPsize;
int MAP[10][10] = { 0, };

int usedDFS[10][10] = { 0, }; // 찾은 적 있는가?

void dfs(int nowRow, int nowCol) // now에 있다. // Node now
{
    if (nowRow == MAPsize - 1 && nowCol == MAPsize - 1)
        return; // 끝점 세팅
    //now에서 갈 수 있는 next로 가라!
    // 상하좌우 4개의 방향으로 계산
    int dr[] = { 0,0,-1,1 }; // <----- break point, F5를 눌러가며 확인
    int dc[] = { -1,1,0,0 };
    for (int i = 0; i < 4; i++) {
        int nextRow = nowRow + dr[i];
        int nextCol = nowCol + dc[i];
        if (nextRow < 0 || nextCol < 0 || nextRow >= MAPsize || nextCol >= MAPsize)
            continue; // 맵을 벗어나는 좌표면 무시
        if (usedDFS[nextRow][nextCol] != 0)
            continue; // next라는 좌표는 찾았던 좌표다. 무시
        if (MAP[nextRow][nextCol] == 1)
            continue; // next가 벽이면 무시

        usedDFS[nextRow][nextCol] = 1; // next라는 좌표를 찾았다. 기록
        dfs(nextRow, nextCol);

        usedDFS[nextRow][nextCol] = 0; // <- 기록 복구(다양한 경로) : BFS와 진짜 차별되는 장점

    }
}

void bfs()
{
    // 2. Queue를 생성
    queue<Node> q; // q에 넣은 정보 : node정보(어떤 node인가? 전염을 시켜나갈 node번호)
                   //                 row, col -> 2개의 정보 -> node 1개
    int usedBFS[10][10] = { 0, };
    // usedBFS[row][col] = row,col을 찾은 적 있는가?
    //        upgrade : row,col은 몇 개의 점을 들려서 갈 수 잇는가?

    // 3. 시작점 세팅
    usedBFS[0][0] = 1; // 0,0은 찾았다. 기록
    q.push({ 0, 0 }); // row = 0, col = 0에서 시작

    // 7. 4 ~ 6 단계 반복
    while (!q.empty()) {
        // 4. now꺼내기
        Node now = q.front(); // <----- break point, F5를 눌러가며 확인
        q.pop();
        // 5. **** now->next찾기 (상하좌우) -> 방향배열
        int dr[] = { 0,0,1,-1 };
        int dc[] = { 1,-1,0,0 };
        for (int i = 0; i < 4; i++)
        {
            int nextRow = now.row + dr[i];
            int nextCol = now.col + dc[i];

            // ------------ 진행해도 되는가?
            // nextRow, nextCol : now 에서 갈 수 있는 다음 점(next)
            if (nextRow < 0 || nextCol < 0 || nextCol >= MAPsize || nextRow >= MAPsize)
                continue; // 맵을 벗어나는 좌표가 계산되면 무시
            if (usedBFS[nextRow][nextCol] != 0) continue; // 어떤 기록이 있는 좌표더라(찾았던 좌표더라) 무시
            if (MAP[nextRow][nextCol] == 1)continue; // 벽이면 무시
            // ------------ 

            // 6. next를 queue에 추가
            usedBFS[nextRow][nextCol] = usedBFS[now.row][now.col] + 1; // nextRow, nextCol을 찾았다. 기록
            q.push({ nextRow, nextCol });
        }
    }
}

int main()
{
    cin >> MAPsize;
    for (int row = 0; row < MAPsize; row++)
        for (int col = 0; col < MAPsize; col++)
            cin >> MAP[row][col];
    usedDFS[0][0] = 1;
    dfs(0, 0);
    bfs();
    return 0;
}