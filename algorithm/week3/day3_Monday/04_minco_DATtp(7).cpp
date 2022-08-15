#include <iostream>
#include <algorithm>
using namespace std;
int cnt[10000001];

int main() {
	ios::sync_with_stdio(false); // ���ð� ���� // cin,scanf ���� ���� ����
	cin.tie(); 
	cout.tie();// ����� �ð� ���� // �̰��� ���� scanf,printf���� ���� �ȵ�

	//1.��Ž:���� �ݺ����� �� ���� �迭�� ī��Ʈ
	int row, col;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int num;
			cin >> num;
			cnt[num]++;
		}
	}
	//2.���: ���� �󵵼� ���� id �ε��� �� 
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