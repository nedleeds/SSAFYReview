#include <iostream>
using namespace std;

int n, cnt = 0;
int DAT[11];  // col�� ���� DAT(index: ����ȣ, value: ĳ���� �ξ��°�?)
int path[10]; // üũ�� path �迭
/// row�� ���ų� col�� ������ continue

void go(int row) {
	if (row == n) {
		// row�� ������! ĳ���� �� ���Ҵ�!
		cnt++; // count �� 1���� ���Ѷ� !!
		/*for (int i = 0; i < n; i++){ 
			cout << "(" << i << "," << path[i] << ")\n";
		}*/
		return;
	}


	for (int c = 0; c < n; c++) {
		if (DAT[c] == 1) { // col�� DAT�� 1�̸� ĳ���� �� ��!
			continue;
		}
		//path[row] = c;
		DAT[c] = 1; // ���� row���� �ش� col�� ĳ���� ���Ҵ�!

		go(row + 1); // ���� ������ ������!

		//path[row] = 0;
		DAT[c] = 0; // ���� row���� �ش� col�� ĳ���� ġ����!
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