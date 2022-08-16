#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int maxSize, windowSize, value;
		vector<int> values;
		cin >> maxSize >> windowSize;

		// 1. set values
		for (int j = 0; j < maxSize; j++) {
			cin >> value;
			values.push_back(value);
		}
		// 2. init sum
		int sum = 0;
		int left = 0;
		int right = windowSize - 1;
		int M = -2134567890;
		int M_left = 0;
		int M_right = 0;
		for (int k = left; k < right; k++)
			sum += values[k];
		
		// 3. do while (right<maxSize)
		while (right < maxSize) {
			// complete the initialzied sum
			sum += values[right];

			// check the sum Value
			if (sum > M){
				M = sum;
				M_left = left;
				M_right = right;
			}
			// prepare moving
			sum -= values[left];

			// move pointer
			right++;
			left++;
		}
		cout << "#" << i + 1 << ' ';
		cout << M_left << ' ' << M_right << ' ' << M << '\n';
	}

	return 0;
}