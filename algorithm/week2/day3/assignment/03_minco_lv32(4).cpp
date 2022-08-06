#include <iostream>
#include <algorithm>
using namespace std;

string plastics[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int i = 0; i < 5; i++) {
		cin >> plastics[i];
	}

	int r1, r2;
	cin >> r1 >> r2;

	sort(plastics[r1].begin(), plastics[r1].end());
	sort(plastics[r2].begin(), plastics[r2].end());

	for (int i = 0; i < 5; i++) {
		cout << plastics[i][0] << ' ';
	}

	return 0;
}