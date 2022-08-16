#include <iostream>
#include <vector>
using namespace std;
vector<string> cloud;

int binarySearch(string line) {
	int left = 0;
	int right = line.length() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (line[mid] == '0') {
			return mid;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string c;
		cin >> c;
		cloud.push_back(c);
		int mid = binarySearch(cloud[i]);
		if (mid != -1){
			cout << i << ' ' << mid - 1 << '\n';
			return 0;
		}
	}



	return 0;
}