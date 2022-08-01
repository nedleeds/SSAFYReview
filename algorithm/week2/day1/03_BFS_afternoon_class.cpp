#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 인접 행렬 BFS

// nodeNum : 노드의 개수
// edgeNum : 간선의 개수
/*
9 8
1 2
1 7
2 3
3 4
3 8
4 5
4 6
8 9
*/

int numNode, numEdge;
int mat[10][10];

void bfs(int node) {
	// 2가지의 세팅
	// ** 상황에 따라서 전역으로 선언할 필요가 있다.
	// ** FloodFill (ex-시작 node가 2군데 일 때.)
	
	// 1. queue 세팅
	queue<int> q;
	q.push(node); // 시작 노드 넣은채로 시작.
	
	// 2. (그래프 한정) --> visited 세팅 필요
	int visited[10] = { 0, }; //**함수 내에서 만들면 {0,} 초기화 필요.
	// 시작 노드 방문 기록
	visited[node] = 1; // **그래프 한정**

	//bfs의 logic
	// 더 이상 가볼 수 있는 노드의 후보지가 없을 때까지 반복
	// --> queue에 더 이상 가볼 수 있는 노드가 없다 !!
	while (!q.empty()) {
		// 현재 node를 추출!
		int now = q.front();
		q.pop();

		cout << now << ' ';

		// 지금 (now)노드로부터 갈 수 있는 후보지들을 확인하고 q에 넣어!
		for (int i = 1; i <= numNode; i++) {
			int next = i;
			// 다음 후보지를 갈 수 있는지 체크
			// DFS랑 동일
			
			// 1. (인접행렬) 갈 수 있는지 (경로가 있는지)
			if (mat[now][next] == 0)
				continue;

			// 2. 방문한 적이 있는가?
			if (visited[next] == 1)
				continue;

			// next를 찾았다!
			// 1. 방문 체크
			visited[next] = 1;
			// 2. q에 넣어 
			q.push(next);

		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> numNode >> numEdge;

	//간선의 개수 만큼 입력
	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		mat[from][to] = 1;
		mat[to][from] = 1; // 무방향
	}
	
	// bfs 탐색 시작
	bfs(1);

	return 0;
}