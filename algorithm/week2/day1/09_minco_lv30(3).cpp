#include <iostream>
#include <queue>
using namespace std;

int adj_mtx[6][6] = {
	// 0  1  2  3  4  5
	  {0, 1, 0, 0, 1, 0},   // 0
	  {0, 0, 1, 0, 0, 1},	// 1
	  {0, 0, 0, 1, 0, 0},   // 2
	  {0, 0, 0, 0, 0, 0},	// 3
	  {0, 0, 0, 0, 0, 0},	// 4
	  {0, 0, 0, 0, 0, 0},	// 5
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int start;
	queue<int> q;

	cin >> start;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		cout << now << ' ';

		for (int next = 0; next < 6; next++) {
			if (adj_mtx[now][next] == 0) continue;

			q.push(next);
		}
	}

	return 0;
}