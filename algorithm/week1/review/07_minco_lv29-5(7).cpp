#include <iostream>
using namespace std;

int MAP[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int start_idx, life;
	cin >> start_idx >> life;
	

	while (start_idx < 5 && life >= 0) {
		MAP[start_idx] = life;
		for (int i = 0; i < 5; i++) {
			if (MAP[i] == 0) {
				cout << '_';
			}
			else {
				cout << MAP[i];
			}
		}
		cout << '\n';
		MAP[start_idx] = 0;
		start_idx++;
		life--;
	}

	return 0;
}