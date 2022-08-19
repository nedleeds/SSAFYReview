#include <iostream>
using namespace std;

// top-down 

int target;
int n; // coin ����
int coins[3001];
int dp[3001];

int func(int now) {
	// ���ó�� --> ���� ���� ����
	// ��Ȳ���� return �ؾ� �ϴ� ������ ����
	
	// ��� ������ ���ΰ�?
	// ������ �ִ� ���� ������ŭ ���鼭 ���������°���
	int minValue = 2134567890;
	for (int i = 0; i < n; i++) {
		int temp = func(now - coins[i]); // func�� ���ڷ� now - coins[i]; ���� ��
		// now "����" ������ �����ִ� �� -> temp �� ���� ��
		// �ٵ�, ȹ���� temp�� �ּ��� �����ΰ�?
		// ��, nextScore�� optimalScore�� ���ؾߵǴ°���
		if (temp < minValue)
			minValue = temp;
	}
	// ���� �κ��� ���� �򰥷ȴ� �� 
	// --> ������ �°� dp �迭�� �ִ� ���� �����ؼ� �־�� ��
	// --> ������ ���, ����ϰ� ������ now���� �ּ����� ���� ��
	// --> �ּ����� ���� ���� ��� ����? 
	// --> 
	dp[now] = minValue + 1; 
	return dp[now]; 
}

int main() {
	cin >> target >> n;
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	// DP -> ���������� �����ؼ� �����ϸ鼭 ������
	int ans = func(target);
	cout << ans;
}