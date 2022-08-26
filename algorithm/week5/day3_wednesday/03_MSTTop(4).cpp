//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int cntRow, cntCol, testCase;
//int MAP[50][50];
//int parent[50];
//struct Node { int row, col, idx; } nodeTo, nodeFrom;
//struct Edge { int from, to, cost; };
//vector<Node> toNodes;
//vector<Edge> edges;
//
//
//int Find(int node) {
//	if (parent[node] == node)
//		return node;
//
//	return parent[node] = Find(node);
//}
//
//int Union(int a, int b) {
//	int aRoot = Find(a);
//	int bRoot = Find(b);
//
//	if (aRoot == bRoot) return;
//
//	parent[bRoot] = aRoot;
//}
//
//bool cmp(Edge a, Edge b) {
//	if (a.cost < b.cost) return true;
//	if (a.cost > b.cost) return false;
//	return false;
//}
//
//int kruskal() {
//	// init parent
//	for (int i = 0; i < 101; i++)
//		parent[i] = i;
//
//	// sort Edge
//	sort(edges.begin(), edges.end(), cmp);
//
//	// for -> till all the edges are connected
//	for (int i = 0; i < edges.size(); i++) {
//		if(Find(nodeFrom, edges[i])
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	cin >> testCase >> cntCol >> cntRow;
//
//	// edge 구성 -> to노드는 idx:1 부터 시작
//	int idxTo = 1;
//	for (int row = 0; row < cntRow; row++) {
//		for (int col = 0; col < cntCol; col++) {
//			cin >> MAP[row][col]; 
//			if (MAP[row][col] == 'A') {
//				Node toNode = { row, col, idxTo };
//				toNodes.push_back(toNode);
//				idxTo++; // A에 대한 노드들 -> idx로 Edge to에 넣고, from 을 S에 idx 0으로 설정!
//			}
//			else if (MAP[row][col] == 'S') {
//				nodeFrom = { row, col, 0}; // 
//			}
//		}
//	}
//
//	// edge 구성 - from - to는 정해졌지만, cost는 아직 미정
//	// cost 값을 col 차이 + row 차이
//
//
//	int ans = kruskal();
//	cout << ans << '\n';
//
//	return 0;
//}