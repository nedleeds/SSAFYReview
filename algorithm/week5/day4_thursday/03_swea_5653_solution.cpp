//#include <iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//struct Coord {
//    int row, col;
//    int deactivate; // <- 비활성화 상태 남은 시간
//    int activate; // <- 활성화 상태 유지 시간
//};
//
//int N, M, K;
//int MAP[1000][1000]; // 계산상 650이상 <- 생명력 수치를 기록 + 세포가 퍼졌는가?
//
//bool operator<(Coord A, Coord B) {
//    if (MAP[A.row][A.col] < MAP[B.row][B.col]) return true; // B쪽을 먼저 꺼냄
//    if (MAP[A.row][A.col] > MAP[B.row][B.col]) return false; // A쪽을 먼저 꺼냄
//
//    return false;
//}
//
//void input()
//{
//    cin >> N >> M >> K;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < M; j++)
//            cin >> MAP[i + 500][j + 500];
//}
//
//priority_queue<Coord> bfs(priority_queue<Coord> nowQ) // <- 1이라는 시간에만 작동
//{
//    // 1. 그래프 구조
//    // 2. queue생성 <- 매개변수로 받았음
//    priority_queue<Coord> nextQ; // <- 다음시간에 진행할 세포
//    // 3. 시작점 세팅 <- 매개변수의 queue가 갖고 있음
//
//    // 이번 시간에 고려할 세포를 모두 꺼낼때까지
//    while (!nowQ.empty()) {
//        // 4. now꺼내기 <- 이번 시간에 갱신될 세포
//        Coord now = nowQ.top(); nowQ.pop();
//        now.deactivate--; // 비활성화 남은 시간을 줄임
//        if (now.deactivate < 0) // 더 이상 남은 비활성화 시간이 없다면 ? => 활성화
//        {
//            if (now.activate == 0) // 첫 활성화
//            {
//                // 5. next찾기
//                int dr[] = { -1,1,0,0 };
//                int dc[] = { 0,0,-1,1 };
//                for (int i = 0; i < 4; i++)
//                {
//                    int nr = now.row + dr[i];
//                    int nc = now.col + dc[i];
//                    if (MAP[nr][nc] != 0) continue; // 이미 세포가 있었으면 무시
//                    MAP[nr][nc] = MAP[now.row][now.col];
//                    // next를 찾음
//                    // 6. next를 queue에 추가 <- next는 지금 시간이 아니라 다음시간에 적용
//                    nextQ.push({ nr, nc, MAP[nr][nc], 0 }); // next를 다음 시간에 예약
//                }
//            }
//            now.activate++; // 활성화가 됐으므로 활성화 시간을 증가
//        }
//        // 살아있는지 여부 : activate가 생명력 수치이상이 되면 죽으니 아직 작은지 확인
//        if (now.activate < MAP[now.row][now.col]) // 활성화 뿐만 아닌 비활성화 상태에서도
//            nextQ.push(now); // 아직 활성화 시간이 생명력 수치만큼 충족되지 않음(살아있음), 다음시간에도 확인
//    }
//    return nextQ; // 다음시간에 진행할 세포 예약 현황을 그대로 줌
//}
//
//int solution()
//{
//    priority_queue<Coord> nowQ;
//    //세포 찾기
//    for (int i = 500; i < 500 + N; i++)
//        for (int j = 500; j < 500 + M; j++)
//            if (MAP[i][j])
//            {
//                // 세포들은 번식을 해나갈것 <- BFS모양
//                nowQ.push({ i, j, MAP[i][j], 0 }); // i,j좌표의 세포 등록, 비활성화 남은 시간, 활성화는 안됨
//            }
//
//    // 시간 적용
//    for (int i = 0; i < K; i++)
//        nowQ = bfs(nowQ);
//
//    // nowQ : K시간에 살아있는 모든 세포
//    return nowQ.size();
//}
//
//void init() {
//    for (int i = 0; i < 1000; i++)
//        for (int j = 0; j < 1000; j++)
//            MAP[i][j] = 0;
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//    for (int tc = 1; tc <= T; tc++)
//    {
//        init();// 초기화 <- 상당히 자주 까먹어서 문제가 됨
//        input(); // 입력
//        cout << "#" << tc << " " << solution() << "\n"; // 계산
//    }
//    return 0;
//}