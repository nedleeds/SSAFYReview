//#include <iostream>
//#include<vector>
//using namespace std;
//struct Coord {
//    int row, col;
//};
//int N, W, H; // 입력에서 초기화
//int MAP[20][20]; // 입력에서 초기화
//int copyMAP[20][20]; // makeCopy에서 초기화
//vector<int> path; // dfs에서 사용하며 다시 원복
//int ans = 2134567890; // <- 따로 초기화
//
//void init() {
//    ans = 2134567890;
//}
//
//void input()
//{
//    cin >> N >> W >> H;
//    for (int row = 0; row < H; row++)
//        for (int col = 0; col < W; col++)
//            cin >> MAP[row][col];
//}
//
//void makeCopy() // 원본 map -> copy본에게 복사
//{
//    for (int i = 0; i < 20; i++)
//        for (int j = 0; j < 20; j++)
//            copyMAP[i][j] = MAP[i][j];
//}
//
//void boom(Coord now) // now : 이번에 터질 좌표
//{
//    int boomRange = copyMAP[now.row][now.col];
//    copyMAP[now.row][now.col] = 0; // 터져서 없어짐
//
//              // 상,하,좌,우
//    int dr[] = { -1,1, 0,0 }; // 방향
//    int dc[] = { 0,0,-1,1 }; // 방향
//    for (int i = 0; i < 4; i++)
//    {
//        for (int dist = 1; dist < boomRange; dist++)
//        {
//            int nr = now.row + dr[i] * dist;
//            int nc = now.col + dc[i] * dist;
//            if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
//            if (copyMAP[nr][nc] == 0) continue;
//            boom({ nr, nc });
//        }
//    }
//}// boom 1개
//
//void Gravity()
//{
//    for (int col = 0; col < W; col++)
//    {
//        int lastZero = H - 1;
//        for (int row = H - 1; row >= 0; row--)
//        {
//            if (copyMAP[row][col] != 0)
//            {
//                int temp = copyMAP[row][col];
//                copyMAP[row][col] = copyMAP[lastZero][col];
//                copyMAP[lastZero][col] = temp;
//                lastZero--;
//            }
//        }
//    }
//}
//
//void simul() {
//    // path를 이용하여 각 turn마다 구슬을 떨어뜨림
//    makeCopy();
//    for (int i = 0; i < N; i++) // i : turn
//    {
//        int col = path[i];
//        for (int row = 0; row < H; row++)
//        {
//            if (copyMAP[row][col])
//            {
//                boom({ row, col });
//                break;
//            }
//        }
//        Gravity();
//    }
//}
//
//int remainCnt()
//{
//    int cnt = 0;
//    for (int row = 0; row < H; row++)
//        for (int col = 0; col < W; col++)
//            if (copyMAP[row][col]) cnt++;
//    return cnt;
//}
//void dfs(int now) // now : 뽑은 개수 or turn
//// dfs : 각 turn마다 구슬을 떨어뜨릴 위치 뽑기
//{
//    if (now >= N) // 0~3번까지 정상적으로 뽑고 난 이후
//    {
//        simul();
//        ans = min(ans, remainCnt());
//        return;
//    }
//    for (int i = 0; i < W; i++)
//    {
//        path.push_back(i); // i번을 뽑았다라고 기록
//        dfs(now + 1);
//        path.pop_back(); // 이번에 기록했던걸 삭제, 복구
//    }
//}
//
//int solution()
//{
//    // N개의 구슬을 떨어뜨릴 위치
//    // N개의 주사위, 주사위 눈 : 0~col-1
//    // 나올 수 잇는 경우의 수
//
//    dfs(0);
//    return ans;
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//    for (int tc = 1; tc <= T; tc++)
//    {
//        init();
//        input();
//        cout << "#" << tc << " " << solution() << "\n";
//    }
//    return 0;
//}