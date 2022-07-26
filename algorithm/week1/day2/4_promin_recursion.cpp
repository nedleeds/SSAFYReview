#include <iostream>
using namespace std;

int arr[6] = {0};

void moonstep(int idx, int len) {
	if (idx == len-1) {
		cout << arr[idx] << " ";
		return ;
	}

	cout << arr[idx] << " ";
	moonstep(idx + 1, len);
	cout << arr[idx] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int idx = 0;
	int len = 6;

	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	moonstep(idx, len);
	cout << "\n";

	return 0;
}
