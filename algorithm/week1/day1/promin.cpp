#include <iostream>
using namespace std;

int arr[3][3] = {
    {3, 5, 4}, 
    {1, 1, 2}, 
    {1, 3, 9} 
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int r, c;
    cin >> r >> c;

    int dir[4][2] = {
        {-1, 0},
        { 1, 0},
        { 0,-1},
        { 0, 1}
    };

    int s = 0;
    for (int i = 0; i<4; i++){
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];

        if (0 <= nr && nr <=3 && 0 <= nc && nc <= 3){
            s += arr[nr][nc];
        }
    }
    
    cout << s << "\n";

    return 0;
} 
