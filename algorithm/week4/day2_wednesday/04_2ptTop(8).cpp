#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[5][4];
int sum = 0;
int cnt = 0;

vector<int> AB, CD;
void psearch() {
	int left = 0;
	int right = CD.size() - 1;

	while (!(right == 0 && left == CD.size()-1 )) {
		int sum = AB[left] + CD[right];
		if (sum == 0) {
			cnt++;
			cout << cnt << '\n';
		}
		else if (sum > 0) {
			right = right - 1;
		}
		else if (sum < 0){
			left = left + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < 4; c++)
			cin >> arr[r][c];

	for (int r = 0; r < 5; r++) {
		int left = arr[r][0];
		for (int r1 = 0; r1 < 5; r1++) {
			int right = arr[r1][1];
			AB.push_back(left + right);
		}
	}

	for (int r = 0; r < 5; r++) {
		int left = arr[r][2];
		for (int r1 = 0; r1 < 5; r1++) {
			int right = arr[r1][3];
			CD.push_back(left + right);
		}
	}

	//AB, CD two pointer·Î Á¢±Ù
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
	psearch();

	return 0;
}