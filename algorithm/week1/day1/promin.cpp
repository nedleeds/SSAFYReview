#include <iostream>
using namespace std;

int MAP[5][5] = {
    {3, 3, 5, 3, 1},
    {2, 2, 4, 2, 6},
    {4, 9, 2, 3, 4},
    {1, 1, 1, 1, 1},
    {3, 3, 5, 9, 2}
};

int dir[4][2] = {
    {-1,-1},
    {-1, 1},
    { 1,-1},
    { 1, 1}
};

int sum(int r, int c){
    int s = 0;
    for (int i = 0; i<4; i++){
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];

        if (0 <= nr && nr <=4 && 0 <= nc && nc <= 4){
            s += MAP[nr][nc];
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int s = 0, M=0, M_r, M_c;
    for (int r=0; r<5; r++){
        for (int c=0; c<5; c++){
            s = sum(r, c);
            if (s > M){
                M_r = r;
                M_c = c;
                M = s;
            }
        }
    }
    
    cout << M_r << " " << M_c << "\n";

    return 0;
} 
