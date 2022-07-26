#include <iostream>
using namespace std;

string branch = "ABC";
string path;
char DAT[3];
int lvl;
int cnt = 0;

void func(int level) {
	// 기저조건
	if (level == lvl) {
		for (int j = 0; j < 3; j++) {
			if (DAT[j] == 3) {
				return;
			}
		}
		cnt++;
		cout << path << "\n";
		return;
	}

	// 재귀조건
	for (int i = 0; i < branch.length(); i++) {
		if (DAT[branch[i] - 'A'] >= 3) {
			continue;
		}

		path.push_back(branch[i]);
		DAT[branch[i] - 'A'] += 1;

		func(level + 1);
		path.pop_back();
		DAT[branch[i] - 'A'] -= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> lvl;
	func(0);
	if (lvl == 0){
		cout << 0 << "\n";
	}else{
		cout << cnt << "\n";
	}

	return 0;
}