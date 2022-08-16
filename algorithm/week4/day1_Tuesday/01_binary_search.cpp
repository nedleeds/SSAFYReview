#include <iostream>
using namespace std;

// binary search
// --> �Ϲ������δ� ã�ƾ��ϴ� ������ ������ ����
// --> �ʼ� ���� : ���� ���¿��� ��밡��

void binarySearch(int target) {
	// 1. ���� ���� -> �ּҰ��� �ִ밪
	int left = 1;	 // �ּ�
	int right = 100; // �ִ�

	// left�� right�� �̸���(�¿�) �ϴ� ���� �ݺ�
	while (left <= right) {
		// 2. binary search �� mid�� ����ϴ� �˰���
		int mid = (left + right) / 2;

		// 3���� �ɼ��� ���� ���� �� üũ
		// 1. ������  2. Ŭ ��  3.���� ��
		if (mid == target) {
			cout << "ã�Ҵ�!\n";
			return;
		}
		else if (mid > target) {
			cout << "���ʿ� ���� �ִ�\n";
			// �� ������ ���°� �ᱹ mid�� Ȯ���ߴٴ� ��
			right = mid - 1; // Ȯ���� ���� ����
		}
		else{
			cout << "�����ʿ� ���� �ִ�\n";
			left = mid+1;
		}
	}
	cout << "��ã�Ҵ�\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int target = 77;
	binarySearch(target);


	return 0;
}