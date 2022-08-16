#include <iostream>
#include <queue>
using namespace std;



struct Item {
	int weight;
	int isGold;
};

vector<int> jjangdol;
int check(int gold) {
	for (int i = 0; i < jjangdol.size(); i++) {
		if (jjangdol[i] == gold) {
			return 0;
		}
	}
	return 1;
}

bool operator<(Item A, Item B) {
	if (A.weight < B.weight) return false;
	if (A.weight > B.weight) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	priority_queue<Item> pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push({ num, 1 });
	}

	int cntGold = 0;
	while (true) {
		// 1. °¡º­¿î µ¹ 2°³ »«´Ù.
		Item first = pq.top();
		pq.pop();
		if (first.isGold)
			cntGold++;
		else {
			cout << cntGold << '\n';
			return 0;
		}

		Item second = pq.top();
		pq.pop();
		if (second.isGold)
			cntGold++;
		else {
			cout << cntGold << '\n';
			return 0;
		}

		// 2. Â¯µ¹À» ³Ö´Â´Ù
		pq.push({ second.weight * 2, 0 });
	}


	return 0;
}