#include <iostream>
using namespace std;


int path[10];
int branch;

void func(int level) {
	if (level == 4) {
		for (int j = 0; j < 10; j++) {
			if (path[j] > 0) {
				cout << path[j];
			}
			else {
				break;
			}
		}
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= branch; i++) {
		path[level] = i;
		func(level + 1);
		path[level] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> branch;

	func(0);

	return 0;
}