#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to, cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	vector<Edge> v[10];
	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}//1. �׷��� ����

	// 2. �ʿ��� ������ - �Ÿ�, Ȯ������
	// ã�Ҵ� �Ÿ��� �߿��� ���� ª�� �Ÿ�
	// priority_queue �ֽ�?
	// �켱������ ���� �� �ְ�, �̴�� data�� ���� �� �ִ�.
	priority_queue<Edge> pq;

	int used[10] = { 0, }; // Ȯ���ߴ°�?
	int dist[10]; // �Ÿ� �ʱ�ȭ
	for (int i = 1; i <= cntNode; i++)
		dist[i] = 2134567890;

	// 3. ������ ����
	dist[1] = 0;
	pq.push({ 1, 0 });

	// 7. 4~6�ܰ� �ݺ�
	// cntNode -> 1�� ������ ó���ϸ� x 
	while (!pq.empty()) {
		// 4. now������
		// 1) Ȯ���� �ȵ� �� �� ���� ����� ��(now)�ϳ� ����
		int now = pq.top().to;
		int nowDist = pq.top().cost;
		pq.pop();

		if (used[now] == 1) continue; // �̹� Ȯ���� ��

		used[now] = 1; // �� Ȯ��

		// 5. next -> next
		// 1) Ȯ���� now�� ������� next�� ���� -> ���ο� �� ã�Ҵ�
		for (int i = 0; i < v[now].size(); i++) {
			Edge edge = v[now][i];
			int next = edge.to;
			int edgeDist = edge.cost; // now -> next�� ���� ���(�Ÿ�)
			if (dist[now] + edgeDist > dist[next]) continue;

			// 6. next ��� update
			dist[next] = dist[now] + edgeDist;
			pq.push({ next, dist[next] });

		}

		int forDebug = 1;
		return 0;
	}

	return 0;
}