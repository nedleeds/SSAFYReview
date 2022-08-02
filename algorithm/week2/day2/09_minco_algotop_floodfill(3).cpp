#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

int rowMax, colMax;
int MAP[101][101];
int visited[101][101];

struct Pos {
	int r, c;
};

void checkZombie() {
	int cnt = 0;
	for (int r = 0; r < rowMax; r++) {
		for (int c = 0; c < colMax; c++) {
			if (MAP[r][c] == 1 && visited[r][c] == 0) {
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}

int MAX = -2134567890;
void printVaccine() {
	for (int r = 0; r < rowMax; r++) {
		for (int c = 0; c < colMax; c++) {
			//cout << MAP[r][c]<< '(' << visited[r][c] << ')' << ' ';
			if (visited[r][c] > MAX) {
				MAX = visited[r][c];
			}
		}
		//cout << '\n';
	}
	cout << MAX << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> colMax >> rowMax;
	string inputs;

	for (int r = 0; r < rowMax; r++) {
		cin >> inputs;
		for (int c = 0; c < colMax; c++)
			if (inputs[c] == ' ')
				MAP[r][c] = 0;
			else
				MAP[r][c] = inputs[c] - '0';
	}

	Pos vaccine;
	cin >> vaccine.c >> vaccine.r;
	vaccine.c -= 1;
	vaccine.r -= 1;
	queue<Pos> q;
	q.push(vaccine);
	visited[vaccine.r][vaccine.c] = 3;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r >= rowMax || next.c >= colMax)
				continue;
			if (MAP[next.r][next.c] == 0) continue;
			if (visited[next.r][next.c] > 1) continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			q.push(next);
		}
	}

	int cnt = 0;
	for (int r = 0; r < rowMax; r++) {
		for (int c = 0; c < colMax; c++) {
			if (MAP[r][c] == 1 && visited[r][c] == 0) {
				cnt++;
			}
		}
	}
	printVaccine();
	checkZombie();
	return 0;
}