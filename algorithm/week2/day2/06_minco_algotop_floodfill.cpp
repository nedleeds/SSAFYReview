#include <iostream>
#include <queue>
using namespace std;

// �÷�����
// 2���� �迭������ BFS
// --> ���� ���׿��� BFS ������ ���´� --> 100% �÷�����
// --> ���׿� ������ ��ť
// �⺻���� �ۼ� Ʋ�� �ٲ�� ���� ���� XX
// --> 1. ����,  2. ���� ����
// visited�� ä���� -> ���۳�� -> �� �������� "�ִ� ���"�� ã�� ����.

// ���� �ڵ�
// 5x5 �迭 (MAP) �� �ְ�,
// Ư�� ��ǥ�� ������ �� -> �Էµ� �ٸ� ��ǥ������ �ִܰ�δ� ��?

int sy, sx; // ���� ��ǥ
int ey, ex; // ���� ��ǥ

// ������Ʃ��ó�� Ư�� ��忡 ������ ������ 
// ��� ��带 ���ĿԴ°��� ���.
int visited[5][5];

// �� �� �ִ°�? + �÷��� ��? --> ����迭

int ydir[] = { 0, 0, -1, 1 };
int xdir[] = { -1, 1, 0, 0 };


struct Node {
	int y, x;
};

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y, x });

	// visited ����
	// ���۳�� 1�� ����.
	visited[y][x] = 1;

	// floodfill
	while (!q.empty()) {
		// ���� �� �� �ִ� ��带 ������
		Node now = q.front();
		q.pop();

		// ������ ���� �� �� �ִ°�?
		// ** ���� �迭 üŷ **
		for (int i = 0; i < 4; i++) {
			// ���� ����� y, x (row, col) Ȯ��
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			// ���� �迭 ��� ��, �ʼ������� ���� �˻�
			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
				continue;
			// �湮 ��� üũ
			if (visited[ny][nx] > 0) 
				continue;
			//// �߰� ���� ġ�� (�ɼ�)

			// ���� ��ǥ �Ѿ�� ���� �������.
			visited[ny][nx] = visited[now.y][now.x] + 1;
			// ���� ��� �� ������ ��.
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> sy >> sx;

	// �÷��� �ʷ� �ϴ� ���� ä���.

	bfs(sy, sx);

	// �湮 ��� ���
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}

	cin >> ey >> ex;
	// (sy, sx)���� (ey, ex)��ǥ������ �ִ� �Ÿ�
	cout << visited[ey][ex];

	return 0;
}