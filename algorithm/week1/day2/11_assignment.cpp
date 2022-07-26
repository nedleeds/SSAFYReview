#include <iostream>
using namespace std;

string branch = "EWABC";
string path;
int DAT[26];
int lvl = 4;
int cnt = 0;
char except;
int isThere() {
	for (int i = 0; i < path.length(); i++) {
		if (path[i] == except) {
			return 1;
		}
	}
	return 0;
}

void func(int level) {
	// 기저조건
	if (level == lvl) {
		if (isThere()){
			return;
		}
		cout << path << "\n";
		return;
	}

	// 재귀조건
	for (int i = 0; i < branch.length(); i++) {
		if (DAT[branch[i] - 'A'] == 1) {
			continue ;
		}
		
		path.push_back(branch[i]);
		DAT[branch[i]-'A'] = 1;
		
		func(level + 1);

		path.pop_back();
		DAT[branch[i] - 'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> except;
	func(0);
	cout << cnt << "\n";

	return 0;
}