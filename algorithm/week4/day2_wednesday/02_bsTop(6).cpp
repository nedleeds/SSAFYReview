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
	// 9:00 ~ 9:44 ( bsTop(6) ���� )
	// 9:44 ~ 10:05 ( bsTop(6) ���� )
	//binarySearch();
	// 3, 3, 2 �׷� 2��?
	// t, t, 2, --> ( total - t * cnt ) % t �� �Ǵ� �� ����.
	// (��ü - üũ�� ��� ��) % t == 0�̸� t 
	// != 0 �̸� (��ü - üũ�� ��� �� ) % t ��ŭ�� üũ ?
	// ���� ���� 0���� ����
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
