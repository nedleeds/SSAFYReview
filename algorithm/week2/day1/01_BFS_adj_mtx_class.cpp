#include <iostream>
#include <queue>
using namespace std;

//BFS Ư¡
/*
- ���� Ž�� (����� ��� node�� �鸰��.)
- Queue�� ����Ѵ�.
- **�ּ����� node�� �鸮��** ���.
  (�� �� �ִ� �Ÿ��� ���ϴ� ��쿡 ���Ǳ⵵ �Ѵ�)
  (!! �������� �ƴϴ� !!)
*/

/* input
7
1 2
1 7
2 3
3 4
4 5
4 6
8 9
*/

/* BFS ���� ����
1. �׷��� ����(�Է��� �޴´�) - �� node �� ����
2. queue�� ����
3. ���� ��� ����
------------------- �غ�Ϸ�
4. queue���� node(now)�� �ϳ� ����
   ��> ���� ���ѳ��� ������ node
5. now ���� �� �� �ִ� node(next)�� ã��
6. next ����  queue�� �߰�

7. 4~6 �ܰ� �ݺ�
   ��> ��������? �� �̻� ������ �Ͼ�� ���� �� ����.
   ��> == queue �� ������� Ÿ�̹�.

������ ��������, �ܰ踸 �˰� �����ϸ�
�ڵ� ���� BFS�� ���� �׻� �����ϴ�.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int nodeNum;
	int adj_mtx[10][10] = { 0, };

	// 1. �׷��� ����
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++) {
		int from, to;
		cin >> from >> to;
		adj_mtx[from][to] = 1;
	}

	// 2. Queue ����
	queue<int> q; // queue�� �ִ� ���� : !! Node ���� !!


	// 3. ���� ��� ����
	int startNode = 1;
	q.push(startNode);

	// 7. 4~6�ܰ� �ݺ�
	// queue�� ������� �ʾҴ� == �������� ���� ������ node(next)�� ���Ҵ�.
	while(!q.empty()) { 
		// 4.queue���� node(now)�� �ϳ� ����
		int now = q.front(); // now -> �̹��� ������ ���ѳ��� node
		q.pop();

		// ----- �̹��� now�� ��ȴ� -------
		cout << now << ' ';
		// --------------------------------

		// 5. now���� �� �� �ִ� node(next)�� ã��.
		for (int next = 1; next <= 9; next++) {
			if (adj_mtx[now][next] == 0) continue; // now->next �� �� �� ����

			// next�� ã�Ҵ�!!!

			// now->next ���� : ������ų �� �ִ�!
			// 6. next�� queue���ٰ� �־��ش�.
			q.push(next);
		}
	}


	return 0;
}