#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DAT[27];
string ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (DAT[s[i] - 'A'] == 0) {
			DAT[s[i] - 'A'] = 1;
			ans += s[i];
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}