#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rowMax, K;
int arr[101][11];
int visited[101][11];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0,-1, 1 };

struct Pos { int row, col; };
vector<Pos> path;
int checkNum;
void dfs(Pos now) {
    for (int i = 0; i < 4; i++) {
        Pos next = { now.row + dr[i], now.col + dc[i] };
        if (next.row < 0 || next.col < 0 || next.row >= rowMax || next.col >= 10)
            continue;
        if (visited[next.row][next.col] != 0)
            continue;
        if (arr[next.row][next.col] != checkNum)
            continue;
        visited[next.row][next.col] = checkNum;
        dfs(next);
    }
    path.push_back(now);
}

void initVisited() {
    for (int r = 0; r < rowMax; r++)
        for (int c = 0; c < 10; c++)
            visited[r][c] = 0;
}

void doGravity() {
    vector<int> nonZerosEachCol[10];
    for (int c = 0; c < 10; c++) {
        for (int r = rowMax - 1; r >= 0; r--) {
            if (arr[r][c] != 0) {
                nonZerosEachCol[c].push_back(arr[r][c]);
                arr[r][c] = 0;
            }
        }
    }

    for (int c = 0; c < 10; c++) {
        int rowIdx = rowMax - 1;
        for (int i = 0; i < nonZerosEachCol[c].size(); i++) {
            arr[rowIdx][c] = nonZerosEachCol[c][i];
            rowIdx--;
        }
    }

    int de = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> rowMax >> K;
    for (int r = 0; r < rowMax; r++) {
        string s;
        cin >> s;
        for (int i = 0; i < 10; i++) {
            arr[r][i] = (s[i] - '0');
            visited[r][i] = 0;
        }
    }

    // row는 밑에서 시작
    int cntBomb = 1;
    int flag = 1;

    while (flag) {
        cntBomb = 1;
        initVisited();
        for (int row = rowMax - 1; row >= 0; row--) {
            for (int col = 0; col < 10; col++) {
                if (arr[row][col] == 0)
                    continue;
                else{
                    // 들어와서 dfs 
                    checkNum = arr[row][col];
                    if (visited[row][col] != 0)
                        continue;
                    visited[row][col] = checkNum;
                    dfs({ row, col });

                    // 펑!
                    if (path.size() >= K) {
                        for (int i = 0; i < path.size(); i++) {
                            Pos curr = path[i];
                            arr[curr.row][curr.col] = 0;
                        }
                        cntBomb++;
                    }
                    //path 초기화
                    while (!path.empty())
                        path.pop_back();
                }
            }

        }
        doGravity();
        if (cntBomb == 1)
            break;
    }

    for (int r = 0; r < rowMax; r++) {
        for (int c = 0; c < 10; c++)
            cout << arr[r][c];
        cout << '\n';
    }
    return 0;
}