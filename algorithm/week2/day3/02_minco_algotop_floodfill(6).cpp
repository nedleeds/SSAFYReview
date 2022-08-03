#include <iostream>
#include <queue>
using namespace std;

int MAP[101][101];
int visited[101][101];
int rMax, cMax;
int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

struct Pos {
	int r, c;
};

void floodfill(Pos start, int group) {
	queue<Pos> q;
	q.push(start);
	visited[start.r][start.c] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r >= rMax || next.c >= cMax)
				continue;
			if (visited[next.r][next.c] > 0)
				continue;
			if (MAP[group])
				continue;


		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rMax >> cMax;

	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			cin >> MAP[r][c];
		}
	}

	// 이어져 있는지, 그룹이 어떻게 지어져있는지?
	// 이런 애들은 일단 for문으로 2차원 배열을 모두 탐색
	// r, c -> 스타트 (0, 0)으로 시작!! 
	// floodfill 함수를 만들어서 호출하는게 더 생각하기도 보기도 편함
	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			if (MAP[r][c] == 1) {
				floodfill({ r, c });
			}
		}
	}

	return 0;
}