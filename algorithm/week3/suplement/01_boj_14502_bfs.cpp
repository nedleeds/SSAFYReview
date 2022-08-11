#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* �Ｚ ä�� ���� ����
* A�� ������ ����
* ���� Ž�� <- �ʹ� ȿ���� ������ �ʾƵ� ������
*/

int maxSize;
int rMax, cMax;
int M = -2134567890;
int adjMtx[10][10] = { 1, };
int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1},
};
struct Node { int row, col; };
queue<Node> viruses;
vector<Node> blanks;

int checkVirus() {
	int numBlank = 0;
	int visited[10][10] = {0,};

	queue<Node> q = viruses;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Node next = { now.row + dir[i][0], now.col + dir[i][1] };
			if (visited[next.row][next.col]) continue;
			if (adjMtx[next.row][next.col] != 0) continue; // 0�� ���

			visited[next.row][next.col] = 1;
			numBlank++; // 0 �̸� ��ĭ �� ���� 
			q.push(next);
		}
	}
	return blanks.size() - 3 - numBlank;
}

int buildWall() {
	for (int i = 0; i < blanks.size(); i++)
		for (int j = i + 1; j < blanks.size(); j++)
			for (int k = j + 1; k < blanks.size(); k++) {
				Node v1 = blanks[i];
				Node v2 = blanks[j];
				Node v3 = blanks[k];

				adjMtx[v1.row][v1.col] = 1;
				adjMtx[v2.row][v2.col] = 1;
				adjMtx[v3.row][v3.col] = 1;

				M = max(M, checkVirus());

				adjMtx[v1.row][v1.col] = 0;
				adjMtx[v2.row][v2.col] = 0;
				adjMtx[v3.row][v3.col] = 0;
			}
	return M;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rMax >> cMax;

	for (int r = 0; r < 10; r++)
		for (int c = 0; c < 10; c++)
			adjMtx[r][c] = 1;

	for (int r = 1; r <= rMax; r++) {
		for (int c = 1; c <= cMax; c++) {
			cin >> adjMtx[r][c];
			if (adjMtx[r][c] == 2)
				viruses.push({ r, c });
			else if (adjMtx[r][c] == 0)
				blanks.push_back({ r, c });
		}
	}

	cout << buildWall() << '\n';


	return 0;
}
/* ����
 [�Է�]
 - ù° �ٿ� ������ rMax, cMax (3<= rMax, cMax <=8)
 - ��° �ٺ��� rMax ���� ���� row�־���
 - 0�� �� ĭ, 1�� ��, 2�� ���̷����� �ִ� ��ġ
 - 2�� ������ 2���� ũ�ų� ���� 10���� ���� �ڿ���
 - �� ĭ ������ 3�� �̻�

 - �Ϻ� ĭ�� ���̷����� �����ϸ�,
 - ���̷����� �����¿�� ������ �� ĭ���� ��� �������� �� �ִ�.
 - ���� ���� �� �ִ� ���� ������ 3���̸�, �� 3���� ������ �Ѵ�.
 - ���̷����� ��� �� ĭ���� �������� �� �ִ�.

 - �ϴ� ���غ��߰ڴµ�?
 - �� ~ �̷��� �÷��� ��~

 [�⺻ �÷�����]
 - �ϴ� ���� �޾ƿͼ�, bfs�� �ѱ��
 - ���� �迭 üũ
   --> ���� + �� + �湮���

 [�ٵ� ���� �����ߵ�]
 - ���� ���� �� �ִ� ��� ����� ���� ���� ���̷��� ������ üũ?
 - �׷� ���� ��� ����ǵ�..?
 - 2 �ֺ� ����迭 Ž�� -> 0 �߰� �� 1�� �־����
 - 0�� �߰��� ��ǥ�� �����س���
 - ����� ��ǥ���� ��ȸ??�ϸ鼭 ���� ����°���
 - ��ȸ ����-> count�� 3�� ����ε� ��� 3���� �������� ����

 [�ؼ�]
 - '3��'��� ������ �������� --> 3�� for���� Ȱ���ؼ� ���� ����� �ȴ�
 - dfs�� n���� ���ؼ� �����ϴ� ��

 [bfs-�� ����]
 - ���� �°� ����.
 - �� �ʱ�ȭ ���ִ� �κ�
 - queue �����ϴ� �κ�
 - bfs �� virus queue �ϳ��� ���� ��
 + �޶��� �κ��� blank ������ ���� queue�� ���� �����ϴ� ��
 - ������??
 --> �ᱹ bfs ���� ��������
 --> �ܱⰣ�� bfs�� �Ĺٹ� �����ؼ�
 --> '�̰� �� ã�ƺ��� �ǰڳ�'�� �����ϴ°� point
 ----> �������� bfs, dfs ������ ���� �ٷιٷ� �ǰԲ� �ؾߵ�

*/