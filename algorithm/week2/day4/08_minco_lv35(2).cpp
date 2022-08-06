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

	// 1. n개의 도시 (node수 입력)
	int numNode;
	cin >> numNode;

	// 2. adjacent Matrix 입력	
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
떠오른 두 가지 풀이법.
1) vector -> push + sort -> 0 ~ 2
2) priority queue -> operator 설정 -> pop 3번 [이걸로 해보자]***
   --> 미쳤네;;
   --> 구조체로 Heap ( from, to, cost ) 넣고,
   --> cost로 정렬해서 top() + pop()으로 앞에서 빼주고,
   --> 그걸로 바로 from, to, cost 동시 출력 가능
*/