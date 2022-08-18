#include <iostream>
#include <vector>
using namespace std;

int rowMax, colMax;
int MAP[10][10];
int DP[10][10];
/*
* MAP정보들(0은 벽, 갈 수 없음)
* 첫 째줄 rowMax, colMax
7 3
1 0 0
1 2 2
0 3 0
3 -10 -5
15 -10 50
15 -10 10
0 6 4
*/
void dp(int currRow) {
	// set init
	if (currRow == 1) {
		DP[currRow][0] = 1;
		return;
	}

	for (int currCol = 1; currCol <= colMax; currCol++) {
		if (MAP[currRow][currCol] == 0) continue;
		int dr[] = { -1, -1, -1 };
		int dc[] = { -1, 0, 1 };
		int maxPreValue = -213456890;
		for (int i = 0; i < 3; i++) {
			int preRow = currRow + dr[i];
			int preCol = currCol + dc[i];
			if (preRow<0 || preCol<0 || preRow>rowMax || preCol>colMax) continue;
			if (DP[preRow][preCol] == -2134567890) continue;
			maxPreValue = max(maxPreValue, DP[preRow][preCol]);
		}
		if (maxPreValue == -2134567890) continue;
		DP[currRow][currCol] = maxPreValue + MAP[currRow][currCol];
	}
	return;
}

void initDP(int initVal) {
	for (int r = 0; r < rowMax; r++)
		for (int c = 0; c < colMax; c++)
			DP[r][c] = initVal;
}


vector<pair<int, int>> path;
int visited[10][10];
int dr[] = {1, 1, 1};
int dc[] = {-1, 0, 1};
int maxSum = -2134567890;
void dfs(int currRow, int currCol) {
	if (currRow == rowMax) {
		if (maxSum < DP[currRow][currCol]){
			maxSum = DP[currRow][currCol];
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nextRow = currRow + dr[i];
		int nextCol = currCol + dc[i];
		if (nextRow < 0 || nextCol <0 || nextRow > rowMax || nextCol > colMax)
			continue;
		if (MAP[nextRow][nextCol] == 0) continue;
		//if (visited[nextRow][nextCol] != 0) continue;

		visited[nextRow][nextCol] = 1;
		path.push_back({ nextRow, nextCol });
		DP[nextRow][nextCol] = DP[currRow][currCol] + MAP[nextRow][nextCol];
		dfs(nextRow, nextCol);
		DP[nextRow][nextCol] -= DP[currRow][currCol] + MAP[nextRow][nextCol];
		path.pop_back();
		visited[nextRow][nextCol] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rowMax >> colMax;
	for (int r = 1; r <= rowMax; r++)
		for (int c = 1; c <= colMax; c++)
			cin >> MAP[r][c];

	initDP(-2134567890);

	DP[1][1] = 1;
	path.push_back({ 1, 1 });
	dfs(1,1);

	return 0;
}