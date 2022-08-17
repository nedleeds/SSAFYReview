#include <iostream>
using namespace std;

void binarySearch(string s, char target) {
	int left = 0, right=s.length()-1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (s[mid] == target) {

		}
		else if(s[left] == target) {
			left = mid + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numLine;
	cin >> numLine;
	for (int i = 0; i < numLine; i++) {
		string s;
		cin >> s;
		binarySearch(s, '_');
	}

	return 0;
}