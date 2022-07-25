#include <iostream>
using namespace std;

int main(){
    int arr[4][4], n;
    cin >> n;

    for (int r=0; r<4; r++){
        if (r%2==0){
            for (int c=0; c<4; c++){
                arr[r][c] = n++;
            }
        }else{
            for (int c=3; c>=0; c--){
                arr[r][c] = n++;
            }
        }
    }

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}