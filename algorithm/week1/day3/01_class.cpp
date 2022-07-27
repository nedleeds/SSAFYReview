#include <iostream>
using namespace std;

int dice_num;
int print_num;
int DAT[19];
string branch = "123456";
string path;

void print_all(int level) {
	if (level == dice_num) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < branch.length(); i++) {
		path.push_back(branch[i]);
		print_all(level + 1);
		path.pop_back();
	}
}

void setDAT() {
	for (int i = 0; i < path.length(); i++) {
		DAT[(path[i] - '0')] += 1;
	}
}

int checkDAT() {
	int currDAT[19] = { 0, };
	for (int k = 0; k < path.length(); k++) {
		currDAT[path[k] - '0'] += 1;
	}

	for (int j = 0; j < 19; j++) {
		if (DAT[path[j] - '0'] != currDAT[path[j] - '0']) {
			return 1;
		}
	}
	return 0;
}

void print_wo_duplicate(int level) {
	if (level == dice_num) {
		if (checkDAT()) {
			setDAT();
			cout << path << "\n";
		}

		return;
	}

	for (int i = 0; i < branch.length(); i++) {
		path.push_back(branch[i]);
		print_wo_duplicate(level + 1);
		path.pop_back();

	}
}
void print_different(int level) {
	if (level == dice_num) {
		cout << path << "\n";
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