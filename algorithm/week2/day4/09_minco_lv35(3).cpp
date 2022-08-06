#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Bomb {
	int curr;
	queue<int> adjacent;
};

int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

Bomb bombs[1001];
int MAP[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	//O(N*N)
	int N;
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int curr;
			cin >> curr;
			MAP[r][c] = curr;
		}
	}

	//O(N*N)
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			Bomb b;
			b.curr = MAP[r][c];
			for (int i = 0; i < 4; i++) {
				int nr = r + dir[i][0];
				int nc = c + dir[i][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)
					continue;
				b.adjacent.push(MAP[nr][nc]);
			}
			bombs[MAP[r][c]] = b;
		}
	}

	int cnt = 0;
	int visited[1001] = {0,};
	for (int i = 1; i <= N*N; i++) {
		
		if (visited[bombs[i].curr] != 0)
			continue;

		visited[bombs[i].curr] = 1;
		cnt += 1;

		if (cnt == N * N) {
			cout << i << "��\n";
			return 0;
		}

		while (!bombs[i].adjacent.empty()) {
			int next = bombs[i].adjacent.front();
			bombs[i].adjacent.pop();
			if (visited[next] == 0){
				visited[next] = 1;
				cnt += 1;
			}
			if (cnt == N * N) {
				cout << i << "��\n";
				return 0;
			}
		}
	}

	return 0;
}
/*
������� + ���� �迭 + visited(1�̸�) continue
�Ź� for������ �� �������� Ȯ���Ѵ�?
�������� N size -> 1~1000
�Ź� �鸸���� Ȯ���Ѵٴ� ���� ����!

0. ��������Ʈ ����(N: 1001)
   visited ����.
1. ó�� N������ �Է�
2. ������� �Է� 
   -> ���� ���: ���� 4���� item �� ���� ����Ʈ�� �Է�.
3. priority queue�� �ش� ��������Ʈ sort
4. pop + not visited ��
   --> checked(vector)�� ���� + ���� �� �־�.
5. checked.size()�� N*N�̸� stop.


*/
