#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row, col;
};

int main() {
	int size;
	cin >> size;
	int MAP[10][10];

	// BFS 1�ܰ� : �׷��� ���� <- �� node���� ����(� node�� �� �� �ִ°�?)
	for (int row = 0; row < size; row++)
		for (int col = 0; col < size; col++) 
			cin >> MAP[row][col];

	/*
	row, col <- ����ؼ� ������ ��
	row��� row, col
	*/
	
	// 2. Queue�� ����
	queue<Node> q;
	int used[10][10] = { 0, };

	// 3. ������ ����
	q.push({ 0, 0 });

	while (!q.empty()) {
		// 4. now ������
		Node now = q.front();
		q.pop();

		// 5. *** now -> next ã�� (�����¿�) --> ����迭
		int dr[] = { 0, 0, 1, -1 };
		int dc[] = { 1, -1, 0, 0 };
		for (int i = 0; i < 4; i++) {
			// next position ����ϱ�
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];
			// MAP�� ����� ��ǥ�� ���Ǹ� ����
			if (0 > nextRow || nextRow >= size || 0 > nextCol || nextCol >= size)
				continue;
			// �̹� �湮�� ���� ������ ����
			if (used[nextRow][nextCol] == 1) 
				continue;
			// ���̸� ����
			if (MAP[nextRow][nextCol] == 1)
				continue;

			// 6. next�� queue�� �߰�
			used[nextRow][nextCol] = 1 + used[now.row][now.col]; 
			// ����� �� ������ row, col�� ��ġ�ϴ� ���� + 1�� ���ϰ� �Ǹ� 
			// �� ���� level�� ���ľ� �ϴ��� �ľǵȴ�.
			q.push({ nextRow, nextCol });
		}
	}

	return 0;
}
