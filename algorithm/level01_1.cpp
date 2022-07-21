#include <iostream>
using namespace std;

int main(){
    int arr[3][4] = {{4, 3, 1, 1},
                     {3, 1, 2, 1},
                     {0, 0, 1, 2}};

    int n, cnt = 0;
    cin >> n;

    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            if(arr[i][j] == n){
                cnt += 1;
            }
        }
    }
    
    cout << cnt << "개 존재합니다" << endl;

    return 0;
}
