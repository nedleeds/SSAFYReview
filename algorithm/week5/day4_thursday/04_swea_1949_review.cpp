//#include <iostream>
//#include <queue>
//#define ROWMAX 8
//#define COLMAX 8
//using namespace std;
//
//int N, K;
//int MAP[8][8];
//int visited[8][8];
//struct Pos { int row, col; } startNode;
//
//void initialize() {
//	for (int r = 0; r < ROWMAX; r++)
//		for (int c = 0; c < COLMAX; c++)
//			visited[r][c] = 0;
//}
//
//void getInput() {
//	for (int row = 0; row < N; row++)
//		for (int col = 0; col < N; col++)
//			cin >> MAP[row][col];
//}
//
//int longest = -2134567890;
//void dfs(Pos now, int isDig, int nowHeight) {
//	int dr[4] = { -1, 1, 0, 0 };
//	int dc[4] = { 0, 0, -1, 1 };
//	if (longest < visited[now.row][now.col])
//		longest = visited[now.row][now.col];
//
//	for (int i = 0; i < 4; i++) {
//		Pos next = { now.row + dr[i], now.col + dc[i] };
//		int newR = next.row;
//		int newC = next.col;
//		if (newR < 0 || newC < 0 || newR >= N || newC >= N)
//			continue;
//		if (visited[newR][newC] > 0)
//			continue;
//		if (MAP[newR][newC] >= MAP[now.row][now.col])
//			continue;
//
//		visited[newR][newC] = visited[now.row][now.col] + 1;
//		if (MAP[newR][newC] < nowHeight) {
//			dfs(next, 0, MAP[newR][newC]);
//		}
//		else if (MAP[newR][newC] - K < nowHeight && !isDig) {
//			dfs(next, 1, nowHeight - 1);
//		}
//		visited[newR][newC] = 0;
//	}
//}
//
//queue<Pos> getHighest() {
//	// get max height
//	int maxHeight = -2134567890;
//	for (int row = 0; row < N; row++)
//		for (int col = 0; col < N; col++)
//			maxHeight = max(maxHeight, MAP[row][col]);
//
//	queue<Pos> highestQ;
//	for (int row = 0; row < N; row++)
//		for (int col = 0; col < N; col++) {
//			if (MAP[row][col] == maxHeight)
//				highestQ.push({ row, col });
//		}
//	return highestQ;
//}
//
//int solve() {
//	// 행, 열 전체 위치에 대해서 dfs + backtrack
//	// --> NOPE! : 가장 높은 위치 먼저 체크
//	// 그리고 최장 등산로 리턴
//	int longest = -2134567890;
//
//	queue<Pos> highestQ = getHighest();
//	while (!highestQ.empty()) {
//		startNode = highestQ.front();
//		highestQ.pop();
//		int startHeight = MAP[startNode.row][startNode.col];
//		visited[startNode.row][startNode.col] = 1;
//		dfs(startNode, 0, startHeight);
//		visited[startNode.row][startNode.col] = 0;
//	}
//
//	return longest;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int testCase;
//	cin >> testCase;
//
//	for (int tc = 0; tc < testCase; tc++) {
//		cin >> N >> K;
//		initialize();
//		getInput();
//		int longest = solve();
//		cout << longest << '\n';
//	}
//
//	return 0;
//}