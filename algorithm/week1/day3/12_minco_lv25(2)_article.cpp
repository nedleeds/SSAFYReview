#include <iostream>
using namespace std;

int checkNum(char c) {
	if ('0' <= c && c <= '9') {
		return 1;
	}
	return 0;
}
string ans[1000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	int article_num, cnt = 0;
	cin >> article_num;

	for (int i = 0; i < article_num; i++) {
		string article;
		cin >> article;

		int find_idx = 0;
		int start_idx;
		while ((start_idx = article.find("[", find_idx)) != -1) {
			int end_idx = article.find("]", find_idx);
			for (int j = start_idx + 1; j <= end_idx - 1; j++) {
				if (checkNum(article[j])) {
					ans[cnt].push_back(article[j]);
				}
			}
			if (ans[cnt] != "") {
				cnt++;
			}

			find_idx = end_idx + 1;
		}
	}

	for (int i = 0; ans[i] != ""; i++) {
		if (ans[i].length() == 5) {
			cout << '[' << ans[i] << "]\n";
		}
	}

	return 0;
}