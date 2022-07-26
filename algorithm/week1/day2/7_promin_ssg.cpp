#include <iostream>
using namespace std;

string name;
string target;
string path;
int DAT[26];

void func(int level) {
	// 기저 조건
	if (level == 3) {
		cout << path << "\n";
		return;
	}

	// 재귀 조건
	for (int i = 0; i < name.length(); i++) {
		if (DAT[name[i]-'A'] == 1) {
			continue;
		}
		path.append(1, name[i]);
		DAT[name[i] - 'A'] = 1;
		func(level + 1);
		path.pop_back();
		DAT[name[i] - 'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> name;

	func(0);

	return 0;
}