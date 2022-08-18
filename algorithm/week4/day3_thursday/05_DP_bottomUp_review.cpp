#include <iostream>
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
		return ;
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

int main() {

	cin >> rowMax >> colMax;
	initDP(-2134567890);

	for (int row = 1; row <= rowMax; row++) {
		dp(row);

	}

	int ans = -2134567890;
	for (int col = 1; col <= colMax; col++)
		ans = max(ans, DP[rowMax][col]);

	cout << ans;
	return 0;
}

