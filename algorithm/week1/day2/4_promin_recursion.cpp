#include <iostream>
using namespace std;

int arr[6] = {0};

void jump(int num, int jumpCnt) {
	if (jumpCnt == 3) {
		cout << num << " ";
		return;
	}
	
	jump(num + 2, jumpCnt + 1);
	cout << num << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int num = 0;
	cin >> num;

	jump(num, 0);
	cout << "\n";

	return 0;
}
