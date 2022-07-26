#include <iostream>
using namespace std;


/// 재귀
/// path -> 모든 조합을 때려보는 문제
/// 1. 효율성 up --> 시간이 빨라진다.
/// 
/// 문제 -> 주사위
/// 주사위 3개를 던졌을 때 (서로 다른 수)
/// 출력 --> 123 124 125 126 213 214 ... 654

int path[6];
int DAT[7]; 

void func(int level) {
	// 기저조건
	if (level == 3) {
		for (int i = 0; i < 3; i++) {
			cout << path[i];
		}
		cout << '\n';
		return;
	}
	
	// 재귀 구성
	for (int i = 1; i <= 6; i++) {
		// 가지치기 부분
		// 만약 지금 나온 눈금을 사용할 수 있는가?
		// 중복되지 않는가? -> 중복된다면 안들어갈거야.
		if (DAT[i] == 1) {
			continue;
		}

		path[level] = i;
		DAT[i] = 1; // 이 눈금 이제 사용할 거에요 !

		func(level + 1);

		path[level] = 0;
		DAT[i] = 0; // 이 눈금 이제 다른 경로에서 사용가능해!
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	func(0);

	return 0;
}