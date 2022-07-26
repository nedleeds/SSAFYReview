#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	/// DAT(Direct Address Table) - �迭 -> �ǹ̸� �ο��ؼ� ���
	/// index : ��� ������ ��
	/// value : �� ������ ���� ���� ���� / ����
	/// ex) {1, 3, 5, 2, 1, 3};
	/// 1~10 ������ ���ڰ� �� ���� �ִ��� �˰� ����.
	/// 
	/// ����
	/// ���� �ӵ��� O(1)�̴�.
	/// 
	/// ���� 
	/// -> ����ó�� ������ �����
	/// -> �޸� ���� Ŭ �� �ִ�.
	/// int arr[] = {1, 10000000000, 2, 3, 5};

	
	int DAT[10] = {0,};
	for (int i = 0; i < 10; i++) {
		int tmp;
		cin >> tmp;
		DAT[tmp]++;
	}
	
	for (int j = 0; j<10; j++){
		cout << j << " " << DAT[j];
	}

	return 0;
}
