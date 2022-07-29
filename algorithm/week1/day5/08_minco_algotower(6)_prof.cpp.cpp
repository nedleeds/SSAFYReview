#include <iostream>
using namespace std;

// 럭셔리 여행

// 인접행렬 
int mat[10][10];
// n
int n;
// 시작과 끝 
int st, en;
// 방문기록 배열 
int visited[10];
// 각 경로의 누적 비용 저장할 변수 
int sum = 0;
// 최소비용 기록할 변수
int mincost = 2134567890;
// 최대비용 기록할 변수 
int maxcost = -2134567890;

void dfs(int node) {

    // 기저 조건 (옵션) 
    // 만약 지금 내가 도착지에 도달했다면
    // 더 가볼필요 없이 돌아가서 다른 경로를 찾아봐라!
    if (node == en) {
        // en까지 왔을떄 -> 최소 비용과 최대 비용을 같이 갱신
        // 여기까지 오기 위해 지나쳐온 경로의 누적 비용이 
        // 현재까지 기록된 최대비용보다 크면
        if (sum > maxcost)
            // 최대값을 갱신
            maxcost = sum;
        // 현재까지 기록된 최소 비용보다 작으면
        if (sum < mincost)
            // 최소값 갱신
            mincost = sum;
        return;
    }

    // dfs 구성
    for (int i = 0; i < n; i++) {
        // 가지치기 

        // 1. 갈 수 있는가?
        if (mat[node][i] == 0)
            continue;

        // 2. 방문을 한적이 있는가? 
        if (visited[i] == 1)
            continue;

        // 들어갈떄 방문 기록
        visited[i] = 1;

        // 들어갈때 : 다음 노드로 가는 비용 누적
        sum += mat[node][i];

        // 다음 노드로 가봐라!
        dfs(i);

        // 해제 -> 모든 경로 들러볼떄 (Backtracking)
        visited[i] = 0;

        // 나올때 : 다음 노드로 가는 비용 누적
        sum -= mat[node][i];

    }
}

int main() {
    // input
    cin >> n;
    // 인접행렬 입력 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    // 시작과 끝 입력
    cin >> st >> en;

    // solve 
    // DFS + backtracking 
    // 완전탐색 -st node부터 시작
    // 시작 노드 방문기록 
    visited[st] = 1;
    dfs(st);
    cout << mincost << '\n' << maxcost;
}