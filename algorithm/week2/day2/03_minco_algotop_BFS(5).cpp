#include <iostream>
#include <queue>
using namespace std;

int adjMtx[101][101];
int visited[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode, numEdge;
	cin >> numNode >> numEdge;

	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjMtx[from][to] = 1;
	}

	int coco, somebody;
	cin >> coco >> somebody;

	queue<int> q;
	q.push(coco);
	visited[coco] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next = 0; next < numNode; next++) {
			if (adjMtx[now][next] == 0) continue;
			if (visited[next] = 1) continue;
		}

	}

	return 0;
}