#include <iostream>
#include <queue>
using namespace std;

struct Heap {
	int from;
	int to;
	int cost;
};

bool operator < (Heap a, Heap b) {
	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 1. n���� ���� (node�� �Է�)
	int numNode;
	cin >> numNode;

	// 2. adjacent Matrix �Է�	
	priority_queue<Heap> pq;
	for (int from = 0; from < numNode; from++) {
		for (int to = 0; to < numNode; to++) {
			int cost;
			cin >> cost;
			pq.push({from, to, cost});
		}
	}

	int cnt = 0;
	while (cnt < 3) {
		Heap now = pq.top();
		cout << char(now.from + 'A') << "-";
		cout << char(now.to + 'A') << ' ';
		cout << now.cost << "\n";
		pq.pop();
		cnt++;
	}

	return 0;
}

/*
������ �� ���� Ǯ�̹�.
1) vector -> push + sort -> 0 ~ 2
2) priority queue -> operator ���� -> pop 3�� [�̰ɷ� �غ���]***
   --> ���Ƴ�;;
   --> ����ü�� Heap ( from, to, cost ) �ְ�,
   --> cost�� �����ؼ� top() + pop()���� �տ��� ���ְ�,
   --> �װɷ� �ٷ� from, to, cost ���� ��� ����
*/