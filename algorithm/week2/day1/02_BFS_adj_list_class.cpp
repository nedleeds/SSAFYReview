#include <iostream>
#include <vector>
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
9
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
	vector<int> adj_lst[10];
	cin >> nodeNum;

	// 1. �׷��� ����
	for (int i = 0; i < nodeNum; i++) {
		int from, to;
		cin >> from >> to;
		adj_lst[from].push_back(to);
	}

	// 2. queue ����
	queue<int> q;

	// 3. ���� ��� ����
	q.push(1);

	// 7. queue�� ����� ������
	while (!q.empty())
	{
		// 4. now node ������
		int now = q.front();
		q.pop();

		// 4-1) now node �ٷ��
		cout << now << ' ';

		// 5. next node queue�� �ֱ�
		for (int i = 0; i < adj_lst[now].size(); i++) {
			int next = adj_lst[now][i];

			q.push(next);
		}
	}

	return 0;
}