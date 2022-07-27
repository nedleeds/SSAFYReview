#include <iostream>
using namespace std;

string strings;

int checkLoyal(string path) {
	for (int i = 1; i < path.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (path[i] == path[j]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int start_idx = 0;
		cin >> strings;
		int left_idx, isLoyal = 1;
		while ((left_idx = strings.find('<', start_idx)) != -1) {
			int i;
			string path;
			for (i = left_idx + 1; strings[i] != '>'; i++) {
				path.push_back(strings[i]);
			}
			if (checkLoyal(path) == 0) {
				cout << "X";
				isLoyal = 0;
				break;
			}
			start_idx = left_idx + 1;
		}
		if (isLoyal) {
			cout << "O";
		}
	}
	return 0;
}