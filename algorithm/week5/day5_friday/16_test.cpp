#include <iostream>

#include <queue>

#include <unordered_map>
using namespace std;

int N;
int cnt;
char MAP[1000][1000];
int visited[1000][1000];
int visited2[1000][1000];
struct Pos { int row, col; };
queue<Pos> members;
queue<int> maxIndices;
unordered_map<int, Pos> startNode;
unordered_map<int, queue<int>> maxNodes;

void dfs1(Pos now, int groupIdx) {
    cnt++;
    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };

    startNode[groupIdx] = { now.row, now.col };
    for (int i = 0; i < 4; i++) {
        Pos next = { now.row + dr[i], now.col + dc[i] };
        int nr = next.row;
        int nc = next.col;

        if (nr < 0 || nc < 0 || nr >= 1000 || nc >= 1000)
            continue;
        if (MAP[nr][nc] != '#')
            continue;
        if (visited[nr][nc] != 0)
            continue;

        visited[nr][nc] = groupIdx;
        dfs1({ nr, nc }, groupIdx);
    }
}

int dotCheck(Pos now) {
    // 4방향 . 체크 -> 둘레로 생각
    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int nextRow = now.row + dr[i];
        int nextCol = now.col + dc[i];

        if (visited[nextRow][nextCol] != 0)  count++;
    }
    return 4 - count;
}

int radius;
void dfs2(Pos now, int groupIdx) {

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (visited[r][c] == groupIdx) {
                radius += dotCheck({ r,c });
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }

    int groupIdx = 1;
    int maxGroupIdx = -2134567890;
    int maxAmount = -213456890;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (MAP[r][c] == '#' && visited[r][c] == 0) {
                cnt = -1;
                dfs1({ r, c }, groupIdx);
                if (cnt > maxAmount) {
                    maxAmount = cnt;
                    maxGroupIdx = groupIdx;
                }
                groupIdx += 1;
            }

    
    dfs2(startNode[maxGroupIdx], maxGroupIdx);

    cout << maxAmount << ' ' << radius;

    return 0;
}

