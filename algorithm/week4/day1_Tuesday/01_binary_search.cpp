#include <iostream>
using namespace std;

// binary search
// --> 일반적으로는 찾아야하는 숫자의 수열이 존재
// --> 필수 조건 : 정렬 상태에서 사용가능

void binarySearch(int target) {
	// 1. 범위 설정 -> 최소값과 최대값
	int left = 1;	 // 최소
	int right = 100; // 최대

	// left와 right가 이름값(좌우) 하는 동안 반복
	while (left <= right) {
		// 2. binary search 는 mid를 사용하는 알고리즘
		int mid = (left + right) / 2;

		// 3가지 옵션을 통해 현재 값 체크
		// 1. 같을때  2. 클 때  3.작을 때
		if (mid == target) {
			cout << "찾았다!\n";
			return;
		}
		else if (mid > target) {
			cout << "왼쪽에 값이 있다\n";
			// 이 구문에 들어온건 결국 mid를 확인했다는 것
			right = mid - 1; // 확인한 것은 제외
		}
		else{
			cout << "오늘쪽에 값이 있다\n";
			left = mid+1;
		}
	}
	cout << "못찾았다\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int target = 77;
	binarySearch(target);


	return 0;
}