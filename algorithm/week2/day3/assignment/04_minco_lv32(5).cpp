#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
bool cmp(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	if (a.length() > b.length()) {
		return false;
	}

	if (a < b) {
		return true;
	}
	if (a > b) {
		return false;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	cin >> num;

	for (int i = 0; i < num; i++){
		string name;
		cin >> name;
		v.push_back(name);
	}

	sort(v.begin(), v.end(), cmp);

	for (int j = 0; j < num; j++) {
		cout << v[j] << '\n';
	}

	return 0;
}
