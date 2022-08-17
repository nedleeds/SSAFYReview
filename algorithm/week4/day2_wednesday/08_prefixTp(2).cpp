#include <iostream>
using namespace std;

int arr[100001];
int sumArr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numInfo, lastIdx, maxIdx=-2134567890;
	cin >> numInfo >> lastIdx;
	for (int i = 1; i <= numInfo; i++) {
		int idx, value;
		cin >> idx >> value;
		arr[idx] = value;
		if (idx > maxIdx)
			maxIdx = idx;
	}

	for (int j = 1; j <= lastIdx; j++)
			sumArr[j] = sumArr[j-1] + arr[j];


	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int left, right;
		cin >> left >> right;
		cout << sumArr[right] - sumArr[left - 1] << '\n';
	}


	return 0;
}