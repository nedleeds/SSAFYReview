//#include <iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//struct Coord {
//    int row, col;
//    int deactivate; // <- ��Ȱ��ȭ ���� ���� �ð�
//    int activate; // <- Ȱ��ȭ ���� ���� �ð�
//};
//
//int N, M, K;
//int MAP[1000][1000]; // ���� 650�̻� <- ����� ��ġ�� ��� + ������ �����°�?
//
//bool operator<(Coord A, Coord B) {
//    if (MAP[A.row][A.col] < MAP[B.row][B.col]) return true; // B���� ���� ����
//    if (MAP[A.row][A.col] > MAP[B.row][B.col]) return false; // A���� ���� ����
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
//priority_queue<Coord> bfs(priority_queue<Coord> nowQ) // <- 1�̶�� �ð����� �۵�
//{
//    // 1. �׷��� ����
//    // 2. queue���� <- �Ű������� �޾���
//    priority_queue<Coord> nextQ; // <- �����ð��� ������ ����
//    // 3. ������ ���� <- �Ű������� queue�� ���� ����
//
//    // �̹� �ð��� ����� ������ ��� ����������
//    while (!nowQ.empty()) {
//        // 4. now������ <- �̹� �ð��� ���ŵ� ����
//        Coord now = nowQ.top(); nowQ.pop();
//        now.deactivate--; // ��Ȱ��ȭ ���� �ð��� ����
//        if (now.deactivate < 0) // �� �̻� ���� ��Ȱ��ȭ �ð��� ���ٸ� ? => Ȱ��ȭ
//        {
//            if (now.activate == 0) // ù Ȱ��ȭ
//            {
//                // 5. nextã��
//                int dr[] = { -1,1,0,0 };
//                int dc[] = { 0,0,-1,1 };
//                for (int i = 0; i < 4; i++)
//                {
//                    int nr = now.row + dr[i];
//                    int nc = now.col + dc[i];
//                    if (MAP[nr][nc] != 0) continue; // �̹� ������ �־����� ����
//                    MAP[nr][nc] = MAP[now.row][now.col];
//                    // next�� ã��
//                    // 6. next�� queue�� �߰� <- next�� ���� �ð��� �ƴ϶� �����ð��� ����
//                    nextQ.push({ nr, nc, MAP[nr][nc], 0 }); // next�� ���� �ð��� ����
//                }
//            }
//            now.activate++; // Ȱ��ȭ�� �����Ƿ� Ȱ��ȭ �ð��� ����
//        }
//        // ����ִ��� ���� : activate�� ����� ��ġ�̻��� �Ǹ� ������ ���� ������ Ȯ��
//        if (now.activate < MAP[now.row][now.col]) // Ȱ��ȭ �Ӹ� �ƴ� ��Ȱ��ȭ ���¿�����
//            nextQ.push(now); // ���� Ȱ��ȭ �ð��� ����� ��ġ��ŭ �������� ����(�������), �����ð����� Ȯ��
//    }
//    return nextQ; // �����ð��� ������ ���� ���� ��Ȳ�� �״�� ��
//}
//
//int solution()
//{
//    priority_queue<Coord> nowQ;
//    //���� ã��
//    for (int i = 500; i < 500 + N; i++)
//        for (int j = 500; j < 500 + M; j++)
//            if (MAP[i][j])
//            {
//                // �������� ������ �س����� <- BFS���
//                nowQ.push({ i, j, MAP[i][j], 0 }); // i,j��ǥ�� ���� ���, ��Ȱ��ȭ ���� �ð�, Ȱ��ȭ�� �ȵ�
//            }
//
//    // �ð� ����
//    for (int i = 0; i < K; i++)
//        nowQ = bfs(nowQ);
//
//    // nowQ : K�ð��� ����ִ� ��� ����
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
//        init();// �ʱ�ȭ <- ����� ���� ��Ծ ������ ��
//        input(); // �Է�
//        cout << "#" << tc << " " << solution() << "\n"; // ���
//    }
//    return 0;
//}