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
			cout << i << "초\n";
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
				cout << i << "초\n";
				return 0;
			}
		}
	}

	return 0;
}
/*
인접행렬 + 방향 배열 + visited(1이면) continue
매번 for문으로 다 터졌는지 확인한다?
문제에서 N size -> 1~1000
매번 백만번씩 확인한다는 것은 무리!

0. 인접리스트 생성(N: 1001)
   visited 생성.
1. 처음 N사이즈 입력
2. 인접행렬 입력 
   -> 방향 행렬: 인접 4군데 item 을 인접 리스트에 입력.
3. priority queue로 해당 인접리스트 sort
4. pop + not visited 면
   --> checked(vector)에 본인 + 인접 다 넣어.
5. checked.size()가 N*N이면 stop.


*/
