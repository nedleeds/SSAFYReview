#include <iostream>
#include <queue>
using namespace std;

struct Node { int r, c; };

struct compare {
	bool operator()(char a, char b) {
		// return true: b�� �켱������ �� ����
		// return false: a�� �켱������ �� ����

		if (a < b) return true; 
		if (a > b) return false;
		// sort�� ������ �� return true������
		// pq�� ������ �� �� true��� ��������.

		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	priority_queue<char, string, compare> pq;
	
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		pq.push(s[i]);
	}
	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}

	return 0;
}