#include <iostream>
using namespace std;

char arr[5];
void printing(int idx) {
	if (idx == 5) {
		cout << "\n";
		return;
	}

	cout << arr[idx];
	printing(idx + 1);
	cout << arr[idx];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	
	printing(0);
	cout << "\n";

	return 0;
}
