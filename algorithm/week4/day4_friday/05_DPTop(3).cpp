#include <iostream>
using namespace std;

// top-down 

int target;
int n; // coin 개수
int coins[3001];
int dp[3001];

int func(int now) {
	// 재귀처럼 --> 여러 기저 조건
	// 상황별로 return 해야 하는 값들이 상이
	
	// 어떻게 내려갈 것인가?
	// 가지고 있는 코인 개수만큼 빼면서 내려가보는거지
	int minValue = 2134567890;
	for (int i = 0; i < n; i++) {
		int temp = func(now - coins[i]); // func의 인자로 now - coins[i]; 남은 돈
		// now "부터" 끝까지 남아있는 돈 -> temp 에 넣은 것
		// 근데, 획득한 temp가 최선의 선택인가?
		// 즉, nextScore와 optimalScore와 비교해야되는거지
		if (temp < minValue)
			minValue = temp;
	}
	// 여기 부분이 내가 헷갈렸던 곳 
	// --> 문제에 맞게 dp 배열에 넣는 값을 생각해서 넣어야 돼
	// --> 동전의 경우, 기록하고 싶은게 now에서 최소한의 동전 수
	// --> 최소한의 동전 수는 어떻게 구해? 
	// --> 
	dp[now] = minValue + 1; 
	return dp[now]; 
}

int main() {
	cin >> target >> n;
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	// DP -> 목적지부터 시작해서 분해하면서 내려가
	int ans = func(target);
	cout << ans;
}