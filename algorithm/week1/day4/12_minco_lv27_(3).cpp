#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	vector<int> v;
	cin >> num;

	for (int i = 1; i <= 4; i++) {
		v.push_back(num * i);
	}

	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << ' ';
	}
	cout << "\n";

	return 0;
}