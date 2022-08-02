#include <iostream>
#include <queue>
using namespace std;

int adj_mtx[10][10];
int visited[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;

	// 1. get the MAP
	for (int r=0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> adj_mtx[r][c];

	// 2. make the queue.
	queue<int> q;

	// 3. set the initial node.
	q.push(0);
	visited[0] = 1;
	cout << 0 << ' ';

	while (!q.empty()) {
		// get the current node 
		int now = q.front();
		q.pop();

		for (int next = 0; next < N; next++) {
			if (adj_mtx[now][next] == 0) continue;
			if (visited[next] != 0) continue;

			cout << next << ' ';

			visited[next] = 1;
			q.push(next);
		}

	}

	return 0;
}