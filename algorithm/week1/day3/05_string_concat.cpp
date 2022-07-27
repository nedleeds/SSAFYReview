#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void strconcatenate(char a[100], char b[]) {
	int idx = 0;
	for (int i = 0; i < 100 && a[i] != '\0'; i++) {
		idx++;
	}

	int j;
	for (j = idx; j < 100 && b[j-idx] != '\0'; j++) {
		a[j] = b[j-idx];
	}
	a[j] = '\0'; // ���ڿ����� �ʼ� !! 
}

int main() {

	// 1. ��
	char a[100] = "str";
	char b[] = "zzz";
	strconcatenate(a, b);
	cout << a << "\n";

	// 2. cstring
	// strcat(a, b); <-- a�� b�� ����.
	// ** a�� �迭�� ũ�� ����
	char a1[100] = "str";
	strcat(a1, b);
	cout << a << '\n';

	// 3. C++ string
	string s1 = "str";
	string s2 = "ing";
	cout << s1 + s2 << "\n";


	return 0;
}