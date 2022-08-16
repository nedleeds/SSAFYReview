#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> numbers;

bool cmp(int a, int b) {
	if (a < b) return true;
	if (a > b) return false;
	return false;
}

void getNumbers() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end(), cmp);
}

void binarySearch(int target) {
	int left = 0;
	int right = numbers.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (numbers[mid] == target) {
			cout << "O";
			return ;
		}
		else if (numbers[mid] < target) {
			left = mid + 1;
		}
		else if (numbers[mid] > target) {
			right = mid - 1;
		}
	}
	cout << "X";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	getNumbers();

	int numTarget;
	cin >> numTarget;
	for (int i = 0; i < numTarget; i++) {
		int targetID;
		cin >> targetID;
		binarySearch(targetID);
	}
	return 0;
}