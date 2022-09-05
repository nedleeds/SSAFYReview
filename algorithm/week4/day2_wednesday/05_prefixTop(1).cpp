#include <iostream>
using namespace std;

struct Corner {
	int left_upper[2] = {};
	int right_lower[2] = {};
}corner;
int arr[501][501];
int DAT[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++){
			cin >> arr[r][c];
			DAT[arr[r][c]]++;
		}
		
	int Q;
	cin >> Q;
	for (int j = 0; j < Q; j++) {
		cin >> corner.left_upper[0] >> corner.left_upper[1];
		cin >> corner.right_lower[0] >> corner.right_lower[1];
	}

	int maxCnt = -2134567890;
	for (int r = corner.left_upper[0]; r < corner.right_lower[0]; r++) {
		for (int c = corner.left_upper[1]; c < corner.left_upper[1]; c++) {
			if (DAT[arr[r][c]] > maxCnt) {

			}
		}
	}

	return 0;
}