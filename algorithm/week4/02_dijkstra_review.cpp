#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int to, cost;
}node;
vector<Node> adjList[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;


	// 1. set graph
	for (int i = 0; i < cntEdge; i++) {
		int from;
		cin >> from >> node.to >> node.cost;
		adjList[node.to].push_back({ from, node.cost });
	}

	// 2. 필요한 data : **시작점으로부터의 거리** + 확정유무
	int dist[10] = {0,};
	for (int i = 1; i < cntNode; i++)
		dist[i] = 2134567890;
	dist[1] = 0;
	// 확정됐나?-> DAT[해당번호] : 확정유무
	int checked[10] = { 0, };


	// 3. Dijkstra 구현
	// 목표 : 모든 점들의 최단 거리가 궁금
	// 내부 반복문 1번 : 점 1개를 확정
	// 외부 반복문 cntNode 번 : 전체 노드개에 대해 확정
	for (int times = 1; times < cntNode; times++) {
		int now = -1; // 이번에 확정할 점 (시작점에서 가장 가까운점)
		int minDist = 2134567890;

		// 1) 아직 확정 안한 node 중 가장 가까운 노드하나 선택
		for (int i = 1; i <= cntNode; i++) {
			if (dist[i] < minDist && checked[i] == 0) {
				minDist = dist[i];
				now = i;
			}
		}
		checked[now] = 1; // 선택했으니깐 확정

		for (int i = 0; i < adjList[now].size(); i++) {
			Node next = adjList[now][i];
			if (dist[now] + next.cost > dist[next.to])
				continue;
			dist[next.to] = dist[now] + next.cost;
		}
	}

	return 0;
}