#include <iostream>
#include <queue>
using namespace std;

string MAP[201];
int visited[201][201];
int rMax, cMax;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
int cntMax = -2134567890;
struct Pos {
	int r, c;
};

int bfs(Pos start, char Check) {
	int cnt = 0;
	queue<Pos> q;
	q.push(start);
	visited[start.r][start.c] = 1;
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			Pos next = { now.r + dir[i][0], now.c + dir[i][1] };
			if (next.r < 0 || next.c < 0 || next.r >= rMax || next.c >= cMax)
				continue;
			if (visited[next.r][next.c] > 0)
				continue;
			if (MAP[next.r][next.c] != Check)
				continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;
			q.push(next);
		}
	}
	if (cnt > cntMax)
		cntMax = cnt;
	return 1;
}

int main() {

	cin >> rMax >> cMax;

	for (int i = 0; i < rMax; i++) {
		cin >> MAP[i];
	} // 문자열 맵 생성

	int cntA = 0, cntB = 0;
	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			// visited[r][c]가 방문한 적이 없는 곳이어야지!!
			if (MAP[r][c] == 'A' && visited[r][c] == 0) {
				cntA += bfs({ r,c }, 'A');
			}
			else if (MAP[r][c] == 'B' && visited[r][c] == 0) {
				cntB += bfs({ r,c }, 'B');
			}
		}
	}
	cout << cntA << ' ' << cntB << '\n';
	cout << cntMax << '\n';
	return 0;
}
