#include <iostream>
using namespace std;

int arr[] = { 4, 4, 5, 7, 8, 10, 20, 22, 23, 24 };

int binarySearch(int target) {
	int left = 0;
	int right = 9;

	while (left <= right) {
		int mid = (left + right) / 2;
		cout << mid << '\n';
		if (arr[mid] == target) {
			return 1;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int target;
	cin >> target;

	if (binarySearch(target) == -1)
		cout << "X\n";
	else
		cout << "O\n";


	return 0;
}