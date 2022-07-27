#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string name;
	int cnt;

	cin >> name;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		string checklist;
		cin >> checklist;

		if (checklist.find(name) != string::npos)
			cout << "O\n";
		else
			cout << "X\n";
	}


	return 0;
}