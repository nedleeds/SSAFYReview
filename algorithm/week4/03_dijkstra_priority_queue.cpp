#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to, cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	vector<Edge> v[10];
	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}//1. 그래프 구성

	// 2. 필요한 데이터 - 거리, 확정여부
	// 찾았던 거리들 중에서 제일 짧은 거리
	// priority_queue 왜써?
	// 우선순위를 정할 수 있고, 이대로 data를 꺼낼 수 있다.
	priority_queue<Edge> pq;

	int used[10] = { 0, }; // 확정했는가?
	int dist[10]; // 거리 초기화
	for (int i = 1; i <= cntNode; i++)
		dist[i] = 2134567890;

	// 3. 시작점 세팅
	dist[1] = 0;
	pq.push({ 1, 0 });

	// 7. 4~6단계 반복
	// cntNode -> 1번 꺼내서 처리하면 x 
	while (!pq.empty()) {
		// 4. now꺼내기
		// 1) 확정이 안된 점 중 가장 가까운 점(now)하나 고르기
		int now = pq.top().to;
		int nowDist = pq.top().cost;
		pq.pop();

		if (used[now] == 1) continue; // 이미 확정된 점

		used[now] = 1; // 점 확정

		// 5. next -> next
		// 1) 확정된 now를 기반으로 next들 갱신 -> 새로운 점 찾았다
		for (int i = 0; i < v[now].size(); i++) {
			Edge edge = v[now][i];
			int next = edge.to;
			int edgeDist = edge.cost; // now -> next로 가는 비용(거리)
			if (dist[now] + edgeDist > dist[next]) continue;

			// 6. next 비용 update
			dist[next] = dist[now] + edgeDist;
			pq.push({ next, dist[next] });

		}

		int forDebug = 1;
		return 0;
	}

	return 0;
}