#include <iostream>
using namespace std;

void printing(int value, int end) {
	if (value == end) {
		cout << value << " ";
		return;
	}

	cout << value << " ";
	printing(value + 1, end);
	cout << value << " ";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int start, end;
	cin >> start >> end;
	
	printing(start, end);
	cout << "\n";

	return 0;
}
