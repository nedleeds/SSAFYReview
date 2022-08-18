#include <iostream>
#include <vector>
using namespace std;

int rowMax = 4;
int colMax = 4;
int MAP[5][5];
int DP[5][5];
int visited[5][5];
struct Pos {
	int row, col;
};
vector<Pos> path;
vector<Pos> ans;
int minCost = 2134567890;
void dfs(int nowRow, int nowCol) {
	if (nowRow == rowMax) {
		if (minCost > DP[nowRow][nowCol]) {
			for (int i = 0; i < path.size(); i++) {
				ans.push_back({ path[i] });
			}
		}
		return;
	}


	int dr[] = {1, 1, 1};
	int dc[] = {-1, 0, 1};
	int minCost = 2134567890;
	for (int i = 0; i < 3; i++) {
		int newRow = nowRow + dr[i];
		int newCol = nowCol + dc[i];
		if (newRow < 0 || newCol < 0 || newRow > rowMax || newCol > colMax)
			continue;
		if (DP[newRow][newCol] != -2134567890)
			continue;
		if (visited[newRow][newCol] != 0)
			continue;
		
		visited[newRow][newCol] = 1;
		path.push_back({ newRow, newCol });
		dfs(newRow, newCol);
		path.pop_back();
		visited[newRow][newCol] = 0;
		
	}
	
}

void initDP(int initValue) {
	for (int row = 0; row < rowMax; row++)
		for (int col = 0; col < colMax; col++)
			DP[row][col] = initValue;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int row = 1; row <= rowMax; row++)
		for (int col = 1; col <= colMax; col++)
			cin >> MAP[row][col];

	initDP(-2134567890);

	path.push_back({ 0, 0 });
	dfs( 0, 0 );

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].row << ',' << ans[i].col << '\n';

	return 0;
}