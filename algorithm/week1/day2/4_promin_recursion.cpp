#include <iostream>
using namespace std;

void boomerang(int i) {
	if (i == 0) {
		cout << i << " ";
		return ;
	}

	cout << i << " ";
	boomerang(i - 1);
	cout << i << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int n;
	cin >> n;
	boomerang(n);
	cout << "\n";

	return 0;
}
