#include <iostream>
using namespace std;


int main(){
    int arr[6][3];
    int x, y;

    cin >> x >> y;

    for (int i=0; i<6; i++){
        if (i<3){
            for (int j=0; j<3; j++){
                arr[i][j] = x;
            }
        }else{
            for (int j=0; j<3; j++){
                arr[i][j] = y;
            }
        }
    }

    for (int r=0; r<6; r++){
        for (int c=0; c<3; c++){
            cout << arr[r][c];
        }
        cout << endl;
    }

    return 0;
}
