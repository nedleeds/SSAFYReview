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
	// �ʱⰪ : ����ߴ� ��ǥ���� Ȯ�ο����� ���� �� ���� ������ �ʱ⼼��
	// �߼� ���� DP���� ���� ��, ��� �� ���� �� ���� ���� ���� ������ ���� ��� ��.
    //							 ��� �� ���� �� �ִ� �ٸ� ��-> �ٽ� ����� �ʿ�X ���� ���.


	for (int row = 1; row <= R; row++) {
		for (int col = 1; col <= C; col++) {
			DP[row][col];
			if (MAP[row][col] == 0)
				continue;
			// row, col�� �� �� �ִ� ���: 3����(����迭����)
			int dr[] = { -1, -1, -1 };
			int dc[] = { -1, 0, 1 };
			int maxPreValue = -2134567890;
			for (int i = 0; i < 3; i++) {
				int pr = row + dr[i];
				int pc = col + dc[i];
				if (pr <= 0 || pc <= 0 || pr > R || pc > C)
					continue;
				if (DP[pr][pc] == -2134567890) {
					// ����� �� ���� ��ǥ�� -> ������ ���� �־��� ��� -> �����ؾߵ�
					continue;
				} 

				maxPreValue = max(maxPreValue, DP[pr][pc]);
			}
			if (maxPreValue == -2134567890) continue; // now�� �� �� �ִ� ��ǥ�� 
			int maxNowValue = maxPreValue + MAP[row][col];
			DP[row][col] = maxNowValue;
		}
	}

	return 0;
}