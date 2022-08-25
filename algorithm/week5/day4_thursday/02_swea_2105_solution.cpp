//#include <iostream>
//#include<vector>
//using namespace std;
//
//struct Coord {
//    int row, col;
//};
//
//int N;
//int MAP[30][30];
//void input()
//{
//    cin >> N;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            cin >> MAP[i][j];
//}
//
//int visited[30][30]; // ��ȴ°�? -> '�� ��°�� ��ȴ°�?'
//int DAT[101] = { 0, }; // // ����Ʈ ��ȣ -> �ش� ����Ʈ�� ã�� ���ִ°�?
//int ans = -1;
//void dfs(Coord now, int cnt, Coord st) // ���� ��ǥ, ���� ����
//{
//    if (now.row == st.row && now.col == st.col && visited[now.row][now.col]) // �簢���� ���������� ����
//    {
//        ans = max(ans, visited[now.row][now.col]);
//        return;
//    }
//    //  ����, ����, �»�, ��� ������ ����
//    int dr[] = { 1, 1,-1,-1 };
//    int dc[] = { 1,-1,-1, 1 };
//    for (int i = 0; i < 2; i++)
//        // i : 0�϶��� ������� �״��
//        // i : 1�϶��� ������������ �ٲ㼭
//    {
//        int nr = now.row + dr[cnt + i];
//        int nc = now.col + dc[cnt + i];
//        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
//        if (cnt + i >= 4) continue; // ������ȯ�� 4���ϸ� ����
//        if (DAT[MAP[nr][nc]] != 0) continue; // �̹� ����� ����Ʈ
//        if (visited[nr][nc] == 0)
//        {
//            DAT[MAP[nr][nc]] = 1;
//            visited[nr][nc] = visited[now.row][now.col] + 1;
//            // ��ȴ� ���̶�� ��� -> next�� now���� 1�� �� ���� �鸰��.
//            dfs({ nr, nc }, cnt + i, st);
//            visited[nr][nc] = 0; // �پ��� ��� ����
//            DAT[MAP[nr][nc]] = 0;
//        }
//    }
//}
//
//int solution()
//{
//    ans = -1;
//    for (int row = 0; row < N; row++)
//        for (int col = 0; col < N; col++)
//        {
//            Coord st = { row, col };
//            dfs(st, 0, st);
//        }
//    return ans;
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//    for (int tc = 1; tc <= T; tc++)
//    {
//        input();
//        cout << "#" << tc << " " << solution() << "\n";
//        int de = 1;
//    }
//    return 0;
//}