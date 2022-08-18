#include <iostream>
using namespace std;

int dp[36];

int fibo_with_dp(int n) {
	if (dp[n] > 0)
		return dp[n];

	if (n <= 1) {
		dp[n] = n;
		return n;
	}


	int first = fibo_with_dp(n - 2);
	int second = fibo_with_dp(n - 1);
	dp[n] = first + second;

	return dp[n];
}

int fibo_wo_dp(int n) {
	if (n <= 1)
		return n;

	int first = fibo_wo_dp(n - 2);
	int second = fibo_wo_dp(n - 1);
	int nowValue = first + second;

	return nowValue;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;


	cout << fibo_with_dp(n - 1) << '\n';

	return 0;
}