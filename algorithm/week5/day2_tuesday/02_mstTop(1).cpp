#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parents[10001];
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

	parents[now] = Find(parents[now]);
	return parents[now];
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int bRoot = Find(b);

	if (aRoot == bRoot) return;

	parents[bRoot] = aRoot;
}

int main() {

	int numNode, numEdge;
	cin >> numNode >> numEdge;

	// init parents
	for (int i = 1; i <= numNode; i++)
		parents[i] = i;

	for (int i = 0; i < numEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.push_back({ from, to, cost });
	}

	// sort edges
	sort(edges.begin(), edges.end(), cmp);

	int sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		// cost가 작은 것부터 연결
		int from = edges[i].from;
		int to = edges[i].to;

		if (Find(from) == Find(to)) continue;

		Union(from, to);
		sum += edges[i].cost;
	}
	cout << sum;
	return 0;
}