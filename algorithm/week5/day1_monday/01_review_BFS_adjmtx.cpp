#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// ���� ��ķ� ����
///*BFS ���� ����
//1. �׷��� ����(�Է��� �޴´�) - �� node �� ����
//2. queue �� ����
//3. ���� ��� ����
//4. queue ���� node(now)�� �ϳ� ����
//   -> ���� ���ѳ��� ������ node
//5. now���� �� �� �ִ� node(next)�� ã��
//6. next���� queue�� �߰�
//7. 4~6 �ܰ� �ݺ�
//   -> ��������? queue�� ����� �� ����
//*/
//
//int main() {
//
//	int nodeNum;
//	int adjMtx[10][10] = { 0, };
//
//	// 1. �׷��� ����
//	cin >> nodeNum;
//	for (int i = 0; i < nodeNum; i++) {
//		int from, to;
//		cin >> from >> to;
//		adjMtx[from][to] = 1;
//	}
//
//	// 2. queue ����
//	queue<int> q;
//	int startNode = 1;
//	q.push(startNode);
//
//	while (!q.empty()) {
//		int now = q.front();
//		q.pop();
//
//		for (int i = 1; i <= 9; i++) {
//			int next = i;
//			if (adjMtx[now][next] == 0)
//				continue;
//			q.push(next);
//		}
//
//	}
//
//
//	return 0;
//}


//// ���� ����Ʈ�� ����
//int main() {
//
//	int nodeNum;
//	vector<int> adjList[10];
//	cin >> nodeNum;
//
//	// 1. get the graph
//	for (int i = 0; i < nodeNum; i++) {
//		int from, to;
//		cin >> from >> to;
//		adjList[from].push_back(to); // ������
//		adjList[to].push_back(from); // ������
//	}
//
//	queue<int> q;
//	int startNode = 1;
//	q.push(startNode);
//
//	while (!q.empty()) {
//		int now = q.front();
//		q.pop();
//		
//		cout << now << ' ';
//
//		for (int i = 0; i < adjList[now].size(); i++) {
//			int next = adjList[now][i];
//
//			q.push(next);
//		}
//
//	}
//
//}

// FloodFill? 
// -> BFS(������� or ��������Ʈ) + ����迭
// --> 1) ����迭 üũ
// --> 2) �湮���� ������ ����
// --> +) ���̸� ���� 
// --> *) visited[next.r][next.c] = 1 + visited[now.r][now.c]
// -----> ����� �� ������ row, col�� ��ġ�ϴ� ���� + 1�� ���ϰ� �Ǹ� 
// -----> �� ���� level�� ���ľ� �ϴ��� �ľǵȴ�
// 
// -> DFS(������� or ��������Ʈ) + ����迭