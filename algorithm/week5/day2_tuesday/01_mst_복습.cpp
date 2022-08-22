#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
* MST
* cost�� ���� edge���� ����(�׷�ȭ)
* ��, �̹� ���� �׷쿡 ���� edge�� '����'
* ��> ����
*	��> 'cost�� ����' : sort / priority queue
*	��> '����(�׷�ȭ)' : Union(V) / Find
*	��> '���� �׷쿡 ����' : Union(V) / Find
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

void Union(int a, int b) { // �׷쿡 ��ȭ
	int aRoot = Find(a);
	int bRoot = Find(b);

	if (aRoot == bRoot) return; // why? 
	// ��ǥ�� ������ ������ �ִ� �����̱� ����

	// �� �κк��ʹ� a, b�� �ٸ� �׷��� ����
	parents[bRoot] = aRoot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	// Union-Find ���� �ʱ�ȭ
	for (int i = 1; i <= cntNode; i++)
		parents[i] = i;

	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.push_back({ from, to, cost });
	}
	
	// ����
	sort(edges.begin(), edges.end(), cmp);

	// cost�� ���� �ͺ��� ����
	int sum = 0; // �ִ��� ���� ������� ��� node�� �������� ���� ���
	for (int i = 0; i < edges.size(); i++) {
		//i��° edge�� �����ϴ� �� node
		int from = edges[i].from;
		int to = edges[i].to;

		// �̹� from�� to�� ���� �׷��� �� �ִ�.
		// �׷� ��� �����ؾߵ�
		if (Find(from) == Find(to)) continue;

		Union(from, to); // from�� to�� �ϳ��� �׷����� ����
		sum += edges[i].cost;
	}

	return 0;
}