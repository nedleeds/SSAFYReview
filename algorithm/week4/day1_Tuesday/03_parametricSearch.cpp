#include <iostream>
using namespace std;

// parametric search
// --> 정렬이 필수
int arr[] = { 1, 2, 3, 3, 4, 4, 5, 6, 10, 10 };

// arr에서 몇 개의 요소/숫자가 5를 더했을 때 10 이하의 숫자는 몇 개인가?
void parametricSearch() {
	int left = 0;	// 배열의 첫번째 위치
	int right = 9;	// 배열의 마지막 위치
	int ans = -1;

	while (left <= right) {
		// 2. 핵심 : mid
		// mid -> 기준 : mid는 내가 찾고자 하는 정답이다~! 라고 가정
		int mid = (left + right) / 2;

		// 가능성 체크
		if (arr[mid] + 5 <= 10) {
			// 지금 mid를 더해봤을 때 
			// --> 우리가 찾고자 하는 정답이 맞다
			// --> 가능성을 찾았다!! 라고 기록
			ans = mid;
			// 더 많은 숫자가 정답이 될 수 있을까?
			// --> 찾고자 하는 범위를 늘려보자
			left = mid + 1; // 최대, 최소에 따라 이 부분이 바뀐다
			// 최소면 right 가 mid-1로 업데이트 해주겠지
			// 범위를 줄여야 하니깐
		}
		else {
			// 이미 mid 부분은 정답이 될 수 없다
			// --> 찾고자 하는 범위를 줄여야한다.
			right = mid - 1;
		}
	}
	// 나의 생각 정리
	// 결국, target point를 찾으면, 시작 포인트(left)를 
	// 갱신해
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	parametricSearch();

	return 0;
}