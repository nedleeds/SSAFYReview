#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge { int from, to, cost; };
vector<Edge> edge;

int parents[10];

bool cmp(Edge A, Edge B) {
	if (A.cost < B.cost) return true;
	if (A.cost > B.cost) return true;
	return false;
}

int Find(int now) {
	if (parents[now] == now)
		return now;
	return parents[now] = Find(now);
}

void Union(int a, int b) {
	int aRoot, bRoot;
	aRoot = Find(a);
	bRoot = Find(b);


}

int main() {

	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i <= nodeCnt; i++) {
		parents[i] = i; //�� ���� node�� ��ǥ�� �ʱ�ȭ
	}

	for (int i = 0; i < edgeCnt; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from, to, cost });
	}

	// ����: cost�� ���� ������
	sort(edge.begin(), edge.end(), cmp);

	// cost�� ���� edge���� ����
	for (int i = 0; i < edge.size(); i++) {

		int from = edge[i].from;
		int to = edge[i].to;
	}


	return 0;
}