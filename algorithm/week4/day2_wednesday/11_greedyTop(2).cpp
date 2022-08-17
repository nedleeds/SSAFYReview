#include <iostream>
#include <vector>
using namespace std;

int DAT[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numhole, lenTape;
	cin >> numhole >> lenTape;

	int cnt = 0;
	for (int i = 0; i < numhole; i++) {
		int num;
		cin >> num;
		DAT[num] = 1;
		cnt++;
	}

	int idx = 0;
	int cntTape = 0;
	while (cnt > 0) {
		if (DAT[idx]) {
			// ���� ã�Ҵ� -> ������ �ٿ�
			DAT[idx] = 0;
			cnt--;
			for (int i = 0; i < lenTape; i++) {
				if (DAT[idx + i] == 1) { 
					DAT[idx + i] = 0; // ������ ���� ���� �ʿ� �����־ ���Ҵ�
					cnt--; // ���� ���� ����
				}
			}
			cntTape++; // tape �ϳ� ���.
		}
		idx++;
	}
	cout << cntTape << '\n';
	return 0;
}