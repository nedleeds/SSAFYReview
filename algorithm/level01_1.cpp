#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{3, 4, 1},
                     {2, 1, 4},
                     {3, 3, 0}};
    int cnt[2] = {0, 0}; 

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (arr[i][j]%2){
                cnt[0]++;
            }else{
                cnt[1]++;
            }
        }
    }
    cout << "짝수 : " << cnt[1] << endl;
    cout << "홀수 : " << cnt[0] << endl;
    return 0;
}