#include <iostream>
#include <algorithm>
using namespace std;
int cnt[10000001];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(); 
	cout.tie();// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.완탐:이중 반복으로 각 숫자 배열에 카운트
	int row, col;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int num;
			cin >> num;
			cnt[num]++;
		}
	}
	//2.출력: 가장 빈도수 높은 id 인덱스 값 
	int M=-2134567890, M_idx=0;
	for (int i = 0; i < 10000001; i++) {
		if (M < cnt[i]) {
			M = cnt[i];
			M_idx = i;
		}
	}
	cout << M_idx << '\n';
	return 0;
}