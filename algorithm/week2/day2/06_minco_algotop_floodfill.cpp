//#include <iostream>
//#include <queue>
//using namespace std;
//
//// 플러드필
//// 2차원 배열에서의 BFS
//// --> 만약 코테에서 BFS 문제가 나온다 --> 100% 플러드필
//// --> 코테에 나오면 땡큐
//// 기본적인 작성 틀이 바뀌는 경우는 거의 XX
//// --> 1. 설계,  2. 정답 조건
//// visited를 채워서 -> 시작노드 -> 끝 노드까지의 "최단 경로"를 찾는 문제.
//
//// 예제 코드
//// 5x5 배열 (MAP) 이 있고,
//// 특정 좌표를 정했을 때 -> 입력된 다른 좌표까지의 최단경로는 몇?
//
//int sy, sx; // 시작 좌표
//int ey, ex; // 도착 좌표
//
//// 하이퍼튜브처럼 특정 노드에 도달할 때까지 
//// 몇개의 노드를 거쳐왔는가를 기록.
//int visited[5][5];
//
//// 갈 수 있는가? + 플러드 필? --> 방향배열
//
//int ydir[] = { 0, 0, -1, 1 };
//int xdir[] = { -1, 1, 0, 0 };
//
//
//struct Node {
//	int y, x;
//};
//
//void bfs(int y, int x) {
//	queue<Node> q;
//	q.push({ y, x });
//
//	// visited 세팅
//	// 시작노드 1로 설정.
//	visited[y][x] = 1;
//
//	// floodfill
//	while (!q.empty()) {
//		// 지금 갈 수 있는 노드를 빼왔음
//		Node now = q.front();
//		q.pop();
//
//		// 인접한 노드로 갈 수 있는가?
//		// ** 방향 배열 체킹 **
//		for (int i = 0; i < 4; i++) {
//			// 다음 노드의 y, x (row, col) 확인
//			int ny = now.y + ydir[i];
//			int nx = now.x + xdir[i];
//			// 방향 배열 사용 시, 필수적으로 범위 검사
//			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
//				continue;
//			// 방문 기록 체크
//			if (visited[ny][nx] > 0) 
//				continue;
//			//// 추가 가지 치기 (옵션)
//
//			// 다음 좌표 넘어가기 전에 기록하자.
//			visited[ny][nx] = visited[y][x] + 1;
//			// 다음 노드 줄 세워야 함.
//			q.push({ ny, nx });
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	cin >> sy >> sx;
//
//	// 플러드 필로 일단 맵을 채운다.
//
//	bfs(sy, sx);
//
//	// 방문 기록 출력
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			cout << visited[i][j] << " ";
//		}
//		cout << '\n';
//	}
//
//	cin >> ey >> ex;
//	// (sy, sx)부터 (ey, ex)좌표까지의 최단 거리
//	cout << visited[ey][ex];
//
//	return 0;
//}