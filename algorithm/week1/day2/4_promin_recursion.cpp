#include <iostream>
using namespace std;

int arr[] = { 3, 7, 4, 1, 9, 4, 6, 2 };

void printing(int idx) {
	if (idx == 0) {
		cout << arr[idx] << " ";
		return;
	}

	cout << arr[idx] << " ";
	printing(idx-1);
	cout << arr[idx] << " ";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int num;
	cin >> num;
	
	printing(num);
	cout << "\n";

	return 0;
}
