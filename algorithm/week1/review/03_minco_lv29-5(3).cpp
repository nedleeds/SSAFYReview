#include <iostream>
using namespace std;

int arr[3][3];

void getInput() {
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			cin >> arr[r][c];
}

void checkRow() {

	for (int r = 0; r < 3; r++) {
		int cnt = 0, flag = 0;
		int base = arr[r][0];

		for (int c = 0; c < 3; c++) {
			if (base == arr[r][c]) 
				cnt += 1;
			if (cnt == 3) {
				cout << base << '\n';
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			cout << "x\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	getInput();
	checkRow();

	return 0;
}