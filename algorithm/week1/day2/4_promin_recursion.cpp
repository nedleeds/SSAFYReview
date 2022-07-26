#include <iostream>
using namespace std;

void bbq(int i) {
	if (i == 4) {
		return ;
	}
	bbq(i + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	bbq(0);

	return 0;
}
