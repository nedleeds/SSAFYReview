#include <iostream>
using namespace std;

string branch;
string path;
int cnt = 0;

int checkPath() {
	for (int i = 1; i < path.length(); i++) {
		int dif = path[i] - path[i - 1];
		if (dif > 3 || dif < -3) {
			return 0;
		}
	}
	return 1;
}

void func(int level) {
	// 기저 조건
	if (level == 4) {
		if (!checkPath()){
			return;
		}
		cnt++;
		return;
	}

	//재귀 조건
	for (int i = 0; i < branch.length(); i++) {
		path.push_back(branch[i]);
		func(level + 1);
		path.pop_back();

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> branch;

	func(0);
	cout << cnt << "\n";

	return 0;
}