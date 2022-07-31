#include <iostream>
using namespace std;

int chains[4][3] = {
	{ 3, 7, 4 },
	{ 2, 6, 9 },
	{ 5, 1, 2 },
	{ 3, 6, 7 }
};
int cnt[4];
int ans[3][4];
void rotate() {
	int tmp[3] = { 0, };

	for (int chain = 0; chain < 4; chain++) {
		int rotate_num = cnt[chain];
		for (int idx = 0; idx < 3; idx++) {
			int curr_idx = (idx + rotate_num) % 3;
			ans[curr_idx][chain] = chains[chain][idx];
		};
	}
}

void printAns() {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 4; c++) {
			cout << ans[r][c];
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int i = 0; i < 4; i++)
		cin >> cnt[i];

	rotate();
	printAns();

	return 0;
}