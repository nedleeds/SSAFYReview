#include <iostream>
#include <queue>
using namespace std;

int dir[8][2] = {
	{-3,-2},
	{-2, 3},
	{-3, 2},
	{-2, 3},
	{ 2, 3},
	{ 3, 2},
	{ 3,-2},
	{-3, 2},
};

struct Pos {
	int r, c;
}red, blue;

int MAP[101][101];
int visited[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int rMax, cMax, numNode;
	cin >> rMax >> cMax;
	cin >> red.r >> red.c;
	cin >> blue.r >> blue.c;
	cin >> numNode;

	for (int i = 0; i < numNode; i++) {
		int row, col;
		cin >> row >> col;
		MAP[row][col] = 1;
	}
	MAP[red.r][red.c] = -2;
	MAP[blue.r][blue.c] = -1;

	queue<Pos> q;
	q.push(red);
	visited[red.r][red.c] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		if (now.r == blue.r && now.c == blue.c)
			cout << visited[now.r][now.c] << '\n';
			break;

		for (int i = 0; i < 8; i++) {
			Pos next = {
				now.r + dir[i][0],
				now.c + dir[i][1]
			};
			if (next.r < 0 || next.c < 0 || next.r >= rMax || next.c >= cMax)
				continue;
			if (next.r == red.r && next.c == red.c)
				continue;
			if (visited[next.r][next.c] > 0)
				continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			q.push(next);
		}
	}

	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			cout << MAP[r][c] << '(' << visited[r][c] << ") ";
		}
		cout << '\n';
	}

	return 0;
}