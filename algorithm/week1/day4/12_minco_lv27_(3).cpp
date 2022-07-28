#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	cin >> num;

	num -= 11;
	for (int i = 0; i < 4; i++) {
		v.push_back('A'+ num + i);
	}

	for (int j = 0; j < v.size(); j++) {
		cout << v[j];
	}
	cout << "\n";

	return 0;
}