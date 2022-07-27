#include <iostream>
#include <cstring>
using namespace std;

string logs;

void upper(){
	for (int i = 0; i < logs.length(); i++) {
		if ('a' <= logs[i] && logs[i] <= 'z') {
			logs[i] -= 'a' - 'A';
		}
	}
}

int FIND(string target) {
	int idx = 0, cnt = 0;
	while (idx < logs.length()) {
		int find_idx = logs.find(target, idx);
		if (find_idx != -1) {
			idx = find_idx;
			idx += target.length();
			cnt++;
		}
		else {
			idx++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	
	cin >> logs;
	upper();

	int pass_num = FIND("PASS");
	int fail_num = FIND("FAIL");
	
	cout << pass_num / (pass_num + fail_num) * 100 << "%\n";

	return 0;
}