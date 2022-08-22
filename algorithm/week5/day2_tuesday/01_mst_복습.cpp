#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
* MST
* cost가 낮은 edge부터 연결(그룹화)
* 단, 이미 같은 그룹에 속한 edge면 '무시'
* ㄴ> 구현
*	ㄴ> 'cost가 낮은' : sort / priority queue
*	ㄴ> '연결(그룹화)' : Union(V) / Find
*	ㄴ> '같은 그룹에 속한' : Union(V) / Find
*/
int parents[10001];
int memberCnt[10];
struct Edge { int from, to, cost; };
vector<Edge> edges;

bool cmp(Edge a, Edge b) {
	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
	return false;
}

int Find(int now) {
	if (parents[now] == now)
		return now;

	parents[now] = Find(now);
	return parents[now];
}

void Union(int a, int b) { // 그룹에 변화
	int aRoot = Find(a);
	int bRoot = Find(b);

	if (aRoot == bRoot) return; // why? 
	// 대표가 같으면 합쳐져 있는 상태이기 때문

	// 이 부분부터는 a, b가 다른 그룹인 상태
	parents[bRoot] = aRoot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	// Union-Find 변수 초기화
	for (int i = 1; i <= cntNode; i++)
		parents[i] = i;

	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.push_back({ from, to, cost });
	}
	
	// 정렬
	sort(edges.begin(), edges.end(), cmp);

	// cost가 작은 것부터 연결
	int sum = 0; // 최대한 적은 비용으로 모든 node를 연결했을 때의 비용
	for (int i = 0; i < edges.size(); i++) {
		//i번째 edge가 연결하는 두 node
		int from = edges[i].from;
		int to = edges[i].to;

		// 이미 from과 to가 같은 그룹일 수 있다.
		// 그럴 경우 무시해야돼
		if (Find(from) == Find(to)) continue;

		Union(from, to); // from과 to를 하나의 그룹으로 만듦
		sum += edges[i].cost;
	}

	return 0;
}