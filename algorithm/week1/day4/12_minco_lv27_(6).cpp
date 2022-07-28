#include <iostream>

using namespace std;
int arr[3][3] = {
	{0, 5, 4},
	{3, 0, 0},
	{0, 0, 1}
};

int main()
{
	/*
	(0, 0) -> (0, 2)
	(0, 1) -> (1, 2)
	(0, 2) -> (2, 2)

	(1, 0) -> (0, 1)
	(1, 1) -> (1, 1)
	(1, 2) -> (2, 1)

	(2, 0) -> (0, 0)
	(2, 1) -> (1, 0)
	(2, 2) -> (2, 0)
	*/

	int num;
	cin >> num;


	for (int k = 0; k < num; k++) {
		int tmp[3][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		};
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				int nr = c;
				int nc;
				if (r == 0) {
					nc = 2;
				}
				else if (r == 1) {
					nc = 1;
				}
				else {
					nc = 0;
				}
				tmp[nr][nc] = arr[r][c];
			}
		}
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				arr[r][c] = tmp[r][c];
			}
		}
	}

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (arr[r][c] == 0) {
				cout << '_';
			}
			else {
				cout << arr[r][c];
			}
		}
		cout << '\n';
	}

	return 0;
}