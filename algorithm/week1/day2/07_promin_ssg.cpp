#include <iostream>
using namespace std;

string branch = "ABC";
string path = "";
int lvl;

void func(int level) {
	if (level == lvl) {
		if 
		return ;
	}

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

	cin >> lvl;

	func(0);

	return 0;
}