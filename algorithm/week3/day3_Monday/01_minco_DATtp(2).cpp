#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
����:
����:
Ǯ��: ��Ž
	//1.�Է�
	//2.�� ���� check �迭 Ž��
	//1�̸� O���
	//0�̸� X���
�ð����⵵: O()=
*/
string vect = "MINCODING";
int n;
bool check[200];
char input[100];

int main() {
	ios::sync_with_stdio(false); // ���ð� ���� // cin,scanf ���� ���� ����
	cin.tie(nullptr); cout.tie(nullptr);// ����� �ð� ���� // �̰��� ���� scanf,printf���� ���� �ȵ�

	//1.�Է�
	cin >> n;
	for (int i = 0; i < vect.size(); i++) {
		check[vect[i]] = 1;
	}
	//2.�� ���� check �迭 Ž��
	//1�̸� O���
	//0�̸� X���
	for (int i = 0; i < n; i++) {
		char tp;
		cin >> tp;
		if (check[tp] == 1) {
			cout << "O";
		}
		else { cout << "X"; }
	}
	return 0;
}