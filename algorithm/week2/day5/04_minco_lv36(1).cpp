#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge { int to, cost; };

bool operator < (Edge a, Edge b) {
	// less - MAX heap: default (내림차순)
	//		- MIN heap: return 반대로 하면 됨 (오름차순)
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;

	if (a.to < b.to) return false;
	if (a.to > b.to) return false;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 입력1
	int numNode, numEdge;
	cin >> numNode >> numEdge;

	// 입력2
	vector<Edge> adjList[2001];
	for (int i = 0; i < numEdge; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		adjList[from].push_back({ to, cost });
	}

	// initialization
	// 1. pq setting
	priority_queue<Edge, vector<Edge>>  pq;
	pq.push({ 0, 0 });
	// 2. initialization
	int costs[20001];
	int visited[20001] = { 0, };
	for (int i = 0; i < numNode; i++)
		costs[i] = 2134567890;
	costs[0] = 0;

	
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// 확정된 적 있어?
		if (visited[now.to] == 1) continue;
		visited[now.to] = 1; // 없으면 확정

		// 확정된 now 기반으로 next 체크 !
		for (int i = 0; i < adjList[now.to].size(); i++){
			Edge next = adjList[now.to][i];
			if (costs[now.to] + next.cost > costs[next.to]) continue;

			costs[next.to] = costs[now.to] + next.cost;
			pq.push({ next.to, costs[next.to] });
		}
	}

	if (visited[numNode - 1] != 0)
		cout << costs[numNode - 1] << '\n';
	else
		cout << "impossible\n";


	return 0;
}
/* 
---------------[내 설계]---------------
** 가장 저렴한 노선의 비용 **
최소 가중치를 가지는 경로 찾기 --> Dijkstra

[입력]
1.	numNode, numEdge (1<= numNode <=20000, 1<=T<=300000)
	-> node : 0 ~ N-1
2.	numEdge 만큼 입력 
	-> (from, to, cost)

[출력]
1. 갈 수 있는 길이 없다면, "Impossible"
2. 0번 -> N-1 노드에 도착하는 최소 비용 

[설계]
*** Dijkstra 로 접근 ***
1.	입력: 인접 리스트 구성
2.	큐 구성
3.	시작 점 세팅: costs, visited, pq.push()
4.	now: 
	-> front + pop
	-> continue: visited[next] == 1 (이미 확정)
5.	next checking
	-> continue: dist[now] + adj[next] > dist[next]
6.	q.push()
7.	iterate (4. ~ 6.) till pq is empty.

!!!!!!!!!!!!!!!! Dijkstra에서 실수한 부분 !!!!!!!!!!!!!!!!
Line 62 ~ 63번에서
	costs[next.to] = costs[now.to] + next.cost;
	pq.push({ next.to, costs[next.to] });

여기서 next를 Edge로 그대로 받아와서
	pq.push(next); 

라고 하는 바람에 testcase에서 1개가 계속 걸렸음
결과적으로, next는 이전에 저장된 cost값이 들어가있고,
모든 경로를 보고 최소 가중치의 값이 업데이트가 안된 상황.
따라서
next.costs = costs[next.to] 로 업데이트를 해주고 next를 넣거나,
pq.push({next.co, costs[next.to]}) 로 업데이트 된 값을 넣도록 해줘야한다.

*/