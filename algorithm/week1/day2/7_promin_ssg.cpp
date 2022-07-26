#include <iostream>
using namespace std;

string alphabets;
string check[2] = {
	"BT", "TB"
};
string path;
int total = 0;
int cnt = 0;
void func(int level) {
	// 기저 조건
	if (level == 4) {
		total++;
		for (int i = 0; i < 2; i++) {
			int find_idx = path.find(check[i]);
			if (0 <= find_idx && find_idx < 3) {
				cnt++;
				return;
			}
		}
		return;
	}

	// 재귀 조건
	for (int i = 0; i < alphabets.length(); i++) {
		path.append(1, alphabets[i]);
		func(level + 1);
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> alphabets;

	func(0);

	cout << total-cnt << "\n";

	return 0;
}