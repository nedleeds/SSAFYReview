#include <iostream>
#include <vector>

using namespace std;

int arr[4][4];
int M = 213456890;
int M_idx = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cin >> arr[r][c];
		}
	}

	for (int r = 0; r < 4; r++) {
		int s = 0;
		for (int c = 0; c < 4; c++) {
			s += arr[r][c];
		}
		if (s > M) {
			M = s;
			M_idx = r;
		}
	}

	cout << char('A' + M_idx) << '\n';

	return 0;
}