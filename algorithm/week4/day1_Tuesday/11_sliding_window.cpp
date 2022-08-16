#include <iostream>
using namespace std;

// sliding window
int arr[] = { -3, 22, 30, 4, -5, 6, 17, 8, 19, 10 };

// 문제 : 3크기 만큼의 합의 최대 값을 찾는 것

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 1. 공통 구간
	// 시작idx = 0 <- 맨 앞에서부터 다 훑을 거라 시작은 대부분? 항상 0 (left)
	// 끝idx = window size - 1 (right)
	int left = 0;
	int right = 3 - 1;

	// 먼저 공통 구간의 합을 구해둔다.
	int sum = 0;
	for (int i = left; i < right; i++)
		sum += arr[i];

	// 2. 창문 열기
	// right가 범위 내에 있는 동안 반복
	int maxVal = -2134567890;
	while (right < 10) {
		sum += arr[right]; //초기 합이 오른쪽 값이 제외된 상태. 여기서 완성됨
		if (sum > maxVal)
			maxVal = sum;
		sum -= arr[left];
		left++;
		right++;
	}

	return 0;
}