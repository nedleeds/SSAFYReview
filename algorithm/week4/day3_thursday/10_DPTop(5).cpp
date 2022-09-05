#include <iostream>
using namespace std;
int rowMax, colMax;
int dRow[] = { 1, 1, 1 };
int dCol[] = { -1, 0, 1 };
int MAP[1001][1001];
int DP[1001][1001];
struct Pos { int row, col; };

int dp(Pos now) {
	if (now.row == rowMax) {
		DP[now.row][now.col] = MAP[now.row][now.col];
		return MAP[now.row][now.col];
	}

	int maxValue = -2134567890;
	for (int i = 0; i < 3; i++) {
		Pos next = { now.row + dRow[i], now.col + dCol[i] };
		int nr = next.row, nc = next.col;
		if (MAP[nr][nc] == 0) continue;
		if (nr < 1 || nc < 1 || nr > rowMax || nc > colMax)
			continue;


		int nextScore = max(maxValue, dp({ nr, nc })); 
		// now-> next로 갈때의 max 값을 찾아야겠지? 
		// next가 3방향이었잖아 그러니깐 여기 for문 안에서 maxValue를 찾아야하는거고.
		maxValue = max(maxValue, nextScore);
	}
	// maxValue 값이 정해졌다! -> 현재의 max값을 구해서 DP에 넣어야지
	DP[now.row][now.col] = maxValue + MAP[now.row][now.col];
	
	return DP[now.row][now.col];
}

void initDP(int value) {
	for (int i = 1; i <= rowMax; i++)
		for (int j = 1; j <= colMax; j++)
			DP[i][j] = value;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rowMax >> colMax;
	for (int row = 1; row <= rowMax; row++)
		for (int col = 1; col <= colMax; col++)
			cin >> MAP[row][col];

	initDP(-2134567890);
	dp({ 1, 1 });
	cout << DP[1][1] <<'\n';

	return 0;
}