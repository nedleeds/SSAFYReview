#include <iostream>
using namespace std;

string arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> arr;

	int l = arr.length();
	char a2[5] = {};
	char a3[5] = {};

	int a2_len=0, a3_len=0;
	for (int i = 0; i < l / 2; i++) {
		a2[i] = arr[i];
		a2_len++;
	}

	int k = 0;
	for (int j = l/2; j < l; j++) {
		a3[k++] = arr[j];
		a3_len++;
	}

	if (a2_len != a3_len) {
		cout << "다른문장\n";
	}
	else {
		for (int j = 0; j < a2_len; j++) {
			if (a2[j] != a3[j]) {
				cout << "다른문장\n";
				return 0;
			}
		}
		cout << "동일한문장\n";
	}

	

	return 0;
}
