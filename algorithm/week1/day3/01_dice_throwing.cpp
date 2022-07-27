#include <iostream>
using namespace std;

int dice_num;
int print_num;
int DAT[19];
string branch = "123456";
string path;

void print_path() {
	for (int i = 0; i < path.length(); i++) {
		cout << path[i] << " ";
	}
	cout << "\n";
}

void print_all(int level) {
	if (level == dice_num) {
		print_path();
		return;
	}

	for (int i = 0; i < branch.length(); i++) {
		path.push_back(branch[i]);
		print_all(level + 1);
		path.pop_back();
	}
}

void print_wo_duplicate(int level) {
	if (level == dice_num) {
		print_path();
		return;
	}

	for (int i = 0; i < branch.length(); i++) {
		if (level > 0) {
			if (path[level - 1] > branch[i]) {
				continue;
			}
		}
		/*f (level > 0) {
			if (path[level - 1] > i)
				continue;
		}*/
		path.push_back(branch[i]);
		DAT[path[i] - '0'] += 1;
		print_wo_duplicate(level + 1);
		path.pop_back();
		DAT[path[i] - '0'] -= 1;

	}
}
void print_different(int level) {
	if (level == dice_num) {
		print_path();
		return;
	}

	for (int i = 0; i < branch.length(); i++) {
		if (DAT[branch[i] - '0'] > 0) {
			continue;
		}

		path.push_back(branch[i]);
		DAT[branch[i] - '0'] += 1;

		print_different(level + 1);

		path.pop_back();
		DAT[branch[i] - '0'] -= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> dice_num >> print_num;

	if (print_num == 1) {
		print_all(0);
	}
	else if (print_num == 2) {
		print_wo_duplicate(0);
	}
	else if (print_num == 3) {
		print_different(0);
	}

	return 0;
}