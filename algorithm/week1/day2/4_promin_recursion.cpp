#include <iostream>
using namespace std;

void bbq(int num) {
	if (num == 3) {
		return;
	}

	bbq(num+1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
		
	bbq(0);
	cout << "\n";

	return 0;
}
