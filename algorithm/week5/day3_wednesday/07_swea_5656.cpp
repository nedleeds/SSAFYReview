#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, H, W;
int MAP[12][15];
int ogMAP[12][15];
int startedCol[15];
int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0,-1, 1 };
struct Pos { int r, c; };
vector<Pos> startNodes;
int flag = 0;

void setMAP() {
	for (int row = 0; row < H; row++)
		for (int col = 0; col < W; col++) {
			cin >> MAP[row][col];
			ogMAP[row][col] = MAP[row][col];
		}
}
void resetMAP() {
	for (int row = 0; row < H; row++)
		for (int col = 0; col < W; col++)
			MAP[row][col] = ogMAP[row][col];
}

void getStartNode() {
	for (int col = 0; col < W; col++)
		for (int row = 0; row < H; row++)
			if (startedCol[col] == 0 && MAP[row][col] == 1) {
				startNodes.push_back({ row, col });
				startedCol[col] = 1;
			}
}

void bfs(Pos start) {
	queue<Pos> q;
	q.push(start);
	int maxLen = MAP[start.r][start.c] - 1;

	while (!q.empty() && maxLen) {
		Pos now = q.front();
		q.pop();
		maxLen = MAP[now.r][now.c] - 1;

		for (int i = 1; i <= maxLen; i++) {
			for (int i = 0; i < 4; i++) {
				int nr = start.r + dRow[i];
				int nc = start.c + dCol[i];
				if (nr < 0 || nc < 0 || nr >= H || nc >= W)
					continue;
				if (MAP[nr][nc] == 0)
					continue;
				MAP[nr][nc] = 0;
				q.push({ nr, nc });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N >> H >> W;
		int step = 0;
		setMAP();

		getStartNode();
		while (!startNodes.empty() && step != N) {
			Pos start = startNodes.back();
			startNodes.pop_back();

			int l = MAP[start.r][start.c] - 1;
			for (int i = 0; i < 4; i++) {
				Pos next = { start.r + l * dRow[i], start.c + l * dCol[i] };
				if (next.r < 0 || next.c < 0 || next.r >= H || next.c >= W)
					continue;
				if (MAP[next.r][next.c] == 0) 
					continue;
				MAP[next.r][next.c] = 0;
				step++;
			}

		}

		resetMAP();
	}
	int de = 1;

	return 0;
}
