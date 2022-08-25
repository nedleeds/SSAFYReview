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
//int visited[30][30]; // 들렸는가? -> '몇 번째로 들렸는가?'
//int DAT[101] = { 0, }; // // 디저트 번호 -> 해당 디저트를 찾은 적있는가?
//int ans = -1;
//void dfs(Coord now, int cnt, Coord st) // 현재 좌표, 진행 방향
//{
//    if (now.row == st.row && now.col == st.col && visited[now.row][now.col]) // 사각형을 정상적으로 만듦
//    {
//        ans = max(ans, visited[now.row][now.col]);
//        return;
//    }
//    //  우하, 좌하, 좌상, 우상 순서로 진행
//    int dr[] = { 1, 1,-1,-1 };
//    int dc[] = { 1,-1,-1, 1 };
//    for (int i = 0; i < 2; i++)
//        // i : 0일때는 진행방향 그대로
//        // i : 1일때는 다음방향으로 바꿔서
//    {
//        int nr = now.row + dr[cnt + i];
//        int nc = now.col + dc[cnt + i];
//        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
//        if (cnt + i >= 4) continue; // 방향전환을 4번하면 무시
//        if (DAT[MAP[nr][nc]] != 0) continue; // 이미 골랐던 디저트
//        if (visited[nr][nc] == 0)
//        {
//            DAT[MAP[nr][nc]] = 1;
//            visited[nr][nc] = visited[now.row][now.col] + 1;
//            // 들렸던 점이라고 기록 -> next는 now보다 1번 더 가서 들린다.
//            dfs({ nr, nc }, cnt + i, st);
//            visited[nr][nc] = 0; // 다양한 방법 적용
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