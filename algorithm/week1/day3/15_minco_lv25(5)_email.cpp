#include <iostream>
using namespace std;

string email;
string name;
string domain;
string currEmail;

void extraction() {
	int at_idx = currEmail.find('@', 0);
	int dot_idx = currEmail.find('.', 0);

	for (int i = 0; i <dot_idx; i++) {
		if (i < at_idx) {
			name.push_back(currEmail[i]);
		}
		else if (at_idx < i) {
			domain.push_back(currEmail[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> email;

	int bar_index;
	int start_idx = 0;
	while ((bar_index = email.find('|', start_idx)) != -1) {
		for (int j = start_idx; j < bar_index; j++) {
			currEmail.push_back(email[j]);
		}
		extraction();
		cout << "[#" << name << "] " << domain << "\n";
		start_idx = bar_index + 1;
		name = "";
		domain = "";
		currEmail = "";
	}

	for (int j = start_idx; j < email.length(); j++) {
		currEmail.push_back(email[j]);
	}
	extraction();
	cout << "[#" << name << "] " << domain << "\n";

	return 0;
}