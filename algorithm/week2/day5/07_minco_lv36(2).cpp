#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int node, cost;
};
vector<Node> adjList[30001];
int dist[30001];

int numNode, numEdge, years;
int cityA, cityB;

bool operator < (Node a, Node b) {
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;
	return false;
}

void dijkstra(Node start, int increment) {
	priority_queue<Node> pq;
	pq.push(start);
	for (int i = 0; i <= numNode; i++)
		dist[i] = 2134567890;

	dist[start.node] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		
		if (dist[now.node] < now.cost)
			continue;

		for (int i = 0; i < adjList[now.node].size(); i++) {
			Node next = adjList[now.node][i];
			int nextCost = dist[now.node] + (next.cost + increment);

			if (dist[next.node] <= nextCost)
				continue;

			dist[next.node] = nextCost;
			pq.push({ next.node, nextCost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> numNode >> numEdge >> years;
	cin >> cityA >> cityB;

	for (int i = 0; i < numEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adjList[from].push_back({ to, cost });
		adjList[to].push_back({ from, cost });
	}

	int increment = 0;
	dijkstra({ cityA, 0 }, increment);
	cout << dist[cityB] << '\n';
	for (int j = 1; j <= years; j++) {
		int x = 0;
		cin >> x;
		increment += x;
		dijkstra({ cityA, 0 }, increment);
		cout << dist[cityB] << '\n';
	}

	return 0;
}