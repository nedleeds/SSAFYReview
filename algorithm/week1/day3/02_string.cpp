#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// C - ���ڿ�(!!! null �� �ݵ�� ���� !!!)
	// �׷��� character �迭�� ���ڿ� ���� -> ũ��� �˳��ϰ� !!!
	char ch[3] = "AB";
	
	// C++ -  ���ڹ迭
	char ch[2] = { 'A', 'B' };

	// �⺻ : �迭 -> ������. �迭�� �̸��� ù��° ����� �ּҰ�
	int arr[] = { 1, 2, 3 };
	cout << arr << '\n';
	cout << &arr[0] << '\n';

	return 0;
}