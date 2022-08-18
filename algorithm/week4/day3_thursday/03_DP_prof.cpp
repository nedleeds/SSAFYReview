#include <iostream>
using namespace std;

long long dp[1000]; // �տ��� ����ߴ� ����� �����ص� ģ��

int fibo_with_dp(int now) {
	if (now <= 1){
		dp[now] = now; // ��� ����
		return now; // fibo(1):1, fibo(0):0;
	}

	if (dp[now] > 0) // �̹� �߾��� ����� �װ� ��
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
	int dp[4][3] = {0,}; // dp[����ȣ][���׸����ȣ]
	int arr[4][3] = {
		{10, 20, 30 },
		{20, 30, 40 },
		{40, 20, 10 },
		{50, 10, 100 }
	};

	for (int i = 0; i < 4; i++) {		// ����ȣ 
		for (int j = 0; j < 3; j++) {	// ���׸���
			// dp[i][j] <== ����� ����ϰ� ����
			if (i == 0) {
				// ���� ���� ���µ�, ���� ���� ���� ���
				dp[i][j] = arr[i][j];
				continue;
			}
			if (j == 0) {
				// ���� 0�� ���׸����
				int pre = min(dp[i - 1][1], dp[i - 1][2]);
				int now = pre + arr[i][j]; // ���� ���� ��� + ������ �� ������
				dp[i][j] = now;
				// ���� ���׸��� ���1, 2 �� ������ �� ����
			}
			else if (j == 1) {
				// ���� 1�� ���׸����
				int pre = min(dp[i - 1][0], dp[i - 1][2]);
				int now = pre + arr[i][j]; // ���� ���� ��� + ������ �� ������
				dp[i][j] = now;
				// ���� ���׸��� ���0, 2 �� ������ �� ����
			}
			else if (j == 2) {
				// ���� 2�� ���׸����
				int pre = min(dp[i - 1][0], dp[i - 1][1]);
				int now = pre + arr[i][j]; // ���� ���� ��� + ������ �� ������
				dp[i][j] = now;
				// ���� ���׸��� ���0, 1 �� ������ �� ����
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
	// ������ �����Ͽ� "������" ���ϴ� ������ ���
	
	// Ư¡ Ȥ�� ����
	// 1.	���� ��Ģ���� ����� �������Ѵ�
	//		(ū ������ �ذ��ϴ� ����� ���� ������ �ذ��ϴ� ����� ����.)
	// 2.**	�� �� ����� ����� �ٲ��� �ʾƾ� �Ѵ� **
	//		(������ ����� �߰��� ������ ����� DP�� ����� �����ϴϱ�)

	// Dynamic Programming�� �ذ��ϴ� ���
	// 1. ��Ȳ�� ������ �� �ִ� ���� ���� 
	//    (���� ���� ������ ��, ���� ���� ��, Ȥ�� ���� ��)
	//    => ����� ������ ��ġ�� ��� ���ε�
	//	  => �� ������ ã�°� ���� �߿�
	// 
	// 2. �迭 ����
	//	  => ���� �ϳ� �� ���� �ϳ�
	//	  => dp[��][���׸���][����]
	// 
	// 3. ��Ģ ã��
	//	  => now ��� ��Ȳ�� ���� ��, now��� ��Ȳ�� ���� �� �ִ�
	//    => �ٷ� ���� ��Ȳ�� ���.
	//    => ��? �ٷ� ������ ��Ȳ ���� ������ ��� ��Ȳ�� �ݿ��� ���̱� ����
	// 
	// 4. ��ȭ prof's advice
	//    => DP�� ������ �ᱹ ��ȭ���� ����� ��
	//    => ����? ��? ���°�?
	//    => ��� �ߴ� �ߺ� ������� �ʱ� ���ؼ�
	//	  => greedy �� �κ� �����ؿ�����, DP�� ���� �����ظ� ���Ѵ�
	//    => 2���� ���
	//    ===> Top Down (fibonacci) --> ��ͷ�    --> (n)���� ����
	//    ===> Bottom Up (house)    --> for������ --> (0)���� ����



	return 0;
}
