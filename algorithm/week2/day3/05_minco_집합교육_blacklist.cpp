#include <iostream>
#include <vector>
using namespace std;

vector<int> Apart;
vector<int> Blacklist;
int DAT[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int rMax, cMax;
	cin >> rMax >> cMax;

	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			int num;
			cin >> num;
			Apart.push_back(num);
		}
	}

	int rMax2, cMax2;
	cin >> rMax2 >> cMax2;
	for (int r = 0; r < rMax2; r++) {
		for (int c = 0; c < cMax2; c++) {
			int num;
			cin >> num;
			DAT[num] = 1;
		}
	}

	int cntBlack = 0;
	int cntCitizen = 0;
	// DAT를 사용해야된다.
	for (int i = 0; i < Apart.size(); i++) {
		if (DAT[Apart[i]])
			cntBlack += 1;
	}

	cout << cntBlack << '\n' << Apart.size() - cntBlack << '\n';

	return 0;
}