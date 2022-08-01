#include <iostream>
using namespace std;

int adj_mtx[6][6] = {
  // 0  1  2  3  4  5
	{0, 0, 1, 0, 2, 0}, // 0
	{5, 0, 3, 0, 0, 0},	// 1
	{0, 0, 0, 0, 0, 7}, // 2
	{2, 0, 0, 0, 8, 0},	// 3
	{0, 0, 9, 0, 0, 0},	// 4
	{4, 0, 0, 7, 0, 0},	// 5
};
int visited[10];
int weight;

void dfs(int now) {
	for (int next = 0; next < 6; next++) {
		if (adj_mtx[now][next] == 0) continue;
		if (visited[next] == 1) continue;

		weight += adj_mtx[now][next];
		visited[next] = 1;
		cout << next << ' ' << weight << '\n';

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
	cout << start << ' ' << 0 << '\n';
	dfs(start);

	return 0;
}