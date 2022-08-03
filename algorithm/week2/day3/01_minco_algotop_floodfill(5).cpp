#include <iostream>
#include <queue>
using namespace std;

int dir[8][2] = {
	{-2, 3},
	{-2,-3},
	{-3, 2},
	{-2, 3},
	{ 2, 3},
	{ 3, 2},
	{ 3,-2},
	{ 2,-3},
};

int MAP[101][101]; //adjacent matrix
int visited[101][101];

struct Pos {
	int r, c;
}red, blue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int rMax, cMax;
	cin >> rMax >> cMax;
	cin >> red.r >> red.c;
	cin >> blue.r >> blue.c;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int row, col;
		cin >> row >> col;
		MAP[row][col] = 1;
	}

	queue<Pos> q;
	q.push(red);
	visited[red.r][red.c] = 1;
	int ans = 0;
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r >= rMax || next.c >= cMax)
				continue;
			if (visited[next.r][next.c] != 0)
				continue;
			if (MAP[next.r][next.c] != 0)
				continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;

			if (next.r == blue.r && next.c == blue.c) {
				ans = visited[now.r][now.c];
				cout << ans << '\n';
				return 0;
			}

			q.push(next);
		}
	}

	if (visited[blue.r][blue.c] == 0)
		cout << -1 << '\n';
	
	return 0;
}