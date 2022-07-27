#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//----cstring----
//strlen
//strcat
//strcmp / strncmp
//strcpy / strncpy
//strstr

//----string----
//length()
//+ , =, ==
//substr
//find
//replace

char arr[3][2][2]{
	{{2, 4}, {1, 5}},
	{{2, 3}, {3, 6}},
	{{7, 3}, {1, 5}}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int M = 0;
	int m = 99999999;

	int z;
	cin >> z;

	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < 2; c++) {
			if (arr[z][r][c] > M) {
				M = arr[z][r][c];
			}
			if (arr[z][r][c] < m) {
				m = arr[z][r][c];
			}
		}
	}

	cout << "MAX=" << M << "\n";
	cout << "MIN=" << m << "\n";

	return 0;
}