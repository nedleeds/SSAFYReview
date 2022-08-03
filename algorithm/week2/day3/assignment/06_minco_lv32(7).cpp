#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	string MAP[3][3] = { {""}, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, c;
		string plants;
		cin >> r >> c >> plants;
		MAP[r][c] = plants;
	}

	int numWind;
	cin >> numWind;
	vector<int> windPower;
	for (int i = 0; i < numWind; i++) {
		int p;
		cin >> p;
		windPower.push_back(p);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (numWind < int(MAP[i][j].length())) {
				char lastNum = MAP[i][j][int(MAP[i][j].length() - 1)];
				char last = char((lastNum - '0') - numWind + '0');
				for (int k = 0; k < numWind; k++)
					MAP[i][j].pop_back();
			}
			else {
				MAP[i][j].pop_back();
			}
		}
	}

	return 0;
}
