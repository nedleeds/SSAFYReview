// !! youtube 시간 !!
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    // 문제 1
    // input1: 0 1 0 0 1 1 0 1 0 1
    // input2:(1~8) 사이의 10개 숫자.
    // 만약 (0~9)일 경우 -> -1, 10 index 접근 -> 에러.
    // int arr[10], n;
    // for (int i=0; i<10; i++){
    //     cin >> arr[i];
    // }
    // cin >> n;
    
    // if (n==0){
    //     cout << arr[n]+arr[n+1] << "개\n";
    // }else if(n==9){
    //     cout << arr[n]+arr[n-1] << "개\n";
    // }else{
    //     cout << arr[n-1]+arr[n]+arr[n+1] << "개\n";
    // }

    // 문제 2 - 해당 Row, col 주변 확인.
    int MAP[10][10]{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 10, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int row, col;
    int d[5][2]={
        // 상하좌우
        {-1, 0},
        {0, 1},
        {0, 0},
        {0, -1},
        {1, 0}
    };

    cin >> row >> col;
    int s = 0, dist=0;
    // dist 문 추가.
    cin >> dist;

    for (int j=1; j<dist; j++){
        for (int i=0; i<5; i++){
            int nr = row + d[i][0]*j;
            int nc = col + d[i][1]*j;
            int value = MAP[nr][nc];
            if ((0 <= nr && nr < 10) && (0 <= nc && nc < 10)){
                if ( value > 0 ){
                    s += value;
                }
            }
        }
        
        if (s > 0){
            for (int i=0; i<s; i++){
                cout << "BOOM!\n";
            }
        }else{
            cout << "STILL ALIVE!\n";
        }
    }

    return 0;
}