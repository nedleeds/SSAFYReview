#include <iostream>
using namespace std;

long long dp[1000]; // 앞에서 계산했던 결과를 저장해둘 친구

int fibo_with_dp(int now) {
	if (now <= 1){
		dp[now] = now; // 결과 저장
		return now; // fibo(1):1, fibo(0):0;
	}

	if (dp[now] > 0) // 이미 했었던 결과는 그걸 써
		return dp[now];

	int first = fibo_with_dp(now - 1);
	int second = fibo_with_dp(now - 2);
	int nowValue = first + second;
	dp[now] = nowValue;

	return nowValue;
}

int fibo_without_dp(int now) {
	if (now <= 1) {
		return now; // fibo(1):1, fibo(0):0;
	}

	int first = fibo_without_dp(now - 1);
	int second = fibo_without_dp(now - 2);
	int nowValue = first + second;

	return nowValue;
}

void doFibo() {
	for (int i = 0; i <= 40; i++) {
		//cout << fibo_with_dp(i) << '\n';
		cout << fibo_without_dp(i) << '\n';
	}
}

void house() {
	int dp[4][3] = {0,}; // dp[집번호][인테리어번호]
	int arr[4][3] = {
		{10, 20, 30 },
		{20, 30, 40 },
		{40, 20, 10 },
		{50, 10, 100 }
	};

	for (int i = 0; i < 4; i++) {		// 집번호 
		for (int j = 0; j < 3; j++) {	// 인테리어
			// dp[i][j] <== 비용을 계산하고 싶음
			if (i == 0) {
				// 현재 집을 보는데, 이전 집이 없는 경우
				dp[i][j] = arr[i][j];
				continue;
			}
			if (j == 0) {
				// 현재 0번 인테리어면
				int pre = min(dp[i - 1][1], dp[i - 1][2]);
				int now = pre + arr[i][j]; // 이전 선택 결과 + 현재의 값 합쳐줌
				dp[i][j] = now;
				// 이전 인테리어 비용1, 2 중 저렴한 것 선택
			}
			else if (j == 1) {
				// 현재 1번 인테리어면
				int pre = min(dp[i - 1][0], dp[i - 1][2]);
				int now = pre + arr[i][j]; // 이전 선택 결과 + 현재의 값 합쳐줌
				dp[i][j] = now;
				// 이전 인테리어 비용0, 2 중 저렴한 것 선택
			}
			else if (j == 2) {
				// 현재 2번 인테리어면
				int pre = min(dp[i - 1][0], dp[i - 1][1]);
				int now = pre + arr[i][j]; // 이전 선택 결과 + 현재의 값 합쳐줌
				dp[i][j] = now;
				// 이전 인테리어 비용0, 1 중 저렴한 것 선택
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int prefix[10] = { 0 };

	//doFibo();
	house();

	// Dynamic Programming
	// 재계산을 방지하여 "빠르게" 원하는 값까지 계산
	
	// 특징 혹은 조건
	// 1.	같은 규칙으로 계산해 나가야한다
	//		(큰 문제를 해결하는 방법과 작은 문제를 해결하는 방법이 같다.)
	// 2.**	한 번 계산한 결과가 바뀌지 않아야 한다 **
	//		(저장한 결과가 중간에 변함이 없어야 DP가 제대로 동작하니깐)

	// Dynamic Programming을 해결하는 방법
	// 1. 상황을 설명할 수 있는 변인 요인 
	//    (지금 집을 선택할 때, 이전 집의 색, 혹은 가격 등)
	//    => 결과에 영향을 미치는 모든 요인들
	//	  => 이 요인을 찾는게 제일 중요
	// 
	// 2. 배열 설정
	//	  => 변인 하나 당 차원 하나
	//	  => dp[집][인테리어][가격]
	// 
	// 3. 규칙 찾기
	//	  => now 라는 상황이 있을 때, now라는 상황을 만들 수 있는
	//    => 바로 직전 상황만 고려.
	//    => 왜? 바로 직전의 상황 역시 이전의 모든 상황이 반영된 것이기 때문
	// 
	// 4. 득화 prof's advice
	//    => DP의 목적은 결국 점화식을 만드는 것
	//    => 언제? 왜? 쓰는가?
	//    => 계산 했던 중복 계산하지 않기 위해서
	//	  => greedy 는 부분 최적해였지만, DP는 완전 최적해를 구한다
	//    => 2가지 방법
	//    ===> Top Down (fibonacci) --> 재귀로    --> (n)부터 시작
	//    ===> Bottom Up (house)    --> for문으로 --> (0)부터 시작



	return 0;
}
