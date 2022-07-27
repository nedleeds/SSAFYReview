#include <iostream>
#include <cstring>
using namespace std;

int DAT[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string alphabets;
	cin >> alphabets;

	for (int i = 0; i < alphabets.length(); i++) {
		DAT[alphabets[i] - 'A']++;
	}

	int M = 0, M_idx = 0;
	int m = 9999, m_idx = 0;
	for (int i = 0; i < 'K' - 'A'; i++) {
		if (DAT[i] > M) {
			M = DAT[i];
			M_idx = i;
		}
		else if (DAT[i] < m) {
			m = DAT[i];
			m_idx = i;
		}
	}

	cout << char('A' + M_idx) << '\n' << char('A' + m_idx) << '\n';


	return 0;
}