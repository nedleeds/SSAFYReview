#include <iostream>
using namespace std;

char MAP[4][5] = {
    {'_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_'}
};

int dir[8][2] = {
    {-1,-1},
    {-1, 0},
    {-1, 1},
    { 0, 1},
    { 1, 1},
    { 1, 0},
    { 1,-1},
    { 0,-1},
};

void explode(int r, int c){
    for (int i = 0; i<8; i++){
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];

        if (0 <= nr && nr <=3 && 0 <= nc && nc <= 4){
            MAP[nr][nc] = '#';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    for (int i=0; i<2; i++){
        int r, c;
        cin >> r >> c;
        explode(r, c);
    }

    for (int r=0; r<4; r++){
        for (int c=0; c<5; c++){
            cout << MAP[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
} 
