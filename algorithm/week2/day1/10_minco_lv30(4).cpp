#include <iostream>
#include <queue>
using namespace std;

int adj_mtx[6][6] = {
	// 0  1  2  3  4  5
	  {0, 0, 0, 0, 1, 0},   // 0
	  {1, 0, 1, 0, 0, 1},	// 1
	  {1, 0, 0, 1, 0, 0},   // 2
	  {1, 1, 0, 0, 0, 0},	// 3
	  {0, 1, 0, 1, 0, 1},	// 4
	  {0, 0, 1, 1, 0, 0},	// 5
};

int visited[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	queue<int> q;
	int start;

	cin >> start;
	visited[start] = 1;
	q.push(start);
	cout << start << '\n';

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next = 0; next < 6; next++) {
			if (adj_mtx[now][next] == 0) continue;
			if (visited[next] != 0) continue;

			cout << next <<'\n';
			visited[next] = 1;
			q.push(next);
		}
	}

	return 0;
}