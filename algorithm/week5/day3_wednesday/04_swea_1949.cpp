#include <iostream>
#include <vector>
using namespace std;

struct Pos { int row, col; };
int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };
int MAP[8][8];
int visited[8][8];
int heighest = -2134567890;
int testCase, N, K;
vector<Pos> startNodes;
vector<Pos> path;
// 깎으면서 dfs

int cntBreak;
int maxLength = -2134567890;
int pathDistance;
void dfs(Pos now) {

	for (int i = 0; i < 4; i++) {
		Pos next = { now.row + dRow[i], now.col + dCol[i] };
		if (next.row < 0 || next.col < 0 || next.row >= N || next.col >= N)
			continue;
		if (visited[next.row][next.col] > 0)
			continue;
		if (MAP[next.row][next.col] >= MAP[now.row][now.col]) {
			if (cntBreak > 0) continue;
			else {
				if (MAP[next.row][next.col] - K >= MAP[now.row][now.col]) {
					// K만큼 깎아도 똑같거나 더 높으면 굳이 더 이상 경로 더 볼 필요 없다
					continue;
				}
				else {
					// K만큼 깎았을 때, 현재 now 보다 next가 낮으면 깎아
					MAP[next.row][next.col] -= K;
					cntBreak++;
				}
			}
		}
		visited[next.row][next.col] = 1;
		path.push_back({ next.row, next.col });
		pathDistance++;
		dfs(next);
		if (maxLength < pathDistance) {
			maxLength = pathDistance;
		}
		if (cntBreak){
			MAP[next.row][next.col] += K;
			cntBreak--;
		}
		visited[next.row][next.col] = 0;
		path.pop_back();
		pathDistance--;
	}
}

void findHighest(int size) {
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			cin >> MAP[r][c];
			if (MAP[r][c] >= heighest) {
				heighest = MAP[r][c];
			}
		}
	}
}

void setMAP(int size) {
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (MAP[r][c] >= heighest) {
				startNodes.push_back({ r, c });
			}
		}
	}
}

void initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	while (!path.empty())
		path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N >> K;
		maxLength = 0;
		findHighest(N);
		setMAP(N);
		while (!startNodes.empty()) {
			Pos startNode = startNodes.back();
			startNodes.pop_back();
			pathDistance++;
			visited[startNode.row][startNode.col] = 1;
			path.push_back({ startNode.row, startNode.col });
			dfs(startNode);
			pathDistance = 0;
			initialize();
		}
		cout << "#" << tc + 1 << " " << maxLength << "\n";
	}


	return 0;
}