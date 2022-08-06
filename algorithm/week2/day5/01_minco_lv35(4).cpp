#include <iostream>
#include <queue>
using namespace std;

struct Edge {
	int nodeFrom;
	int nodeTo;
	int cost;
};

bool operator < (Edge a, Edge b) {
	// < : greater operator : default - MINMAX Heap (return true)
	// return false : MIN HEAP (������ �켱������ �� ����)
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;

	// if a.cost == b.cost
	if (a.nodeFrom < b.nodeFrom) return false;
	if (a.nodeFrom > b.nodeFrom) return true;

	// if a.cost == b.cost && a.nodeFrom == a.nodeFrom
	if (a.nodeTo < b.nodeTo) return false;
	if (a.nodeTo > b.nodeTo) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	cin >> num;

	//priority_queue���ٰ� ���� ���� + cost �Է� 
	priority_queue<Edge> pq;
	for (int r = 0; r < num; r++) {
		for (int c = 0; c < num; c++) {
			int cost;
			cin >> cost;
			if (cost <= 0) continue;
			if (r >= c) continue;
			pq.push({ r, c, cost });
		}
	}

	//cost ���鸸 �����ؼ� vector�� �ֱ�
	int cnt = 0;
	Edge e;
	while (cnt < 10) {
		e = pq.top();
		e.cost *= 2;
		pq.pop();
		pq.push(e);
		cnt++;
	}
	
	cout << e.cost << "����\n";

	return 0;
}
/*
-----------------[ �� ���� 1 ]-----------------
1.	priority_queue
	-> ���� ���� + cost �Է� 

2.	vector �� cost ���� �ֱ� (Ʋ��)
	-> ���⼭ ���� �߻�
	-> ������ ���ǿ� ���缭 pq�� �����Ǵµ�,
	-> �ű�鼭 cost �������θ� �����.

3. vector ������ ���鿡 *=2 ���� (Ʋ��)

-----------------[ �� ���� 2 ]-----------------
1. priority_queue -> ���� + cost

2-A. priority_queue 
	-> pop ���� �ʰ�, front() �� ����
	-> front() *= 2
	-> �̰� 10�� �ݺ�.
	-> index = index % pq.size()
	   index++;
	==> !!! pq�� index ������ �Ұ� !!!
	==> HEAP ������ pop���� �ֻ��� node������
	    push�� ���Ը� �����ϴ�.
	==> ���� ���� ���뵵, push �������� cost�� ����
	    ������ �ٲ�� �� ����ؾ� ����ó���� �ƴ�.
	==> ���� ������ Ǯ�̴� 2-B.�� ����.

2-B. priority_queue
	-> �� 10���� �ݺ���
	-> �ش� �ݺ��� �ȿ��� top()�� e(Edge) ������ pop()
	-> e�� costs *= 2 (���� ����)
	-> push(): �ڵ����� overriding �� �Ŀ� ���� ���ĵ�.
	-> �ݺ��� ���� �� e ���
	
-----------------[ ������ ���� ]-----------------
���� ����
*/