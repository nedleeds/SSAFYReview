#include <iostream>
#include <vector>
using namespace std;

struct Pos { int row, col; };
int arr[501][501];
int visited[501][501];
int cnt;
int maxSum;
int areaSum;
int rowMax, colMax;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
/*
ㅗ : dy{0, 0, 0, -1}, dx{-1, 0, 1,0}
ㅏ : dy{-1, 0, 1, 0}, dx{0, 0, 0, 1} 
ㅓ : dy{-1, 0, 1, 0}, dx{0, 0, 0,-1}
ㅜ : dy{ 0, 0, 0, 1}, dx{-1, 0, 1, 0}
*/
int dRow[4][4] = {
	{0, 0, 0, -1},
	{-1, 0, 1, 0},
	{-1, 0, 1, 0},
	{ 0, 0, 0, 1},
};

int dCol[4][4] = {
	{-1, 0, 1,0},
	{0, 0, 0, 1},
	{0, 0, 0,-1},
	{-1, 0, 1, 0}
};

void shapeT(Pos now) {
	for (int shape = 0; shape < 4; shape++) {
		int s = 0;
		for (int j = 0; j < 4; j++) {
			Pos next = { now.row + dRow[shape][j], now.col + dCol[shape][j] };
			int nr = next.row;
			int nc = next.col;

			if (nr<1 || nc<1 || nr > rowMax || nc > colMax)
				break;
			s += arr[nr][nc];
		}
		if (s > maxSum)
			maxSum = s;
	}
}

void dfs(Pos now) {
	if (cnt == 4) {
		if (maxSum < areaSum) {
			maxSum = areaSum;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		Pos next = { now.row + dr[i], now.col + dc[i] };
		int nr = next.row;
		int nc = next.col;
		if (nr < 1 || nc < 1 || nr > rowMax || nc > colMax)
			continue;
		if (visited[nr][nc] != 0)
			continue;

		visited[nr][nc] = 1;
		cnt++;
		areaSum += arr[nr][nc];

		dfs({ nr, nc });

		visited[nr][nc] = 0;
		cnt--;
		areaSum -= arr[nr][nc];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	/*
	* row, col 하나씩 접근
	* 해당 위치에서 그자리, x축 대칭, y축 대칭, xy대칭
	*/

	cin >> rowMax >> colMax;

	for (int row = 1; row <= rowMax; row++)
		for (int col = 1; col <= colMax; col++)
			cin >> arr[row][col];

	for (int row = 1; row <= rowMax; row++)
		for (int col = 1; col <= colMax; col++) 
		{	
			visited[row][col] = 1;
			areaSum += arr[row][col];
			cnt++;
			
			dfs({ row, col });
			
			visited[row][col] = 0;
			areaSum -= arr[row][col];;
			cnt--;

			shapeT({ row, col });
		}

	cout << maxSum;

	return 0;
}