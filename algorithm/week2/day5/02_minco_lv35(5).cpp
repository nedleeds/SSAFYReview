#include <iostream>
#include <queue>
using namespace std;
int nums[] = { 1, 2, 3, 5 };
void uglyNumber(int idxEnd) {
	int idx = 1;
	while (idx <= idxEnd) {



		idx++;
	}

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