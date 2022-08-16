#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void binarySearch(int target) {
	int left = 0;
	int right = v.size();
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (mid * mid == target) {
			cout << mid << '\n';
		}
		else if (mid * mid > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << mid << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	binarySearch(n);

	return 0;
}