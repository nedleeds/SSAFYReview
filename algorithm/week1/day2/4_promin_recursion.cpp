#include <iostream>
using namespace std;

void printing(int num) {
	if (num == 0) {
		return;
	}

	printing(num/2);
	cout << num << " ";
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
