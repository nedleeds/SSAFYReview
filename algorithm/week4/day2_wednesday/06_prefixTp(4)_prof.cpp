#include <iostream>
using namespace std;

// 2차원 prefix sum

int arr[1001][1001];
int sumarr[4][4];

int main() {
    // get array
    int N, M;
    cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> arr[r][c];
            sumarr[r][c] = sumarr[r][c - 1] + arr[r][c];
        }
    }


    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            sumarr[i][j] = sumarr[i][j - 1] + sumarr[i - 1][j] - sumarr[i - 1][j - 1] + arr[i][j];
        }
    }

    int eny = 3;
    int enx = 3;
    int sty = 2;
    int stx = 2;
    // 2차원 prefix sum query
    // sumar
    cout << sumarr[eny][enx] - sumarr[eny][stx - 1] - sumarr[sty - 1][enx] + sumarr[sty - 1][stx - 1];
}