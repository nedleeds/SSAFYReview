#include <iostream>
#include <queue>
using namespace std;

int dir[8][2] = {
	{-1, -2},
	{-2, -1},
	{-2,  1},
	{-1,  2},
	{ 1,  2},
	{ 2,  1},
	{ 2, -1},
	{ 1, -2}
};

struct Pos {
	int r, c;
}night, target;

int MAP[101][101];
int visited[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int rowMax, colMax;
	cin >> rowMax >> colMax;

	cin >> night.r >> night.c;
	cin >> target.r >> target.c;
	MAP[night.r][night.c] = 1;
	MAP[target.r][target.c] = -1;

	queue<Pos> q;

	q.push(night);
	visited[night.r][night.c] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r > rowMax || next.c > colMax)
				continue;
			if (visited[next.r][next.c] > 0) continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			if (MAP[next.r][next.c] == -1){
				cout << visited[now.r][now.c] << '\n';
				break;
			}
			q.push(next);
		}

	}



	return 0;
}