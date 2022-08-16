#include <iostream>
using namespace std;

// sliding window
int arr[] = { -3, 22, 30, 4, -5, 6, 17, 8, 19, 10 };

// ���� : 3ũ�� ��ŭ�� ���� �ִ� ���� ã�� ��

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 1. ���� ����
	// ����idx = 0 <- �� �տ������� �� ���� �Ŷ� ������ ��κ�? �׻� 0 (left)
	// ��idx = window size - 1 (right)
	int left = 0;
	int right = 3 - 1;

	// ���� ���� ������ ���� ���صд�.
	int sum = 0;
	for (int i = left; i < right; i++)
		sum += arr[i];

	// 2. â�� ����
	// right�� ���� ���� �ִ� ���� �ݺ�
	int maxVal = -2134567890;
	while (right < 10) {
		sum += arr[right]; //�ʱ� ���� ������ ���� ���ܵ� ����. ���⼭ �ϼ���
		if (sum > maxVal)
			maxVal = sum;
		sum -= arr[left];
		left++;
		right++;
	}

	return 0;
}