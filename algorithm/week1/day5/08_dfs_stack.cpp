#include<iostream>
#include<stack> 
using namespace std;

int MAP[5][5] = {
    {0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

// stack dfs
stack<int> s;
int visited[10];

void dfs(int node) {

    visited[node] = 1;
    s.push(node);
    cout << node << " ";

    while (!s.empty()) {
        // 지금 노드
        int now = s.top();

        // 갈 수 이있는 노드가 있는지 확인하기 위한 변수 
        int flag = 0;

        // 인접행렬과 동일하게 내려갈 수 있는 노드 확인 
        for (int i = 0; i < 5; i++) {

            // 갈 수 없다면 continue 
            if (MAP[now][i] == 0)
                continue;

            // 방문한적이 있다면 continue
            if (visited[i] == 1)
                continue;

            // 출력
            cout << i << " ";

            // ---- 여기까지 왔다면 -> 갈수 있는 노드다!
            s.push(i);
            visited[i] = 1;
            // 가볼수 있는 노드가 있다면
            flag = 1;
            break;
        }
        // 다 체크해봤는데, 가볼수 있는 노드가 더 없네요? 
        // 그렇다면 지금 접근하고있는 노드의 스택을 해제
        if (flag == 0) {
            s.pop();
        }
    }
}

int main() {
    // dfs -> 0번 노드부터
    dfs(0);
}