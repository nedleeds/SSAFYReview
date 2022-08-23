#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// 인접 행렬로 구현
///*BFS 제작 순서
//1. 그래프 구성(입력을 받는다) - 각 node 간 관계
//2. queue 를 생성
//3. 시작 노드 생성
//4. queue 에서 node(now)를 하나 꺼냄
//   -> 감염 시켜나갈 예정인 node
//5. now에서 갈 수 있는 node(next)들 찾기
//6. next들을 queue에 추가
//7. 4~6 단계 반복
//   -> 언제까지? queue가 비워질 때 까지
//*/
//
//int main() {
//
//	int nodeNum;
//	int adjMtx[10][10] = { 0, };
//
//	// 1. 그래프 구성
//	cin >> nodeNum;
//	for (int i = 0; i < nodeNum; i++) {
//		int from, to;
//		cin >> from >> to;
//		adjMtx[from][to] = 1;
//	}
//
//	// 2. queue 생성
//	queue<int> q;
//	int startNode = 1;
//	q.push(startNode);
//
//	while (!q.empty()) {
//		int now = q.front();
//		q.pop();
//
//		for (int i = 1; i <= 9; i++) {
//			int next = i;
//			if (adjMtx[now][next] == 0)
//				continue;
//			q.push(next);
//		}
//
//	}
//
//
//	return 0;
//}


//// 인접 리스트로 구현
//int main() {
//
//	int nodeNum;
//	vector<int> adjList[10];
//	cin >> nodeNum;
//
//	// 1. get the graph
//	for (int i = 0; i < nodeNum; i++) {
//		int from, to;
//		cin >> from >> to;
//		adjList[from].push_back(to); // 유방향
//		adjList[to].push_back(from); // 무방향
//	}
//
//	queue<int> q;
//	int startNode = 1;
//	q.push(startNode);
//
//	while (!q.empty()) {
//		int now = q.front();
//		q.pop();
//		
//		cout << now << ' ';
//
//		for (int i = 0; i < adjList[now].size(); i++) {
//			int next = adjList[now][i];
//
//			q.push(next);
//		}
//
//	}
//
//}

// FloodFill? 
// -> BFS(인접행렬 or 인접리스트) + 방향배열
// --> 1) 방향배열 체크
// --> 2) 방문한적 있으면 무시
// --> +) 벽이면 무시 
// --> *) visited[next.r][next.c] = 1 + visited[now.r][now.c]
// -----> 기록할 때 현재의 row, col의 위치하는 값에 + 1씩 더하게 되면 
// -----> 몇 개의 level을 거쳐야 하는지 파악된다
// 
// -> DFS(인접행렬 or 인접리스트) + 방향배열