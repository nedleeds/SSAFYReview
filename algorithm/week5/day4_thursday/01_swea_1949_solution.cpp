//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct coord { int row, col; };
//
//int n, k;
//int map[10][10];
//int visited[10][10];
//vector<coord> pos;
//
//void input()
//{
//	cin >> n >> k;
//	int maxheight = -1;
//	for (int row = 0; row < n; row++)
//		for (int col = 0; col < n; col++)
//		{
//			cin >> map[row][col];
//			if (map[row][col] > maxheight)
//				pos.clear();
//			if (map[row][col] >= maxheight)
//			{
//				pos.push_back({ row, col });
//				maxheight = map[row][col];
//			}
//		}
//}
//
//int dfs(coord now, int flag, int height) {
//	int ret = 1;
//	int dr[] = { -1, 1, 0, 0 };
//	int dc[] = { 0, 0, -1, 1 };
//	for (int i = 0; i < 4; i++)
//	{
//		int nr = now.row + dr[i];
//		int nc = now.col + dc[i];
//		if (nr < 0 || nc < 0 || nc >= n || nr >= n)
//			continue;
//		if (visited[nr][nc] != 0) continue;
//
//		visited[nr][nc] = 1;
//
//		if (height > map[nr][nc])
//		{
//			ret = max(ret,
//				dfs({ nr, nc }, flag, map[nr][nc]) + 1// next�� ���� �ִ� �󸶳� �� �� �ִ°�?
//			);
//		}
//		else if (flag == 0 && height > map[nr][nc] - k) // <- �����Ŀ� �� �� �ִ°�?
//		{
//			ret = max(ret,
//				dfs({ nr, nc }, 1, height - 1) + 1 // next�� ���� �ִ� �󸶳� �� �� �ִ°�?
//			);
//		}// ������ǥ�� ���̰� ������ǥ�� ���� �̻��� ��� <- ����
//
//		visited[nr][nc] = 0; // ��¥ ���� ��ο� �����ϰ� ����
//	}
//	return ret;
//}
//
//int solution()
//{
//	int ret = 0;
//	for (int i = 0; i < pos.size(); i++)
//	{
//		coord st = pos[i]; // ������ ������
//		visited[st.row][st.col] = 1;
//		ret = max(ret, dfs(st, 0, map[st.row][st.col]));
//		visited[st.row][st.col] = 0;
//	}
//	return ret;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	for (int tc = 1; tc <= t; tc++)
//	{
//		input();
//		cout << "#" << tc << " " << solution() << "\n";
//		int de = 1;
//	}
//	return 0;
//}