#include <iostream>
#include <queue>
using namespace std;
int nums[] = { 1, 2, 3, 5 };

int squareK(int k) {
	int x = 3;
	for (int i = 0; i < k; i++)
		x *= x;
	return x;
}

void uglyNumber(int idxEnd) {
	int k = 1;
	int k3 = squareK(k);
	
	cout << k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int cntEnd;
		cin >> cntEnd;
		if (cntEnd == 1) {
			cout << 1 << ' ';
		}else {
			uglyNumber(cntEnd);
		}
	}

	return 0;
}
/*
-------------[ ³» ¼³°è ]-------------

*/