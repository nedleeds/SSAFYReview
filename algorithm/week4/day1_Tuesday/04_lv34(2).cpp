#include <iostream>
using namespace std;

string oilStatus;

void binarySearch(char target) {
	int left = 0;
	int right = oilStatus.length();
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (oilStatus[mid] == target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ((mid) * 100 / oilStatus.length())  << "%\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> oilStatus;
	binarySearch('#');

	return 0;
}