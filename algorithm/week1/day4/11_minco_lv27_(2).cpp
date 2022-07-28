#include <iostream>
#include <vector>

using namespace std;
string commands[3] = {
	"push", "pop", "printLast"
};

vector<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int num;
			cin >> num;
			arr.push_back(num);
		}
		else if (s == "printLast") {
			cout << arr[arr.size() - 1] << '\n';
		}
		else if (s == "pop") {
			arr.pop_back();
		}
	}

	return 0;
}