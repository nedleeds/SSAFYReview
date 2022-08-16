#include <iostream>
#include <vector>
using namespace std;

vector<int> values;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numValues, targetSum;
	cin >> numValues >> targetSum;

	// set the values
	for (int i = 0; i < numValues; i++) {
		int value;
		cin >> value;
		values.push_back(value);
	}

	// initialization
	int left = 0;
	int right = 0;
	int cntSame = 0;

	// iteration
	while (right < numValues) {
		// get the sum of window
		int sum = 0;
		for (int i = left; i <= right; i++)
			sum += values[i]; 

		// check sum
		if (sum == targetSum){
			cntSame++;
			right++;
		}
		// go on to the next(exception)
		else if (sum > targetSum) {
			left++;
		}
		else {
			right++;
		}
	}
	cout << cntSame << '\n';
	return 0;
}