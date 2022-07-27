#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void strcopy(char a[], char b[]) {
	int idx = 0;
	while (b[idx] != '\0') {
		*(a + idx) = b[idx++];
	}
	a[idx] = '\0';
}

int main() {

	// 1. ��
	char a[100];
	char b[100] = "string";
	strcopy(a, b);
	cout << a << '\n';

	// 2. cstring
	char a1[100] = "str";
	strcpy(a1, b); // strcpy(target, source)
	// �κк���
	// strncpy(target, source(=pointer), ����ũ��)
	strncpy(a1, b, 3); 
	cout << a1 << '\n';

	// 3. C++ string
	string s1 = "";
	string s2 = "string";
	s1 = s2;
	cout << s1 << '\n';
	// string class�� �κ� ���� 
	// substr(���� index, ���� ũ��)
	s1 = s2.substr(2, 4);
	cout << s1;

	return 0;
}