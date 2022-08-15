#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
문제:
접근:
풀이: 완탐
	//1.입력
	//2.각 문자 check 배열 탐색
	//1이면 O출력
	//0이면 X출력
시간복잡도: O()=
*/
string vect = "MINCODING";
int n;
bool check[200];
char input[100];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < vect.size(); i++) {
		check[vect[i]] = 1;
	}
	//2.각 문자 check 배열 탐색
	//1이면 O출력
	//0이면 X출력
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