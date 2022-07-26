#include <iostream>
using namespace std;

int arr1[4][4];
int arr2[4][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cin >> arr1[r][c];
		}
	}

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cin >> arr2[r][c];
		}
	}

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (arr1[r][c] == 1 && arr2[r][c] == 1) {
				cout << "걸리다\n";
				return 0;
			}
		}
	}
	cout << "걸리지않는다\n";
	return 0;
}
