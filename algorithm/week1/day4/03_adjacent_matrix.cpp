#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int node, edge;
	cin >> node >> edge;
	int arr[100][100] = { 0 };

	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;
		if (arr[to][from] == 0) {
			arr[from][to] = 1;
		}
	}

	for (int from = 1; from <= node; from++) {
		for (int to = 1; to <= node; to++) {

			cout << arr[from][to] << " ";

		}
		cout << '\n';
	}

	return 0;
}