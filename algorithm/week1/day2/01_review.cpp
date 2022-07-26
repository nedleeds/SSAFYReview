#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	/// DAT(Direct Address Table) - 배열 -> 의미를 부여해서 사용
	/// index : 어떠한 고유의 값
	/// value : 그 고유의 값에 대한 개수 / 존재
	/// ex) {1, 3, 5, 2, 1, 3};
	/// 1~10 사이의 숫자가 몇 개씩 있는지 알고 싶음.
	/// 
	/// 장점
	/// 접근 속도가 O(1)이다.
	/// 
	/// 단점 
	/// -> 음수처리 귀찮고 어려움
	/// -> 메모리 낭비가 클 수 있다.
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
