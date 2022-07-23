#include <iostream>
using namespace std;

int main(){
    int num[6], arr[2][3];
    
    for (int r=1; r>=0; r--){
        for (int c=2; c>=0; c--){
            cin >> arr[r][c];
        }
    }

    int idx = 0;
    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            num[idx++] = arr[r][c];
        }
    }

    int tmp=num[0];

    num[0] = num[5];
    num[5] = tmp;

    for (int i=0; i<6; i++){
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}