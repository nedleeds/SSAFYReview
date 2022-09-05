#include <iostream>
#include <vector>
using namespace std;

int N, M;
int islandNum;
int MAP[10][10];
int visited[10][10];
struct Pos { int r, c; };
vector<Pos> island[6];
vector<Pos> islandCopy[6];



void setMAP() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> MAP[r][c];
}

void dfs(Pos now, int islandIdx) {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0,-1, 1 };

	for (int i = 0; i < 4; i++) {
		Pos next = { now.r + dr[i], now.c + dc[i] };
		if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M)
			continue;
		if (visited[next.r][next.c] != 0)
			continue;
		if (MAP[next.r][next.c] == 0)
			continue;
		visited[next.r][next.c] = islandIdx;
		island[islandIdx].push_back({ next.r, next.c });
		dfs(next, islandIdx);
	}
}

void setGroup() {
	int islandIdx = 1;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			if (MAP[r][c] == 1 && visited[r][c] == 0) {
				island[islandIdx].push_back({ r, c });
				dfs({ r, c }, islandIdx);
				islandIdx++;
			}
		}
	islandNum = islandIdx - 1;
}

void copyIsland() {
	for (int i = 1; i <= islandNum; i++) {
		islandCopy[i] = island[i];
	}
	int de = 1;
}

void findRoute(int islandIdx) {
	// island 하나를 기준으로 나머지 3군데까지
	// 최소 거리 구해서 더해 
	// 방향 : 가로 or 세로
	int dir[4][2] = {
		{1, 0}, {-1, 0}, // 상하
		{0,-1}, {1, 0}   // 좌우
	};

	copyIsland();
	while (!islandCopy[islandIdx].empty()) {
		Pos now = islandCopy[islandIdx].front();
		islandCopy[islandIdx].pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N >> M;

	setMAP();
	setGroup();
	for (int i = 1; i <= islandNum; i++)
		findRoute(i);

	return 0;
}