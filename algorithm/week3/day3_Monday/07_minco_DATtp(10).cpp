#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v2;
int DAT[1000001];

bool cmp(int a, int b) {
	if (a > b) return true;
	if (a < b) return false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int testCase, numStudents;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> numStudents;
		vector<int> v;
		for (int j = 0; j < numStudents; j++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		for (int j = 0; j < numStudents; j++) {
			int num;
			cin >> num;
			DAT[num - 1] = v[j];
		}
		sort(v.begin(), v.end(), cmp);
		
		int k = 0;
		for (k = 0; k < v.size(); k++) {
			if (v[k] != DAT[k]) {
				cout << "NO\n";
				break;
			}
		}
		if (k == v.size())
			cout << "YES\n";
	}


	return 0;
}