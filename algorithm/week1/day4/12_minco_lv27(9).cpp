#include <iostream>
using namespace std;

struct Pos {
	int r;
	int c;
};

int A[3][3] = {
	{2, 6, 3},
	{7, 1, 1},
	{3, 4, 2}
};

int B[2][4] = {
	{6, 4, 2, 4},
	{1, 1, 5, 8}
};

int C[2][3] = {
	{9, 2, 3},
	{4, 2, 1}
};
int ans[3][3];
int row = 0;
int main()
{

	int maxDAT[10] = { 0, };
	for (int i = 0; i < 3; i++) {
		int M = -2134567890;

		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (maxDAT[A[r][c]] == 0) {
					if (A[r][c] > M) {
						M = A[r][c];
					}
				}
			}
		}
		maxDAT[M] += 1;
		ans[row][i] = M;
	}
	row += 1;

	Pos minDAT = {-1, -1};
	for (int i = 0; i < 3; i++) {
		int m = 2134567890;
		int m_r, m_c;
		for (int r = 0; r < 2; r++) {
			for (int c = 0; c < 4; c++) {
				if (!(minDAT.r == r && minDAT.c == c)) {
					if (B[r][c] < m) {
						m = B[r][c];
						m_r = r;
						m_c = c;
					}
				}
			}
		}
		minDAT.r = m_r;
		minDAT.c = m_c;
		ans[row][i] = m;
	}


	return 0;
}