#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> path;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

    int numNode, numEdge, costLimit;
    cin >> numNode >> numEdge >> costLimit;

    int arr[10][10] = { 0, }; // 인접 행렬
    for (int i = 0; i < numEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from][to] = cost;
    } // 1. 그래프 구성

    // 2. Queue 생성
    queue<int> q; // queue에 넣는 정보 : node정보
    int cost[10] = { 0, }; // index : 노드 번호, value : 해당 node까지의 비용

    // 3. 시작노드 세팅
    cost[0] = 0;
    q.push(0); // 1번점이 시작점이므로 넣어줌

    //7. 4~6단계 반복
    while (!q.empty()) // queue가 비워지지 않았다 : 감염 시켜나갈 예정인 node가 남았다.
    {
        //4. queue에서 node(now)를 하나 꺼냄
        int now = q.front(); // now : 이번에 감염을 시켜나갈 node
        q.pop();

        

        // 5. now에서 갈 수 있는 node(next)들 찾기
        for (int next = 1; next <= 9; next++)
        {
            if (arr[now][next] == 0) continue; // now->next로 가지 못하면 무시

            // now가 next를 감염시킬 수 있다.
            // -------- 새로운 next라는 점을 찾았다.

            // 6. next들을 queue에 추가
            cost[next] = cost[now] + arr[now][next];

            if (cost[next] > costLimit) continue;
            path.push_back(next);
            q.push(next);
        }
    }

    for (int i = 0; i < path.size()-1; i++) {
        for (int j = i + 1; j < path.size(); j++) {
            if (path[i] > path[j]) {
                int tmp = path[i];
                path[i] = path[j];
                path[j] = tmp;
            }
        }
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }

    // 들렸을 때 처리 : now만보고 계산 할 수 있을 때
    // 찾았을 때 처리 : now,next의 두가지를 같이 확인할때
    // next까지의 거리 = now까지의 거리 + (now->next)의 거리    <= (처리, 계산) now,next


    return 0;
}