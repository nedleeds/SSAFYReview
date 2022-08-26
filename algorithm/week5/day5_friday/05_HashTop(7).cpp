//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct Pos { int row, col; } black, white;
//int flag = 0; // 마지막 다른 돌 찾으면 1로 바뀜
//int MAP[10][10];
//int visited[10][10];
//int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
//int dc[8] = { -1,  0,  1, 1, 1, 0, -1, -1 };
//queue<Pos> betweens; // 사이에 존재하는 돌
//
//int doChange() {
//	// 시작 돌과 그 다음 돌 사이에 존재하는 돌들의 색을 전환
//	while (!betweens.empty()) {
//		Pos toBeChanged = betweens.front();
//		betweens.pop();
//		if (MAP[toBeChanged.row][toBeChanged.col] == 1)
//			MAP[toBeChanged.row][toBeChanged.col] = 0;
//		else
//			MAP[toBeChanged.row][toBeChanged.col] = 1;
//	}
//	return 1;
//}
//
//void dfs(Pos now) {
//	if (flag == 1)
//		return;
//
//	for (int i = 0; i < 8; i++) {
//		Pos next = { now.row + dr[i], now.col + dc[i] };
//		int nr = next.row;
//		int nc = next.col;
//
//		// 1) 다음 돌, 현재 돌 다르다 
//		//  경우	a)	지금 between에 돌이 없는 상태
//		//			: between에 저장하고 같은 돌 나올때 까지 확인
//		//		b)	지금 between에 돌이 있는 상태
//		//			b: 지금까지 저장한 between의 색을 바꾼다
//		//	
//		// 2) 다음 돌, 현재 돌이 같다
//		//	경우	a)	지금 between에 돌이 있는 상태
//		//			: 이 다음 돌의 색도 같으면 queue에 넣어줘야한다
//		//	경우	b)	지금 between에 돌이 없는 상태
//		//			: 다른 방향 탐색 시작
//
//		// 방문했었고 현재 돌과 같은색이면 pass
//		if (visited[nr][nc] != 0 && MAP[nr][nc] == MAP[now.row][now.col])
//			continue;
//
//		// 1) 다음-현재 돌이 다르다
//		if (MAP[nr][nc] != MAP[now.row][now.col]) {	
//			// a) between 이 비었다
//			if (betweens.empty()) {
//				betweens.push(next);
//			}
//			else {
//			// b) between 에 돌이 있다 -> 색 바꾸고 종료
//				flag = doChange();
//			}
//		}
//		// 다음-현재 돌이 같다
//		else {
//			// a) between에 돌이 있다
//			if (!betweens.empty()) {
//				betweens.push(next);
//			}
//			// b) between에 돌이 없다
//			else {
//				continue;
//			}
//		}
//
//		dfs(next);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		Pos stone = { 0, 0 };
//		if (i % 2 == 0) {
//			cin >> black.row >> black.col;
//			MAP[black.row][black.col] = -1; // 흑돌을 놓았다
//			visited[black.row][black.col] = -1;
//			stone = black;
//		}
//		else {
//			cin >> white.row >> white.col;
//			MAP[white.row][white.col] = 1;// 백돌을 놓았다
//			visited[white.row][white.col] = 1;
//			stone = white;
//		}
//		if (i > 2) { // 세번째 돌을 놓은 경우부터 탐색 시작
//			Pos start = stone;
//			flag = 0;
//			dfs(stone);
//		}
//	}
//
//	int de = 1;
//
//	return 0;
//}