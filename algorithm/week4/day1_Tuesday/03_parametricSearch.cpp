#include <iostream>
using namespace std;

// parametric search
// --> ������ �ʼ�
int arr[] = { 1, 2, 3, 3, 4, 4, 5, 6, 10, 10 };

// arr���� �� ���� ���/���ڰ� 5�� ������ �� 10 ������ ���ڴ� �� ���ΰ�?
void parametricSearch() {
	int left = 0;	// �迭�� ù��° ��ġ
	int right = 9;	// �迭�� ������ ��ġ
	int ans = -1;

	while (left <= right) {
		// 2. �ٽ� : mid
		// mid -> ���� : mid�� ���� ã���� �ϴ� �����̴�~! ��� ����
		int mid = (left + right) / 2;

		// ���ɼ� üũ
		if (arr[mid] + 5 <= 10) {
			// ���� mid�� ���غ��� �� 
			// --> �츮�� ã���� �ϴ� ������ �´�
			// --> ���ɼ��� ã�Ҵ�!! ��� ���
			ans = mid;
			// �� ���� ���ڰ� ������ �� �� ������?
			// --> ã���� �ϴ� ������ �÷�����
			left = mid + 1; // �ִ�, �ּҿ� ���� �� �κ��� �ٲ��
			// �ּҸ� right �� mid-1�� ������Ʈ ���ְ���
			// ������ �ٿ��� �ϴϱ�
		}
		else {
			// �̹� mid �κ��� ������ �� �� ����
			// --> ã���� �ϴ� ������ �ٿ����Ѵ�.
			right = mid - 1;
		}
	}
	// ���� ���� ����
	// �ᱹ, target point�� ã����, ���� ����Ʈ(left)�� 
	// ������
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	parametricSearch();

	return 0;
}