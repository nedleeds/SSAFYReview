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

	// BFS 1단계 : 그래프 구성 <- 각 node간의 관계(어떤 node로 갈 수 있는가?)
	for (int row = 0; row < size; row++)
		for (int col = 0; col < size; col++) 
			cin >> MAP[row][col];

	/*
	row, col <- 계산해서 인접한 점
	row라는 row, col
	*/
	
	// 2. Queue를 생성
	queue<Node> q;
	int used[10][10] = { 0, };

	// 3. 시작점 세팅
	q.push({ 0, 0 });

	while (!q.empty()) {
		// 4. now 꺼내기
		Node now = q.front();
		q.pop();

		// 5. *** now -> next 찾기 (상하좌우) --> 방향배열
		int dr[] = { 0, 0, 1, -1 };
		int dc[] = { 1, -1, 0, 0 };
		for (int i = 0; i < 4; i++) {
			// next position 계산하기
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];
			// MAP을 벗어나는 좌표가 계산되면 무시
			if (0 > nextRow || nextRow >= size || 0 > nextCol || nextCol >= size)
				continue;
			// 이미 방문한 적이 있으면 무시
			if (used[nextRow][nextCol] == 1) 
				continue;
			// 벽이면 무시
			if (MAP[nextRow][nextCol] == 1)
				continue;

			// 6. next를 queue에 추가
			used[nextRow][nextCol] = 1 + used[now.row][now.col]; 
			// 기록할 때 현재의 row, col의 위치하는 값에 + 1씩 더하게 되면 
			// 몇 개의 level을 거쳐야 하는지 파악된다.
			q.push({ nextRow, nextCol });
		}
	}

	return 0;
}
