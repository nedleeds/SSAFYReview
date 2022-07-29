#include <iostream>
using namespace std;

// ���Ÿ� ����

// ������� 
int mat[10][10];
// n
int n;
// ���۰� �� 
int st, en;
// �湮��� �迭 
int visited[10];
// �� ����� ���� ��� ������ ���� 
int sum = 0;
// �ּҺ�� ����� ����
int mincost = 2134567890;
// �ִ��� ����� ���� 
int maxcost = -2134567890;

void dfs(int node) {

    // ���� ���� (�ɼ�) 
    // ���� ���� ���� �������� �����ߴٸ�
    // �� �����ʿ� ���� ���ư��� �ٸ� ��θ� ã�ƺ���!
    if (node == en) {
        // en���� ������ -> �ּ� ���� �ִ� ����� ���� ����
        // ������� ���� ���� �����Ŀ� ����� ���� ����� 
        // ������� ��ϵ� �ִ��뺸�� ũ��
        if (sum > maxcost)
            // �ִ밪�� ����
            maxcost = sum;
        // ������� ��ϵ� �ּ� ��뺸�� ������
        if (sum < mincost)
            // �ּҰ� ����
            mincost = sum;
        return;
    }

    // dfs ����
    for (int i = 0; i < n; i++) {
        // ����ġ�� 

        // 1. �� �� �ִ°�?
        if (mat[node][i] == 0)
            continue;

        // 2. �湮�� ������ �ִ°�? 
        if (visited[i] == 1)
            continue;

        // ���� �湮 ���
        visited[i] = 1;

        // ���� : ���� ���� ���� ��� ����
        sum += mat[node][i];

        // ���� ���� ������!
        dfs(i);

        // ���� -> ��� ��� �鷯���� (Backtracking)
        visited[i] = 0;

        // ���ö� : ���� ���� ���� ��� ����
        sum -= mat[node][i];

    }
}

int main() {
    // input
    cin >> n;
    // ������� �Է� 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    // ���۰� �� �Է�
    cin >> st >> en;

    // solve 
    // DFS + backtracking 
    // ����Ž�� -st node���� ����
    // ���� ��� �湮��� 
    visited[st] = 1;
    dfs(st);
    cout << mincost << '\n' << maxcost;
}