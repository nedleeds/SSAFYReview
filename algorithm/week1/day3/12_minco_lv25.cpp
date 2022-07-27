#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string subject;
		cin >> subject;

		int j = 0;
		while ( int start_idx = subject.find("[", j) != -1){
			int end_idx = subject.find("]");
			for (int i = start_idx; i <= end_idx; i++) {
				cout << subject[i];
			}
			j = end_idx + 1;
			cout << '\n';
		}
	}
	


	return 0;
}