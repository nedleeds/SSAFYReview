#include <iostream>
using namespace std;

void hello() {
	cout << "hello\n";
	hello();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	while (1) {
		cout << "hello\n";
	}


	return 0;
}