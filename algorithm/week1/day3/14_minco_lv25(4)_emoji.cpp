#include <iostream>
using namespace std;

string newEmoji;
char checked;
int eye_cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string emoji;
	cin >> emoji;

	//sol : 문자 하나씩 추출
	for (int i = 0; i < emoji.length(); i++) {
		if (checked != emoji[i] || (emoji[i] == '^' && (eye_cnt % 2))) {
			newEmoji.push_back(emoji[i]);
			checked = emoji[i];
		}
		if (emoji[i] == '^') {
			eye_cnt++;
		}
		if (emoji[i] != '^' && emoji[i] != '(' && emoji[i] != ')') {
			if (eye_cnt % 2) {
				newEmoji.pop_back();
				newEmoji.push_back('_');
			}
		}
	}

	cout << newEmoji <<"\n";

	return 0;
}