#include <iostream>
#include <queue>
using namespace std;

struct Node { int r, c; };

struct compare {
	bool operator()(char a, char b) {
		// return true: b가 우선순위가 더 높음
		// return false: a가 우선순위가 더 높음

		if (a < b) return true; 
		if (a > b) return false;
		// sort는 정상일 때 return true였지만
		// pq는 비정상 일 때 true라고 이해하자.

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