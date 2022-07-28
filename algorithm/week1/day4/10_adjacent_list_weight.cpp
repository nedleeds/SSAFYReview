#include <iostream>
#include <vector>
using namespace std;

// struct -> 구조체 (여러분이 새로운 자료구조)
// 우리가 필요한 것 : Edge 
// --> 이 간선은 무엇을 알고있어야 하는가? 
// --> 1. 어떤 노드로 가는가? (노드의 번호) -> int 
// --> 2. 그 노드까지의 비용은 얼마인가? (비용) -> int 

// 인접 리스트 가중치 DFS 

// 완전 탐색 : --> 시간이 진짜 오래 걸림 O(N!) 
// ---> 기본 완점탐색 문제를 만나게 되면 
// -> N 크기는 항상 확인 
// --> N이 작다? 
// --> N이 크다? --> 에너지를 쏟아야 하는 부분 : 어떻게 경로를 줄일수 있는가? (가지치기)
//     --> DP 

/*
5 6
3 4 5
2 5 8
4 5 9
1 3 3
1 2 10
1 4 7
*/

struct Edge {
    // 1. 번호
    int num;
    // 2. 비용 
    int cost;
};

// Edge를 저장할수 있는 인접 리스트
vector<Edge>v[10]; 
vector<int> path;
int visited[10]; 
int n, m; 
int sum = 0; 

// 최대값 최소값
// int ~ -21억~ 21억 
int minval = 2134567890; 

// 코테 -> 진짜 엄청난 값들은 잘 안나오긴 함 
// 범위 터졌는지 확인 방법
// --> 테케 넣었을때 -> 10 -> 7개는 잘나오는데 3개가 갑자기 음수값 --> 범위 터진 것 

void dfs(int node) {
    // 기저조건 (옵션)
    if (node == 5) {
        cout << "PATH : ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << '\n';
        cout << "COST: " << sum << '\n';

        // 최소비용 갱신
        if (sum < minval)
            minval = sum; 
    }

    // dfs 구성
    // 인접리스트 : vector부분에 지금 노드로부터(node) -> 갈수있는 노드만 저장되어있음. 
    for (int i = 0; i < v[node].size(); i++) {
        // 가지치기 X -> 인접행렬에서는 못가는 노드 걸러줬지만 -> 여기서는 할 필요 X
        // Edge에는 2가기 값
        // num -> 노드 번호 (접근 : next.num)
        // cost -> 비용 (접근 : next.cost)

        Edge next = v[node][i];

        // 다음 노드 갈수 있는가? 
        if (visited[ next.num ] == 1)
            continue;

        // 추가 가지치기
        // 지금 노드까지 오는 비용 + 이 간선을 타고 다음 노드까지 가는 비용 > 지금까지 기록된 최소비용
        if (sum + next.cost > minval)
            // 가망성이 없는 루트다!
            continue;

        // 들어갈때
        // 1. 방문기록
        visited[next.num] = 1;
        // 2. path 기록 
        path.push_back(next.num);
        // 3. 비용 기록 
        sum += next.cost;

        dfs(next.num);


        // 나올 때
        // 1.방문 기록 해제
        visited[next.num] = 0;
        // 2. path 기록 해제 
        path.pop_back();
        // 3. 비용 해제 
        sum -= next.cost;
    }
}

int main() {
    // input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost; 
        cin >> from >> to >> cost; 
        // {번호, cost}
        v[from].push_back({ to, cost });
        // 양/무방향 연결 
        v[to].push_back({ from, cost });
    }

    visited[1] = 1;
    path.push_back(1);
    // 완전탐색 
    dfs(1);
    cout << minval; 
}