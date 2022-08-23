#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge { int from, to, cost; };
vector<Edge> edges;
vector<char> genders;
int parent[1001];
int cntNode, cntEdge;

bool cmp(Edge a, Edge b) {
	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
	return false;
}

int Find(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = Find(parent[node]);
}

void Union(int a, int b) {
	int aParent = Find(a);
	int bParent = Find(b);

	if (aParent == bParent) return;

	parent[bParent] = aParent;
}

int krusakl() {
	// 1) cost ¼ø Á¤·Ä
	sort(edges.begin(), edges.end(), cmp);

	// 2) gender, cost sum
	int minCost = 0;
	int selectedCntEdge = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (genders[edges[i].from] != genders[edges[i].to]) {
			if (Find(edges[i].from) != Find(edges[i].to)){
				minCost += edges[i].cost;
				Union(edges[i].from, edges[i].to);
				selectedCntEdge++;
			}
		}
	}

	if (selectedCntEdge == cntNode-1) {
		return minCost;
	}
	else {
		return -1;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> cntNode >> cntEdge;

	for (int i = 0; i < cntNode; i++)
		parent[i] = i;

	for (int i = 0; i < cntNode; i++) {
		char gender;
		cin >> gender;
		genders.push_back(gender);
	}

	for (int e = 0; e < cntEdge; e++) {
		int manUniv, womUniv, cost;
		cin >> manUniv >> womUniv >> cost;

		edges.push_back({ manUniv - 1, womUniv - 1, cost });
	}

	int ans = krusakl();
	cout << ans;

	return 0;
}