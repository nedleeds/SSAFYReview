#include <iostream>
#include <vector>
using namespace std;

string oilGauge;

void binarySearch(int left, int right) {
	int mid = (left + right) / 2;

	if (left == right && oilGauge[mid] == '_' ) {

	}else if (mid < right){

	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> oilGauge;
		binarySearch(0, n);
	}

	return 0;
}