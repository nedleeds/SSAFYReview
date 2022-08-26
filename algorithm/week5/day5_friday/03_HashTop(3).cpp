#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> members;
unordered_map<int, int> groupHash;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	int M = -2134567890;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		int group = 0;
		for (int i = 0; i < x.size(); i++) {
			group += (int)x[i];
		}
		groupHash[group] += 1;
		M = max(M, groupHash[group]);
	}

	cout << M << '\n';

	return 0;
}