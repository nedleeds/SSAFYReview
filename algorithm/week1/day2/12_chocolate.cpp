#include <iostream>
using namespace std;

string branch = "ABC";
string path;
int lvl;
int cnt = 0;

void func(int level) {
	// 기저조건
	if (level == lvl) {
		int k = 0;
		if (0 <= path.find("AAA") && path.find("AAA") < lvl) {
			return;
		}
		else if (0 <= path.find("BBB") && path.find("BBB") < lvl) {
			return;
		}
		else if (0 <= path.find("CCC") && path.find("CCC") < lvl) {
			return ;
		}

		cnt++;
		return;
	}

	// 재귀조건
	for (int i = 0; i < branch.length(); i++) {
		if (0 <= path.find("AAA") && path.find("AAA") < lvl ){
			continue;
		}
		else if (0 <= path.find("BBB") && path.find("BBB") < lvl) {
			continue;
		}
		else if (0 <= path.find("CCC") && path.find("CCC") < lvl) {
			continue;
		}

		path.push_back(branch[i]);

		func(level + 1);
		
		path.pop_back();
		
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