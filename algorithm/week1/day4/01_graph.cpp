#include <iostream>
using namespace std;


int DAT[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	int poll[10][10];
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			int check;
			cin >> check;
			poll[r][c] = check;
		}
	}

	
	for (int c = 0; c < n; c++) {
		for (int r = 0; r < n; r++) {
			DAT[c]+=poll[r][c];
		}
	}


	int M = 0, M_idx = 0, m = 99999, m_idx = 0;
	for (int x = 0; x < n; x++) {
		if (M < DAT[x]) {
			M = DAT[x];
			M_idx = x;
		}
		else if (m > DAT[x]) {
			m = DAT[x];
			m_idx = x;
		}
	}

	cout << M << '\n' << m;


	return 0;
}
