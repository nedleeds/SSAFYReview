#include <iostream>
#include <vector>
using namespace std;

// 인접 행렬 가중치 DFS 

/*
5 6
1 2 10
1 3 3
1 4 7
3 4 5
2 5 8
4 5 9
*/

// 1->2 
// mat[1][2] = 비용
/*
{0, 10, 3, 7, 0},
{10, 0, 0, 0, 8},
{3, 0, 0, 5, 0}, 
{7, 0, 5, 0, 9},
{0, 8, 0, 9, 0}
*/

// 인접 행렬
int mat[10][10]; 
int n, m; 
// used --> DAT
// index : 노드 번호
// value : 방문했는가? (0: X, 1 : O) 
int visited[10]; 
vector<int>path; 
int sum = 0; // 경로의 비용을 누적

int minval = 2134567890; 

void dfs(int node) {

    // 기저조건 <-- 더이상 필수 사항 (옵션)
    // 5번 노드에 도달했을때 경로를 출력
    if (node == 5) {
        cout << "PATH : ";
        // 지금 경로를 한번 출력
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << '\n';
        cout << "COST: " << sum << '\n';

        if (sum < minval)
            minval = sum; 

        return; 
    }

    // dfs 구성 
    for (int i = 1; i <= n; i++) {
        int next = i; 

        // 가지치기 --> 내가 다음 노드(next)에 접근할수 있을까? 
        // 접근을 할 필요가 없는 / 하지 못하는 "가망성이 없는 노드"라면 skip 
        // 1. 갈수 있는가?
        // 가중치가 포함되도, 갈수 없는 노드 = 0으로 기록 
        if (mat[node][next] == 0)
            continue;
        // 2. 방문을 한적이 있는가? 
        if (visited[next] == 1)
            continue;

        // **가지치기 추가 (최소비용일때)
        // 이미 내가 다음 노드를 가는데 비용이 최소비용보다 초과되면 이 루트는 가볼 필요가 없다
        // (가망성 없음)
        // 지금까지 온 노드에서 + 다음 노드까지의 비용 > 지금까지의 최소 비용보다 크다면? 
        if (sum + mat[node][next] > minval)
            // 가볼 필요가 없는거죠.
            continue;

        // 다음 노드 들어갈때 수행 
        // 1. 방문 기록 -> 내가 next노드로 갈것이다!
        visited[next] = 1;
        // 2. 경로 기록 
        path.push_back(next);
        // 3. node(출발) -> next(도착)까지의 비용을 누적 
        sum += mat[node][next];

        // 검증이 완료되었으니 -> 다음 노드로 들어가라! 
        dfs(next);

        // 노드를 빠져 나올때 수행 
        // 1. 방문 기록 해제 (완전탐색을 위해)
        visited[next] = 0;

        // 2. 경로도 해제 
        path.pop_back(); 

        // 3. 나올때 -> 비용 누적을 해제
        sum -= mat[node][next];
    }
}

int main() {
    // input 
    // n : node 개수
    // m : 간선 개수 
    cin >> n >> m; 
    // 간선 개수만큼 입력 
    for (int i = 0; i < m; i++) {
        int from, to, cost; 
        cin >> from >> to >> cost;
        // 간선에 가중치가 포함되었으니 
        // from -> to / to -> from으로 가기 위해서는 cost만큼의 비용이 발생한다!
        mat[from][to] = cost;
        mat[to][from] = cost; 
    }

    // dfs 
    // 들어가기 전에 해줘야 할게 1~2가지
    // 1. 시작 노드 -> 방문 기록
    // 시작 노드  :1 -> 1번 노드 방문 기록 
    visited[1] = 1; 
    // 2. 경로를 기록 -> path에도 시작 노드를 기록 
    path.push_back(1);
    // 완전탐색 1번 노드부터 
    dfs(1); 

    cout << "최소비용 : " << minval;
}