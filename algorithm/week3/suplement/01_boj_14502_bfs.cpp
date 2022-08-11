#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* 삼성 채용 기출 문제
* A형 정도의 난도
* 완전 탐색 <- 너무 효율을 따지지 않아도 괜찮다
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
			if (adjMtx[next.row][next.col] != 0) continue; // 0만 통과

			visited[next.row][next.col] = 1;
			numBlank++; // 0 이면 빈칸 수 증가 
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
/* 설계
 [입력]
 - 첫째 줄에 지도의 rMax, cMax (3<= rMax, cMax <=8)
 - 둘째 줄부터 rMax 동안 지도 row주어짐
 - 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치
 - 2의 개수는 2보다 크거나 같고 10보다 작은 자연수
 - 빈 칸 개수는 3개 이상

 - 일부 칸은 바이러스가 존재하며,
 - 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
 - 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
 - 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

 - 일단 다해봐야겠는데?
 - 아 ~ 이래서 플러드 필~

 [기본 플러드필]
 - 일단 맵을 받아와서, bfs로 넘긴다
 - 방향 배열 체크
   --> 범위 + 벽 + 방문기록

 [근데 벽을 세워야돼]
 - 벽을 세울 수 있는 모든 경우의 수에 대한 바이러스 퍼짐을 체크?
 - 그럼 벽은 어떻게 세울건데..?
 - 2 주변 방향배열 탐색 -> 0 발견 시 1을 넣어야지
 - 0을 발견한 좌표를 저장해놓고
 - 저장된 좌표들을 순회??하면서 벽을 세우는거지
 - 순회 조건-> count가 3인 경우인데 어떻게 3개를 뽑을지도 관건

 [해설]
 - '3개'라고 갯수가 정해졌다 --> 3중 for문을 활용해서 벽을 세우면 된다
 - dfs는 n개에 대해서 적용하는 것

 [bfs-내 설계]
 - 거의 맞게 들어갔다.
 - 벽 초기화 해주는 부분
 - queue 세팅하는 부분
 - bfs 시 virus queue 하나더 쓰는 것
 + 달랐던 부분은 blank 영역에 대한 queue를 만들어서 적용하는 것
 - 문제는??
 --> 결국 bfs 구현 문제였음
 --> 단기간에 bfs를 파바박 구현해서
 --> '이거 다 찾아보면 되겠네'를 구현하는게 point
 ----> 이제부턴 bfs, dfs 구현은 거의 바로바로 되게끔 해야돼

*/