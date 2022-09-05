#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> samples;

bool cmp(int a, int b) {
	if (a < b) return true;
	if (a > b) return false;
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
	int minSum = 2134567890;

	// iteration
	while (left < right) {
		// get sum
		int sum = samples[left] + samples[right];

		// check sum
		if (abs(sum) < minSum) {
			minSum = abs(sum);
			minLeft = left;
			minRight = right;
		}
		// go next
		if (sum > 0) {
			right--;
		}
		else if (sum < 0) {
			left++;
		}
		else {
			cout << samples[minLeft] << ' ' << samples[minRight] << '\n';
			return 0;
		}
	}
	cout << samples[minLeft] << ' ' << samples[minRight] << '\n';
	return 0;
}