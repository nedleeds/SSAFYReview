#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge { int to, cost; };

bool operator < (Edge a, Edge b) {
	// less - MAX heap: default (��������)
	//		- MIN heap: return �ݴ�� �ϸ� �� (��������)
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;

	if (a.to < b.to) return false;
	if (a.to > b.to) return false;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// �Է�1
	int numNode, numEdge;
	cin >> numNode >> numEdge;

	// �Է�2
	vector<Edge> adjList[2001];
	for (int i = 0; i < numEdge; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		adjList[from].push_back({ to, cost });
	}

	// initialization
	// 1. pq setting
	priority_queue<Edge, vector<Edge>>  pq;
	pq.push({ 0, 0 });
	// 2. initialization
	int costs[20001];
	int visited[20001] = { 0, };
	for (int i = 0; i < numNode; i++)
		costs[i] = 2134567890;
	costs[0] = 0;

	
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// Ȯ���� �� �־�?
		if (visited[now.to] == 1) continue;
		visited[now.to] = 1; // ������ Ȯ��

		// Ȯ���� now ������� next üũ !
		for (int i = 0; i < adjList[now.to].size(); i++){
			Edge next = adjList[now.to][i];
			if (costs[now.to] + next.cost > costs[next.to]) continue;

			costs[next.to] = costs[now.to] + next.cost;
			pq.push({ next.to, costs[next.to] });
		}
	}

	if (visited[numNode - 1] != 0)
		cout << costs[numNode - 1] << '\n';
	else
		cout << "impossible\n";


	return 0;
}
/* 
---------------[�� ����]---------------
** ���� ������ �뼱�� ��� **
�ּ� ����ġ�� ������ ��� ã�� --> Dijkstra

[�Է�]
1.	numNode, numEdge (1<= numNode <=20000, 1<=T<=300000)
	-> node : 0 ~ N-1
2.	numEdge ��ŭ �Է� 
	-> (from, to, cost)

[���]
1. �� �� �ִ� ���� ���ٸ�, "Impossible"
2. 0�� -> N-1 ��忡 �����ϴ� �ּ� ��� 

[����]
*** Dijkstra �� ���� ***
1.	�Է�: ���� ����Ʈ ����
2.	ť ����
3.	���� �� ����: costs, visited, pq.push()
4.	now: 
	-> front + pop
	-> continue: visited[next] == 1 (�̹� Ȯ��)
5.	next checking
	-> continue: dist[now] + adj[next] > dist[next]
6.	q.push()
7.	iterate (4. ~ 6.) till pq is empty.

!!!!!!!!!!!!!!!! Dijkstra���� �Ǽ��� �κ� !!!!!!!!!!!!!!!!
Line 62 ~ 63������
	costs[next.to] = costs[now.to] + next.cost;
	pq.push({ next.to, costs[next.to] });

���⼭ next�� Edge�� �״�� �޾ƿͼ�
	pq.push(next); 

��� �ϴ� �ٶ��� testcase���� 1���� ��� �ɷ���
���������, next�� ������ ����� cost���� ���ְ�,
��� ��θ� ���� �ּ� ����ġ�� ���� ������Ʈ�� �ȵ� ��Ȳ.
����
next.costs = costs[next.to] �� ������Ʈ�� ���ְ� next�� �ְų�,
pq.push({next.co, costs[next.to]}) �� ������Ʈ �� ���� �ֵ��� ������Ѵ�.

*/