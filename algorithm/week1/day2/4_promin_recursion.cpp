#include <iostream>
using namespace std;

string arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> arr;

	int l = arr.length();
	for (int start = l - 1; start >= 0; start--) {
		for (int j = start; j < l; j++) {
			cout << arr[j];
		}
		cout << "\n";
	}

	return 0;
}
