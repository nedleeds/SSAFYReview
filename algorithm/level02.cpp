#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int arr[3][3] = {
        {3, 1, 6},
        {7, 8, 4},
        {9, 2, 3}
    };

    cin >> a >> b >> c;

    arr[a][b] = c;

    int M=0, m=9999;
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c] > M){
                M = arr[r][c];
            }else if (arr[r][c] < m){
                m = arr[r][c];
            }
        }
    }

    cout << M+m << endl;

    return 0;
}