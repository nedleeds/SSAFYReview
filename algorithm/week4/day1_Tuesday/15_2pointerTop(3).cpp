#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> samples;

bool cmp(int a, int b) {
	if (a < b) return false;
	if (a > b) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numSample;
	cin >> numSample;

	// get sample
	for (int i = 0; i < numSample; i++) {
		int sample;
		cin >> sample;
		samples.push_back(sample);
	}

	// sort before adapting two pointer
	sort(samples.begin(), samples.end(), cmp);

	// initialize the 2 pointers
	int left = 0;
	int right = samples.size() - 1;
	int minLeft = 0;
	int minRight = 0;

	// iteration
	while (left <= right) {
		// get sum
		int sum = samples[left] + samples[right];

		// check sum
		int minDiff = 2134567890;
		if (abs(sum-0) < minDiff) {
			minDiff = abs(sum - 0);
			minLeft = left;
			minRight = right;
			cout << minLeft << ' ' << minRight << ' ' << sum << '\n';
		}
		// go next
		if (sum > 0) {
			right--;
		}
		else if (sum < 0) {
			left++;
		}
	}
	cout << minLeft << ' ' << minRight << '\n';
	return 0;
}