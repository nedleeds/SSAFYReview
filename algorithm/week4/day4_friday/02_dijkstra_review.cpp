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

	// 2. �ʿ��� data : **���������κ����� �Ÿ�** + Ȯ������
	int dist[10] = {0,};
	for (int i = 1; i < cntNode; i++)
		dist[i] = 2134567890;
	dist[1] = 0;
	// Ȯ���Ƴ�?-> DAT[�ش��ȣ] : Ȯ������
	int checked[10] = { 0, };


	// 3. Dijkstra ����
	// ��ǥ : ��� ������ �ִ� �Ÿ��� �ñ�
	// ���� �ݺ��� 1�� : �� 1���� Ȯ��
	// �ܺ� �ݺ��� cntNode �� : ��ü ��尳�� ���� Ȯ��
	for (int times = 1; times < cntNode; times++) {
		int now = -1; // �̹��� Ȯ���� �� (���������� ���� �������)
		int minDist = 2134567890;

		// 1) ���� Ȯ�� ���� node �� ���� ����� ����ϳ� ����
		for (int i = 1; i <= cntNode; i++) {
			if (dist[i] < minDist && checked[i] == 0) {
				minDist = dist[i];
				now = i;
			}
		}
		checked[now] = 1; // ���������ϱ� Ȯ��

		for (int i = 0; i < adjList[now].size(); i++) {
			Node next = adjList[now][i];
			if (dist[now] + next.cost > dist[next.to])
				continue;
			dist[next.to] = dist[now] + next.cost;
		}
	}

	return 0;
}