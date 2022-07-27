#include <iostream>
using namespace std;

string note;
string ans[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	cin >> note;

	int underbar_idx;
	int start_idx = 0, cnt = 0;
	while ((underbar_idx = note.find('_', start_idx)) != -1) {
		for (int i = start_idx; i < underbar_idx; i++) {
			ans[cnt].push_back(note[i]);
		}
		if (ans[cnt] != "") {
			cnt++;
		}
		start_idx = underbar_idx + 1;
	}

	if (start_idx != (note.length())) {
		for (int j = start_idx; j < note.length(); j++) {
			ans[cnt].push_back(note[j]);
		}
	}

	int k = 0;
	while (ans[k] != "") {
		cout << k + 1 << "#" << ans[k] << '\n';
		k++;
	}

	return 0;
}