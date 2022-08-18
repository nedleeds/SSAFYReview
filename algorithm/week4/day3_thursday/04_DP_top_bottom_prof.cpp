#include <iostream>
using namespace std;

//int map[7][3] = {
//	{ 1,  0,  0},
//	{ 1,  2,  2},
//	{ 0,  3,  0},
//	{ 3,-10, -5},
//	{15,-10, 50},
//	{15,-10, 10},
//	{ 0,  6,  4}
//};
int DP[10][10];
int MAP[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int R, C;
	cin >> R >> C;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> MAP[r][c];

	for (int row = 1; row <= R; row++)
		for (int col = 1; col <= C; col++)
			DP[row][col] = -2134567890;
	// 초기값 : 계산했던 좌표인지 확인용으로 나올 수 없는 값으로 초기세팅
	// 추수 사용시 DP값을 봤을 때, 계산 상 나올 수 없는 값을 갖고 있으면 아직 계산 전.
    //							 계산 상 나올 수 있는 다른 값-> 다시 계산할 필요X 갖다 써라.


	for (int row = 1; row <= R; row++) {
		for (int col = 1; col <= C; col++) {
			DP[row][col];
			if (MAP[row][col] == 0)
				continue;
			// row, col로 올 수 있는 방법: 3가지(방향배열쓰자)
			int dr[] = { -1, -1, -1 };
			int dc[] = { -1, 0, 1 };
			int maxPreValue = -2134567890;
			for (int i = 0; i < 3; i++) {
				int pr = row + dr[i];
				int pc = col + dc[i];
				if (pr <= 0 || pc <= 0 || pr > R || pc > C)
					continue;
				if (DP[pr][pc] == -2134567890) {
					// 계산한 적 없는 좌표다 -> 직전에 벽이 있었던 경우 -> 무시해야돼
					continue;
				} 

				maxPreValue = max(maxPreValue, DP[pr][pc]);
			}
			if (maxPreValue == -2134567890) continue; // now로 올 수 있는 좌표가 
			int maxNowValue = maxPreValue + MAP[row][col];
			DP[row][col] = maxNowValue;
		}
	}

	return 0;
}