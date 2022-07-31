#include <iostream>
#include <vector>
using namespace std;

int arr[9] = {
	3, 1, 2, 1, 3, 2, 1, 2, 1
};

void func(int currIdx) {
	if (currIdx >= 9) {
		cout << "도착 ";
		return;
	}

	cout << arr[currIdx] << ' ';
	func(currIdx + arr[currIdx]);
	cout << arr[currIdx] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int startIdx;
	cin >> startIdx;

	cout << "시작 ";
	func(startIdx-1);
	cout << "시작\n";


	return 0;
}