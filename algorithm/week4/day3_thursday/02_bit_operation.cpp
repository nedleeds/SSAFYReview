#include <iostream>
using namespace std;

int main() {
	// &  : and <- Ư�� bit�� ����, Ư�� bit�� 0���� ����� ���� ��
	// |  : or  <- Ư�� bit�� 1�� ����� ���� ��
	// ^  : xor, �ٸ��� 1, ������ 0
	// >> : /2 (���������� 1bit �̵�, ������ 2)
	//    : a >> b ( a�� 2�� b������ŭ ��������)
	// << : *2 (�������� 1bit �̵�, ���ϱ� 2)
	//    : a << b ( a�� 2�� b������ŭ ��������)

	//int a = 10;
	//int b = 12;
	//int c = 10 | 12; 
	//// ������ --> ����, b �ϸ� �������� ǥ���ȴ�

	//// �װžƳ�, -1, b ������ϸ� 1��� ����.
	//int origin = 2135;
	//int bit = 0b000100000001; // 0���� ����� ���� bit ����
	//int step1 = -1 ^ bit;	  // bit�� 1,0�� ������
	//int step2 = origin & step1; // �̷��� �ϸ� bit���� ������ bit�� 1�� 0���� �ٲ�

	/*int a = 65;
	int b = 123;
	int c = 213;

	int d = a ^ b ^ c ^ c ^ b;

	cout << d;*/

	/*int n = 1;
	for (int i = 0; i < 5; i++) {
		n <<= 1;
		cout << n << '\n';
	}
	for (int i = 0; i < 5; i++) {
		n >>= 1;
		cout << n << '\n';
	}*/

	//int a = 4865132; // <- 1�� ����
	//int temp = a;
	//int cnt = 0;
	//while (temp)
	//{
	//    if (temp & 1) // 1�� �ڸ��� bit�� �����ϴ°�?
	//    {
	//        cnt++;
	//    }
	//    temp = temp >> 1;
	//}

	int a = 4865132; // <- �����ؼ� 1�� �ִ°�찡 �� ����? ex) 0b 111 => 2����
	int temp = a;
	int cnt = 0;
	while (temp)
	{
		if ((temp & 0b11) == 0b11) // 1�� �ڸ��� bit�� �����ϴ°�?
		{
			cnt++;
		}
		temp = temp >> 1;
	}

	return 0;

	return 0;
}