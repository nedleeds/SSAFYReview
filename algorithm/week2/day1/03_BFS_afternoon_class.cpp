#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���� ��� BFS

// nodeNum : ����� ����
// edgeNum : ������ ����
/*
9 8
1 2
1 7
2 3
3 4
3 8
4 5
4 6
8 9
*/

int numNode, numEdge;
int mat[10][10];

void bfs(int node) {
	// 2������ ����
	// ** ��Ȳ�� ���� �������� ������ �ʿ䰡 �ִ�.
	// ** FloodFill (ex-���� node�� 2���� �� ��.)
	
	// 1. queue ����
	queue<int> q;
	q.push(node); // ���� ��� ����ä�� ����.
	
	// 2. (�׷��� ����) --> visited ���� �ʿ�
	int visited[10] = { 0, }; //**�Լ� ������ ����� {0,} �ʱ�ȭ �ʿ�.
	// ���� ��� �湮 ���
	visited[node] = 1; // **�׷��� ����**

	//bfs�� logic
	// �� �̻� ���� �� �ִ� ����� �ĺ����� ���� ������ �ݺ�
	// --> queue�� �� �̻� ���� �� �ִ� ��尡 ���� !!
	while (!q.empty()) {
		// ���� node�� ����!
		int now = q.front();
		q.pop();

		cout << now << ' ';

		// ���� (now)���κ��� �� �� �ִ� �ĺ������� Ȯ���ϰ� q�� �־�!
		for (int i = 1; i <= numNode; i++) {
			int next = i;
			// ���� �ĺ����� �� �� �ִ��� üũ
			// DFS�� ����
			
			// 1. (�������) �� �� �ִ��� (��ΰ� �ִ���)
			if (mat[now][next] == 0)
				continue;

			// 2. �湮�� ���� �ִ°�?
			if (visited[next] == 1)
				continue;

			// next�� ã�Ҵ�!
			// 1. �湮 üũ
			visited[next] = 1;
			// 2. q�� �־� 
			q.push(next);

		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> numNode >> numEdge;

	//������ ���� ��ŭ �Է�
	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		mat[from][to] = 1;
		mat[to][from] = 1; // ������
	}
	
	// bfs Ž�� ����
	bfs(1);

	return 0;
}