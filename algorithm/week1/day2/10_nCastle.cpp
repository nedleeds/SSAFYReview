#include <iostream>
using namespace std;

int n, cnt = 0;
int DAT[11];  // col에 대한 DAT(index: 열번호, value: 캐슬을 두었는가?)
int path[10]; // 체크용 path 배열
/// row가 같거나 col이 같으면 continue

void go(int row) {
	if (row == n) {
		// row가 끝났다! 캐슬을 다 놓았다!
		cnt++; // count 를 1증가 시켜라 !!
		/*for (int i = 0; i < n; i++){ 
			cout << "(" << i << "," << path[i] << ")\n";
		}*/
		return;
	}


	for (int c = 0; c < n; c++) {
		if (DAT[c] == 1) { // col에 DAT가 1이면 캐슬을 둔 것!
			continue;
		}
		//path[row] = c;
		DAT[c] = 1; // 받은 row에서 해당 col에 캐슬을 놓았다!

		go(row + 1); // 다음 행으로 가보자!

		//path[row] = 0;
		DAT[c] = 0; // 받은 row에서 해당 col에 캐슬을 치웠다!
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	go(0);
	cout << cnt;
	return 0;
}