#include <iostream>
using namespace std;

string registered[10000];
int ENTER[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int func, person;
		string name;
		cin >> func >> person;
		if (func == 1)
			cin >> name;

		if (func == 1) {
			if (registered[person] == "") {
				cout << person << " OK\n";
				registered[person] = name;
			}
			else {
				cout << person << " ERROR\n";
			}
		}
		else {
			if (registered[person] == "") {
				cout << person << " ERROR\n";
				continue;
			}
			if (ENTER[person] == 0) {
				cout << person << ' ' << registered[person] << " ENTER\n";
				ENTER[person] = 1;
			}
			else if (ENTER[person] == 1) {
				cout << person << ' ' << registered[person] << " EXIT\n";
				ENTER[person] = 0;
			}
		}

	}


	return 0;
}