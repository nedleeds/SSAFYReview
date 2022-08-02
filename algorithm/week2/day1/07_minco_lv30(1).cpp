#include <iostream>
using namespace std;

int adj_mtx[6][6] = {
	{0, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0},
};


int visited[6];

void dfs(int now) {

	for (int next = 0; next < 6; next++) {
		if (adj_mtx[now][next] == 0) continue;
		if (visited[next] == 1) continue;

		cout << next << ' ';

		visited[next] = 1;
		dfs(next);

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int start;
	cin >> start;

	visited[start] = 1;
	cout << start << ' ';
	dfs(start);

	return 0;
}