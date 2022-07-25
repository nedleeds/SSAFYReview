// !! youtube 시간 !!
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //문제 1
    // int arr[10];
    // int cnt[2] = {0};

    // for (int i = 0; i < 10; i++){
    //     cin >> arr[i];
    //     cnt[arr[i]]++;
    // }

    // cout << "0:" << cnt[0] << "\n";
    // cout << "1:" << cnt[1] << "\n";

    //문제 2
    // int cnt[10]={0};
    // for (int i=0; i<10; i++){
    //     int temp;
    //     cin >> temp;
    //     cnt[temp]++;
    // }

    // for (int i=0; i<10; i++){
    //     cout << i << ": " << cnt[i] << "\n";
    // }

    //문제 3
    // int arr[10] = {0};
    // for (int i=0; i<10; i++){
    //     int tmp;
    //     cin >> tmp;
    //     arr[tmp] = i;
    // }

    // for (int j=0; j<10; j++){
    //     cout << j << ":" << arr[j] << "\n";
    // }

    int MAP[10][10]{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 10, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int row, col;
    cin >> row >> col;
    if (MAP[row][col]){
        for (int i=0; i<MAP[row][col]; i++){
            cout << "BOOM!";
        }
        cout << "\n";
    }else{
        cout << "STILL ALIVE!\n";
    }

    return 0;
}