#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adjList[101];
vector<int> path;
int visited[101];
int numNode, numEdge;

void dfs(int now) {
	/*if (adjList[now].size() == 0) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << ' ';
		cout << '\n';
	}*/

	for (int i = 0; i < adjList[now].size(); i++) {
		int next = adjList[now][i];
		if (visited[next] != 0) continue;

		path.push_back(next);
		visited[next] = 1;

		dfs(next);
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> numNode >> numEdge;

	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	visited[1] = 1;
	path.push_back(1);
	dfs(1);

	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		if (visited[i] > 0) {
			cnt++;
		}
	}
	cout << cnt-1;
	return 0;
}
/*
�� ���� ����� ��� ��尡 �����ȴ�.
������ ��忩�� �ᱹ �׵��� �׷쳢�� ����.

��ǻ�� ���� 100������, ��������Ʈ�� �����غ���.

[�Է�]
1. ��ǻ�� �� �Է�
   ��ǻ�� ��ȣ(��� ��ȣ�� 1������!!)

2. ��° �ٺ��� ��Ʈ��ũ �󿡼� ����� ���� ���� �־���
   ���� ����ŭ from - to �Է�

[���]
1. 1�� ��ǻ�Ͱ� ���̷��� �ɷ��� ��, �� ���̷����� �ɸ��� ��ǻ�� �� ���

[����]

�⺻ dfs ����? - �ѹ��� �ݺ� no
+ backtracking (path �߰�)
+ ������
dfs(1) �ְ�,
visited üũ �� ����
path�־�� ��
-------������� �ϴ� ����----------
visited �� ���� 0���� �ٽ� �ʱ�ȭ ���ϰ� ���θ�,
�湮�� ������ üũ�� �ǰ� �ٵ��� ����.
�׷� main���� 0�� �ƴ� �� counting !!
-------�Ϻ� ���� ó�� ��-------

������, �������� �ƴϾ��� ����.
��� �˾Ҵ���? --> Ʋ�� ���� ��ΰ� �۰� ���԰�
�� �۰� �������� �����غ� ���, �� ���Ҵٴ� �Ǵ�.
�׷��� ���������� �ٽ� �����ؼ� ���� ��� ����ó��.

*/