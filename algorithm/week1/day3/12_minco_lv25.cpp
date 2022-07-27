#include <iostream>
#include <cstring>
using namespace std;

string arr[3][3] = {
	"BHC", "BBQ", "KFC",
	"MC", "7AVE", "PAPA",
	"DHC", "OBS", "MOMS"
};

int dir[4][2] = {
	// 위, 왼쪽, 아래, 오른쪽
	{-1, 0},
	{ 0,-1},
	{ 1, 0},
	{ 0, 1},
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int r, c;
	cin >> r >> c;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			for (int i = 0; i < 4; i++) {
				int nr = r + dir[i][0];
				int nc = c + dir[i][1];

				if (0 <= nr && nr < 3 && 0 <= nc && nc < 3) {
					cout << arr[r][c];
				}
			}
		}
	}

	return 0;
}