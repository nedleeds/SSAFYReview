#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int height, width;
int MAP[1001][1001];
// index : (row,col)좌표, value : 해당 좌표를 밟을때 얻을 점수
int dp[1001][1001];
// index : (row,col)좌표 <- 어떤 점인지 구별할 정보
// value : 해당 점에서부터 앞으로 구할 최고 점수(답)

int dfs(int row, int col)
// now : 지금 내가 있는 점 (row, col)좌표에 있다.
// upgrade - dfs(now) : now에서부터 끝까지 갔을 때 얻을 수 있는 최고 점수 반환
{
    if (row >= height - 1) // 맨 아래까지 내려왔으면
    {
        return MAP[row][col]; // 더 내려갈 곳이 없으니 끝내라
        // 맨 밑의 층은 해당 좌표에 서있는 점수가 얻을 수 있는 최고점
    }
    if (dp[row][col] != -2134567890) // 전에 어떠한 계산을 했던 기록이 있으면
        return dp[row][col]; // 그 계산한 결과를 바로 가져가라!

    // now -> next를 찾아서 가라!
    int dr[] = { 1, 1, 1 };
    int dc[] = { -1, 0, 1 };
    int scoreNextMax = -2134567890; // 앞으로 얻을 수 있는 최고 점수
    for (int i = 0; i < 3; i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nc < 0 || nr >= height || nc >= width)
            continue; // 맵을 벗어나는 좌표가 계산되면 무시
        if (MAP[nr][nc] == 0)
            continue; // next위치는 벽이다.라면 무시

        int scoreNext = dfs(nr, nc); // next로 가라! -> dfs(next) : next에서는 몇점이 최고인가?
        // scoreNext : next방향으로 갈 때 next부터 얻을 수 있는 최고 점수
        if (scoreNextMax < scoreNext)
            scoreNextMax = scoreNext;
    }
    int scoreNow = scoreNextMax + MAP[row][col];
    // scoreNow : now에서부터 끝까지 갔을 때의 최고 점수

    dp[row][col] = scoreNow; // dp배열에 계산한 결과를 저장

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
            dp[i][j] = -2134567890; // 초기화값 : 계산상 나올 수 없는 값
        }
    }
    cout << dfs(0, 0);
}