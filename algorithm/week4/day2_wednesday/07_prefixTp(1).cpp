#include <iostream>
using namespace std; 

int arr[100001];
int sumArr[100001];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sumArr[i] = sumArr[i - 1] + arr[i];
	}

	for (int j = 0; j < M; j++) {
		int left, right;
		cin >> left >> right;

		cout << sumArr[right] - sumArr[left-1] << '\n';
	}


	return 0;
}