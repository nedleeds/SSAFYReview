#include <iostream>
#include <vector>
using namespace std;

vector<int> brainSpeed;
int DAT[501];

//void binarySearch() {
//	int left;
//	int right;
//
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		int teamCnt = mid;
//
//	}
//
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, t;
	cin >> N >> t;

	for (int i = 0; i < N; i++) {
		int person;
		cin >> person;
		brainSpeed.push_back(person);
	}
	// 9:00 ~ 9:44 ( bsTop(6) 문제 )
	// 9:44 ~ 10:05 ( bsTop(6) 설명 )
	//binarySearch();
	// 3, 3, 2 그럼 2는?
	// t, t, 2, --> ( total - t * cnt ) % t 가 되는 것 같다.
	// (전체 - 체크된 사람 수) % t == 0이면 t 
	// != 0 이면 (전체 - 체크된 사람 수 ) % t 만큼만 체크 ?
	// 시작 점을 0부터 시작
	int cnt = 0, maxSum = -2134567890;
	for (int i = 0; i < N; i += t) {
		for (int j = 0; j < t; j++){
			int sum = 0;
			if (cnt < N) {
				int pIdx = (i + j) % N;
				cout << brainSpeed[pIdx] << ' ';
				sum += brainSpeed[pIdx];
			}
			if (sum > maxSum) {

			}
			cnt++;
		}
		cout << '\n';
	}



	return 0;
}
