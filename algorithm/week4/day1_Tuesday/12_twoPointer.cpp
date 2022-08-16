#include <iostream>
using namespace std;

// two pointer
int arr[] = { 1, 2, 3, 5, 5, 1, 4, 3, 3, 7 };
// 문제: 배열 내에서 합이 10이 되는 연속된 구간은 총 몇 개인가?

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int target = 10;

	//설계대로 두개의 포인터 설정
	int left = 0;
	int right = 0;
	int sum = 0;
	int cnt = 0;

	// ** 종료 조건 ** <- 여기서 제일 많은 실수가 일어남
	// 문제 특성상 left가 right를 건너 뛰는 경우 X
	while (right <= 10) {
		// binary search 처럼 상황에 따라 포인터가 이동하는 경우 작성

		// 1. target을 충족했을 때
		if (sum == target) {
			cnt++;
			// 조건 충족 -> 탈출시켜 -> right가 탈출 조건이니깐 right를 설정
			sum += arr[right];
			right++;
		}
		// 2. target보다 작을 때
		else if (sum < target) {
			sum += arr[right];
			right++;
		}
		// 3. target보다 클 때
		else if (sum > target) {
			sum -= arr[left];
			left++;
		}

	}

	return 0;
}