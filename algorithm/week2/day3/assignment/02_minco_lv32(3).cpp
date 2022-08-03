#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int bomb;
		cin >> bomb;
		v.push_back(bomb);
		if (i >= 2) {
			int last_idx = v.size() - 1;
			if (v[last_idx] == v[last_idx - 1] && v[last_idx - 1] == v[last_idx - 2]) {
				for (int k = 0; k < 3; k++) {
					v.pop_back();
				}
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}