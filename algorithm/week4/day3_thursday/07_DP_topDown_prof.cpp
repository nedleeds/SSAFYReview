#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int height, width;
int MAP[1001][1001];
// index : (row,col)��ǥ, value : �ش� ��ǥ�� ������ ���� ����
int dp[1001][1001];
// index : (row,col)��ǥ <- � ������ ������ ����
// value : �ش� ���������� ������ ���� �ְ� ����(��)

int dfs(int row, int col)
// now : ���� ���� �ִ� �� (row, col)��ǥ�� �ִ�.
// upgrade - dfs(now) : now�������� ������ ���� �� ���� �� �ִ� �ְ� ���� ��ȯ
{
    if (row >= height - 1) // �� �Ʒ����� ����������
    {
        return MAP[row][col]; // �� ������ ���� ������ ������
        // �� ���� ���� �ش� ��ǥ�� ���ִ� ������ ���� �� �ִ� �ְ���
    }
    if (dp[row][col] != -2134567890) // ���� ��� ����� �ߴ� ����� ������
        return dp[row][col]; // �� ����� ����� �ٷ� ��������!

    // now -> next�� ã�Ƽ� ����!
    int dr[] = { 1, 1, 1 };
    int dc[] = { -1, 0, 1 };
    int scoreNextMax = -2134567890; // ������ ���� �� �ִ� �ְ� ����
    for (int i = 0; i < 3; i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nc < 0 || nr >= height || nc >= width)
            continue; // ���� ����� ��ǥ�� ���Ǹ� ����
        if (MAP[nr][nc] == 0)
            continue; // next��ġ�� ���̴�.��� ����

        int scoreNext = dfs(nr, nc); // next�� ����! -> dfs(next) : next������ ������ �ְ��ΰ�?
        // scoreNext : next�������� �� �� next���� ���� �� �ִ� �ְ� ����
        if (scoreNextMax < scoreNext)
            scoreNextMax = scoreNext;
    }
    int scoreNow = scoreNextMax + MAP[row][col];
    // scoreNow : now�������� ������ ���� ���� �ְ� ����

    dp[row][col] = scoreNow; // dp�迭�� ����� ����� ����

    return scoreNow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> height >> width;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> MAP[i][j];
            dp[i][j] = -2134567890; // �ʱ�ȭ�� : ���� ���� �� ���� ��
        }
    }
    cout << dfs(0, 0);
}