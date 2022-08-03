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

	// �̾��� �ִ���, �׷��� ��� �������ִ���?
	// �̷� �ֵ��� �ϴ� for������ 2���� �迭�� ��� Ž��
	// r, c -> ��ŸƮ (0, 0)���� ����!! 
	// floodfill �Լ��� ���� ȣ���ϴ°� �� �����ϱ⵵ ���⵵ ����
	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			if (MAP[r][c] == 1) {
				floodfill({ r, c });
			}
		}
	}

	return 0;
}