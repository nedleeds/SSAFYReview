#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Dijkstra
1. ���� Ȯ������ ���� node�� �� ���� �����(���������� ����) node�� �ϳ� select
2. select�� node�� ������� �� �� �ִ� ��� node�� ���� �Ÿ��� ����
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

	vector<Node> adjList[10]; // ���� ����Ʈ

	// 1. �׷��� ����
	for (int i = 0; i < cntEdge; i++) {
		int from;
		cin >> from >> node.to >> node.cost;
		adjList[from].push_back(node);
		adjList[node.to].push_back({ from, node.cost });
	}

	// 2. �ʿ��� data 
	//    : ** ���������κ����� �Ÿ� ** + Ȯ�� ����

	// �Ÿ� �ʱ�ȭ - �ּҸ� ������Ʈ : �ִ밪���� �ʱ�ȭ.
	// �� ������ �Ÿ��� �˰� ���� ����. �ٷ�, ������!! �Ÿ� 0.
	int dist[10];
	for (int i = 1; i <= cntNode; i++) {
		dist[i] = 2134567890;
	}
	dist[1] = 0;
	// index : node ��ȣ, value : �ش� ���� Ȯ�������°�?
	int checked[10] = { 0, };

	// 3. Dijkstra ����
	// ��ǥ : ��� ������ �ִܰŸ��� �ñ���.
	// ���� �ݺ��� 1�� : �� 1���� Ȯ��.
	// �ܺ� �ݺ��� cntNode�� : ��ü ��尳�� ���ؼ� Ȯ��.

	for (int times = 1; times < cntNode; times++) {
		int now = -1; // <- �̹��� Ȯ���� ��(���������κ��� ���� ����� ��)
		int minDist = 2134567890;

		// 1) ���� Ȯ������ ���� node�� �� ���� ����� ��� �ϳ� �����ϱ�.
		for (int i = 1; i <= cntNode; i++) {
			if (dist[i] < minDist && checked[i] == 0) {
				minDist = dist[i];
				now = i;
			}
		}
		checked[now] = 1; // ���������ϱ� Ȯ��.

		for (int i = 0; i < adjList[now].size(); i++) {
			Node next = adjList[now][i];
			if (dist[now] + next.cost > dist[next.to])
				continue;
			dist[next.to] = dist[now] + next.cost;
		}
	}

	return 0;
}