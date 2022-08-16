#include <iostream>
using namespace std;

// two pointer
int arr[] = { 1, 2, 3, 5, 5, 1, 4, 3, 3, 7 };
// ����: �迭 ������ ���� 10�� �Ǵ� ���ӵ� ������ �� �� ���ΰ�?

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int target = 10;

	//������ �ΰ��� ������ ����
	int left = 0;
	int right = 0;
	int sum = 0;
	int cnt = 0;

	// ** ���� ���� ** <- ���⼭ ���� ���� �Ǽ��� �Ͼ
	// ���� Ư���� left�� right�� �ǳ� �ٴ� ��� X
	while (right <= 10) {
		// binary search ó�� ��Ȳ�� ���� �����Ͱ� �̵��ϴ� ��� �ۼ�

		// 1. target�� �������� ��
		if (sum == target) {
			cnt++;
			// ���� ���� -> Ż����� -> right�� Ż�� �����̴ϱ� right�� ����
			sum += arr[right];
			right++;
		}
		// 2. target���� ���� ��
		else if (sum < target) {
			sum += arr[right];
			right++;
		}
		// 3. target���� Ŭ ��
		else if (sum > target) {
			sum -= arr[left];
			left++;
		}

	}

	return 0;
}