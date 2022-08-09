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


	//O(N*N) - 인접행렬 받아오기
	int N;
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int curr;
			cin >> curr;
			MAP[r][c] = curr;
		}
	}

	//O(N*N) - 연결된 폭탄들 받아오기
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

	//O(N*N) - 연결된 폭탄들 터뜨리기
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
----------------[ 내 설계 ]-----------------
인접행렬 + 방향 배열 + visited(1이면) continue
매번 for문으로 다 터졌는지 확인한다?
문제에서 N size -> 1~1000
매번 백만번씩 확인한다는 것은 무리!

1. 처음 N사이즈 입력

2. 인접행렬 입력 
   -> 방향 행렬: 인접 4군데 item 을 인접 리스트에 입력.
   -> 인접리스트 생성(N: 1001) + visited 생성

3. visited index 순서대로 접근
   -> 폭탄 하나씩 터뜨리면서,
   -> 터질 때마다 cnt++ 
   -> cnt 올리고 나서는 N*N과 같은지 체크.
   -> 같으면 출력 + 종료

----------------[ 교수님 설계 ]----------------
priority queue를 쓰면 쉽다~

1. 인접행렬 입력
   -> priority queue에 {현재 좌표 + 폭탄 번호} 넣어

2. operator overiding 으로 폭탄 번호 내림차순 정렬

3. pop 시작.
   -> *** pop 했을 때, 해당 폭탄의 좌표 값이 있다?	***
      *** 방향 배열 때려서 체크!!!				***
      *** 여기서 방향을 가운데 포함으로 5개 설정	***
      *** 체크 사항: 범위 + 폭탄 터졌었니			***
	  *** 모든 걸 통과: cnt++					***

4. priority queue가 빌 때까지 or 모든 폭탄 다 터질 때까지 반복

*/
