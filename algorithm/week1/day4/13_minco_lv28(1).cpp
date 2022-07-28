#include <iostream>
using namespace std;

int arr[5][5] = {
	{0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0}
};

string names[5] = {
	"Amy", "Bob", "Chloe", "Diane", "Edger"
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int DAT[5] = { 0, };
	for (int to = 0; to < 5; to++) {
		int s = 0;
		for (int from = 0; from < 5; from++) {
			s += arr[from][to];
		}
		DAT[to] = s;
	}

	int M = -2134567890;
	int M_idx = 0;
	for (int i = 0; i < 5; i++) {
		if (DAT[i] > M) {
			M = DAT[i];
			M_idx = i;
		}
	}

	cout << names[M_idx] << '\n';

	return 0;
}