#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1},
};

struct Pos {
	int r, c;
}seed1, seed2;
//ÀÌ¹Ì ²ÉÀÌ ÇÉ ÁöÁ¡ÀÌ³ª, ¾¾¾ÑÀÌ ½É¾îÁø ÁöÁ¡¿¡´Â ¾¾¾ÑÀÌ ½É¾îÁöÁö ¸øÇÕ´Ï´Ù.
int rowMax, colMax;
int visited[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rowMax >> colMax;
	cin >> seed1.r >> seed1.c;
	cin >> seed2.r >> seed2.c;

	queue<Pos> q;
	q.push(seed1);
	q.push(seed2);
	visited[seed1.r][seed1.c] = 1;
	visited[seed2.r][seed2.c] = 1;

	int Max = -2134567890;
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r <0 || next.c <0 || next.r >= rowMax || next.c >= colMax)
				continue;
			if (visited[next.r][next.c] > 0)
				continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			if (visited[next.r][next.c] > Max)
				Max = visited[next.r][next.c];
			q.push(next);
		}
	}
	cout << Max << '\n';
	return 0;
}