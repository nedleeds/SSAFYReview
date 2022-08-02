#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
// �������
1. ���� ���� �� ���� �Ǵ°�? (ã�Ҵ� ���� �� ã�� �Ǵ°�????) <- usedDFS�� �ذ�
2. 2���� ��(���� ����) : ���� ����� ��ǥ�� ���Ǵ°�?
*/

/*
Flood Fill
2���� �ʿ��� Ž���ϸ� �������� ����Ͽ� ä�������� ���
�����¿�� �̵��� �����ϴ�.

ù �ٿ� ���� ũ��(N)
�̾��� N���� �ٿ� ���� N���� ���ڵ��� �־�����, �ʿ� ���� ������ �־���
5
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
*/

/*
������
���� Ž���̴�(��� ���� Ȯ���� �� �ִ�.)
- > ��� ���� 1������ �鸮�� �� : �ƹ��ų� ����ص� OK

������
DFS : ��� ª�� �ϴ� ��� ��θ� �� ������ �ϴ� ��Ȳ
BFS : ���� ���� node�� ������� ����� ���ؾ� �ϴ� ��Ȳ
*/


struct Node {
    int row;
    int col;
};


// �پ��� ��θ� ��� �غ��� �˰��� : DFS

int MAPsize;
int MAP[10][10] = { 0, };

int usedDFS[10][10] = { 0, }; // ã�� �� �ִ°�?

void dfs(int nowRow, int nowCol) // now�� �ִ�. // Node now
{
    if (nowRow == MAPsize - 1 && nowCol == MAPsize - 1)
        return; // ���� ����
    //now���� �� �� �ִ� next�� ����!
    // �����¿� 4���� �������� ���
    int dr[] = { 0,0,-1,1 }; // <----- break point, F5�� �������� Ȯ��
    int dc[] = { -1,1,0,0 };
    for (int i = 0; i < 4; i++) {
        int nextRow = nowRow + dr[i];
        int nextCol = nowCol + dc[i];
        if (nextRow < 0 || nextCol < 0 || nextRow >= MAPsize || nextCol >= MAPsize)
            continue; // ���� ����� ��ǥ�� ����
        if (usedDFS[nextRow][nextCol] != 0)
            continue; // next��� ��ǥ�� ã�Ҵ� ��ǥ��. ����
        if (MAP[nextRow][nextCol] == 1)
            continue; // next�� ���̸� ����

        usedDFS[nextRow][nextCol] = 1; // next��� ��ǥ�� ã�Ҵ�. ���
        dfs(nextRow, nextCol);

        usedDFS[nextRow][nextCol] = 0; // <- ��� ����(�پ��� ���) : BFS�� ��¥ �����Ǵ� ����

    }
}

void bfs()
{
    // 2. Queue�� ����
    queue<Node> q; // q�� ���� ���� : node����(� node�ΰ�? ������ ���ѳ��� node��ȣ)
                   //                 row, col -> 2���� ���� -> node 1��
    int usedBFS[10][10] = { 0, };
    // usedBFS[row][col] = row,col�� ã�� �� �ִ°�?
    //        upgrade : row,col�� �� ���� ���� ����� �� �� �մ°�?

    // 3. ������ ����
    usedBFS[0][0] = 1; // 0,0�� ã�Ҵ�. ���
    q.push({ 0, 0 }); // row = 0, col = 0���� ����

    // 7. 4 ~ 6 �ܰ� �ݺ�
    while (!q.empty()) {
        // 4. now������
        Node now = q.front(); // <----- break point, F5�� �������� Ȯ��
        q.pop();
        // 5. **** now->nextã�� (�����¿�) -> ����迭
        int dr[] = { 0,0,1,-1 };
        int dc[] = { 1,-1,0,0 };
        for (int i = 0; i < 4; i++)
        {
            int nextRow = now.row + dr[i];
            int nextCol = now.col + dc[i];

            // ------------ �����ص� �Ǵ°�?
            // nextRow, nextCol : now ���� �� �� �ִ� ���� ��(next)
            if (nextRow < 0 || nextCol < 0 || nextCol >= MAPsize || nextRow >= MAPsize)
                continue; // ���� ����� ��ǥ�� ���Ǹ� ����
            if (usedBFS[nextRow][nextCol] != 0) continue; // � ����� �ִ� ��ǥ����(ã�Ҵ� ��ǥ����) ����
            if (MAP[nextRow][nextCol] == 1)continue; // ���̸� ����
            // ------------ 

            // 6. next�� queue�� �߰�
            usedBFS[nextRow][nextCol] = usedBFS[now.row][now.col] + 1; // nextRow, nextCol�� ã�Ҵ�. ���
            q.push({ nextRow, nextCol });
        }
    }
}

int main()
{
    cin >> MAPsize;
    for (int row = 0; row < MAPsize; row++)
        for (int col = 0; col < MAPsize; col++)
            cin >> MAP[row][col];
    usedDFS[0][0] = 1;
    dfs(0, 0);
    bfs();
    return 0;
}