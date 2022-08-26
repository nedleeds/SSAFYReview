//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct Pos { int row, col; } black, white;
//int flag = 0; // ������ �ٸ� �� ã���� 1�� �ٲ�
//int MAP[10][10];
//int visited[10][10];
//int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
//int dc[8] = { -1,  0,  1, 1, 1, 0, -1, -1 };
//queue<Pos> betweens; // ���̿� �����ϴ� ��
//
//int doChange() {
//	// ���� ���� �� ���� �� ���̿� �����ϴ� ������ ���� ��ȯ
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
//		// 1) ���� ��, ���� �� �ٸ��� 
//		//  ���	a)	���� between�� ���� ���� ����
//		//			: between�� �����ϰ� ���� �� ���ö� ���� Ȯ��
//		//		b)	���� between�� ���� �ִ� ����
//		//			b: ���ݱ��� ������ between�� ���� �ٲ۴�
//		//	
//		// 2) ���� ��, ���� ���� ����
//		//	���	a)	���� between�� ���� �ִ� ����
//		//			: �� ���� ���� ���� ������ queue�� �־�����Ѵ�
//		//	���	b)	���� between�� ���� ���� ����
//		//			: �ٸ� ���� Ž�� ����
//
//		// �湮�߾��� ���� ���� �������̸� pass
//		if (visited[nr][nc] != 0 && MAP[nr][nc] == MAP[now.row][now.col])
//			continue;
//
//		// 1) ����-���� ���� �ٸ���
//		if (MAP[nr][nc] != MAP[now.row][now.col]) {	
//			// a) between �� �����
//			if (betweens.empty()) {
//				betweens.push(next);
//			}
//			else {
//			// b) between �� ���� �ִ� -> �� �ٲٰ� ����
//				flag = doChange();
//			}
//		}
//		// ����-���� ���� ����
//		else {
//			// a) between�� ���� �ִ�
//			if (!betweens.empty()) {
//				betweens.push(next);
//			}
//			// b) between�� ���� ����
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
//			MAP[black.row][black.col] = -1; // �浹�� ���Ҵ�
//			visited[black.row][black.col] = -1;
//			stone = black;
//		}
//		else {
//			cin >> white.row >> white.col;
//			MAP[white.row][white.col] = 1;// �鵹�� ���Ҵ�
//			visited[white.row][white.col] = 1;
//			stone = white;
//		}
//		if (i > 2) { // ����° ���� ���� ������ Ž�� ����
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