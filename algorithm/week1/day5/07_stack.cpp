#include <iostream>
#include <stack>
using namespace std;

//stack

stack<int> s;

int main() {
	//// stack�� ����
	//s.push(1);
	//s.push(3);

	//// stack�� �� �� �� 
	//cout << s.top() << '\n'; // ��: 3

	//// stack�� �� ���� �����Ͱ� �ִ°�?
	//cout << s.size() << '\n'; // 2��
	//s.pop();

	//// stack�� ����ִ°� ?? yes(true) / no(false)
	//cout << s.empty() << '\n'; // true(1 �����ϱ�)

	//// ������ �� �������� ����
	//// pop() -> return�� ���� ���� (����)
	//// �� �������� �����ͼ� ��� -> top()�� �����ϰ� �����ϼ���
	//int cur = s.top();
	//s.pop();
	

	// problem 1. n���� ���ڸ� �Է¹޾��� �� �������� ����Ͻÿ�.(stack ���)
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.push(num);
	}

	for (int j = 0; j < n; j++) {
		cout << s.top();
		s.pop();
	}
	// �ٷ� �� pop �κ��� �Ʒ��� ���� while�� empty�� ����.
	//while (!s.empty()) {
	//	cout << s.top() << " ";
	//	// ���� �� ���� �ִ� ���� ����
	//	s.pop();
	//}


	return 0;
}