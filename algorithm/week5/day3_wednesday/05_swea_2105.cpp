#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int testCase, N;
int MAP[20][20];
int visited[20][20];
int isSelectedDir[4];
int rowMax;
int dRow[4] = { 1,  1, -1, -1 };
int dCol[4] = { 1, -1, -1,  1 };
int maxLength = -2134567890;
struct Pos { int r, c; } START;
vector<Pos> path;

void setMAP(int size) {
	for (int row = 0; row < size; row++)
		for (int col = 0; col < size; col++) {
			cin >> MAP[row][col];
		}
}

void initVisited() {
	for (int i = 0; i < 101; i++) {
		isSelectedDir[i] = 0;
	}
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++) {
			visited[r][c] = 0;
		}
	path.clear();
	maxLength = -2134567890;
}


void dfs(Pos now) {
	if (path.size() > 1 && (now.r == START.r && now.c == START.c)) {
		if (maxLength < path.size()) {
			maxLength = path.size();
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i >= 1 && isSelectedDir[i - 1] == 0) return;
		if (isSelectedDir[i]) continue;
		int length = int(2 * sqrt(rowMax * rowMax));
		Pos next;
		while (true) {
			next = { now.r + length * dRow[i], now.c + length * dCol[i] };
			if (next.r < 0 || next.c < 0 || next.r >= rowMax || next.c >= rowMax)
				length -= 1;
			else
				break;
		}
		if (visited[next.r][next.c] != 0 && !(next.r == START.r && next.c == START.c))
			continue;

		visited[next.r][next.c] = 1;
		path.push_back({ next.r, next.c });
		isSelectedDir[i] = 1;
		dfs(next);
		visited[next.r][next.c] = 0;
		path.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N;
		setMAP(N);
		rowMax = N;
		for (int row = 0; row < N; row++)
			for (int col = 0; col < N; col++) {
				initVisited();
				Pos startNode = { row, col };
				START = startNode;
				visited[row][col] = 1;
				path.push_back({ row, col });
				dfs({ row, col });
			}

		for (int i = 0; i < 4; i++)
			isSelectedDir[i] = 0;
		cout << "#" << tc + 1 << ' ' << maxLength << '\n';
	}

	return 0;
}