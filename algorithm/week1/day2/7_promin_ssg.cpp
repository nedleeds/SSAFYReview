#include <iostream>
using namespace std;

string branch = "ABCD";
string target;
string path;

int cnt = 0;
int ans;

void func(int level) {
	// 기저 조건
	if (level == 3) {
		cnt++;
		if (target == path) {
			ans = cnt;
		}
		return;
	}

	// 재귀 조건
	for (int i = 0; i < branch.length(); i++) {
		path.append(1, branch[i]);
		func(level + 1);
		path.pop_back();
		if (ans > 0) {
			return ;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> target;

	func(0);
	cout << ans << "번째\n";

	return 0;
}