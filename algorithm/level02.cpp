#include <iostream>
using namespace std;

int main(){
    char arr[6] = {'A', 'P', 'P', 'L', 'E', 'T'};
    char a[5];
    int cnt=0;

    for (int i=0; i<5; i++){
        cin >> a[i];
        for (int r=0; r<6; r++){
            if (arr[r]==a[i]){
                cnt++;
            }
        }
    }

    cout << cnt << "개 맞추었습니다" << endl;

    return 0;
}