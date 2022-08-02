#include <iostream>
using namespace std;

string s1, s2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> s1 >> s2;

	if (s1.length() > s2.length()) {
		for (int check_len = s2.length(); check_len > 0; check_len--) {
			for (int i = 0; i <= s2.length()-check_len; i++) {
				string check = s2.substr(i, check_len);
				if (s1.find(check) != -1) {
					cout << check << '\n';
					return 0;
				}
			}
		}
	}
	else {
		for (int check_len = s1.length(); check_len > 0; check_len--) {
			for (int i = 0; i <= s1.length() - check_len; i++) {
				string check = s1.substr(i, check_len);
				if (s2.find(check) != -1) {
					cout << check << '\n';
					return 0;
				}
			}
		}
	}

	return 0;
}