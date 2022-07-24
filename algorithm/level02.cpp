#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[3][5]={
        {5, 1, 4, 2, 6},
        {3, 5, 0, 0, 7},
        {9, 9, 8, 3, 1}
    };
    int n, cnt=0;

    cin >> n;

    for (int r=0; r<3; r++){
        for (int c=0; c<5; c++){
            if (arr[r][c] > n){
                cnt++;
            }
        }
    }
    cout << cnt << "개" << endl;

    return 0;
}