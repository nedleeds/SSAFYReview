#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Dijkstra
1. 아직 확정하지 않은 node들 중 가장 가까운(시작점으로 부터) node를 하나 select
2. select한 node를 기반으로 갈 수 있는 모든 node에 대한 거리를 갱신
*/

/*
8
11
1 2 10
1 5 1
2 3 5
3 5 2
3 6 4
3 7 8
3 4 6
4 8 11
5 6 7
6 7 9
7 8 3
*/
struct Node {
	int to, cost;
}node;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	vector<Node> adjList[10]; // 인접 리스트

	// 1. 그래프 구성
	for (int i = 0; i < cntEdge; i++) {
		int from;
		cin >> from >> node.to >> node.cost;
		adjList[from].push_back(node);
		adjList[node.to].push_back({ from, node.cost });
	}

	// 2. 필요한 data 
	//    : ** 시작점으로부터의 거리 ** + 확정 유무

	// 거리 초기화 - 최소를 업데이트 : 최대값으로 초기화.
	// 딱 한점은 거리를 알고 시작 가능. 바로, 시작점!! 거리 0.
	int dist[10];
	for (int i = 1; i <= cntNode; i++) {
		dist[i] = 2134567890;
	}
	dist[1] = 0;
	// index : node 번호, value : 해당 점을 확정지었는가?
	int checked[10] = { 0, };

	// 3. Dijkstra 구현
	// 목표 : 모든 점들의 최단거리가 궁금해.
	// 내부 반복문 1번 : 점 1개를 확정.
	// 외부 반복문 cntNode번 : 전체 노드개에 대해서 확정.

	for (int times = 1; times < cntNode; times++) {
		int now = -1; // <- 이번에 확정할 점(시작점으로부터 가장 가까운 점)
		int minDist = 2134567890;

		// 1) 아직 확정하지 않은 node들 중 가장 가까운 노드 하나 선택하기.
		for (int i = 1; i <= cntNode; i++) {
			if (dist[i] < minDist && checked[i] == 0) {
				minDist = dist[i];
				now = i;
			}
		}
		checked[now] = 1; // 선택했으니깐 확정.

		for (int i = 0; i < adjList[now].size(); i++) {
			Node next = adjList[now][i];
			if (dist[now] + next.cost > dist[next.to])
				continue;
			dist[next.to] = dist[now] + next.cost;
		}
	}

	return 0;
}