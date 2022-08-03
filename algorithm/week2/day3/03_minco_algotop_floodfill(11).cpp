#include <iostream>
#include <queue>
using namespace std;

// !!! floodfill 두 번 돌리기 !!!
// 이런 설계 방식을 하나씩 머릿속에 집어 넣어야돼!! 

string MAP[8];
int visited[8][9];
int visited2[8][9];
int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};
struct Pos {
	int r, c;
}p1, p2, end1, end2;

int floodfill(Pos start) {
	queue<Pos> q, q2;
	q.push(start);
	visited[start.r][start.c] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r > 7 || next.c > 8)
				continue;
			if (visited[next.r][next.c] > 0)
				continue;
			if (MAP[next.r][next.c] == '_') {
				visited[next.r][next.c] = 1;
				q2.push({ next.r, next.c });
				continue;
			}

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			q.push(next);
		}
	}

	int ans = 0;
	while (!q2.empty()) {
		Pos now = q2.front();
		q2.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r > 7 || next.c > 8)
				continue;
			if (visited[next.r][next.c] > 0)
				continue;
			if (MAP[next.r][next.c] == '#') {
				return visited[now.r][now.c];
			}

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			q2.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	p1 = { 7, 0 };
	p2 = { 0, 8 };
	for (int i = 0; i < 8; i++) {
		cin >> MAP[i];
	}

	int ans = floodfill(p1);

	cout << ans << '\n';
	return 0;
}