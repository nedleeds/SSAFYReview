#include <iostream>
using namespace std;

int main(){
    int arr[5][5], i=1, r_idx;

    for (int c=4; c>=0; c--){
        for (int r=0; r<5; r++){
            arr[r][c] = i++;
        }
    }

    cin >> r_idx;

    for (int c=0; c<5; c++){
        arr[r_idx][c] = r_idx;
    }
    
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
