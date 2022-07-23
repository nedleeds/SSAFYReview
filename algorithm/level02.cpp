#include <iostream>

using namespace std;

int main(){
    int arr[4][4];

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }

    for (int r=0; r<4; r++){
        for (int c=0; c<4; c++){
            if (arr[r][c]%2==0 && arr[r][c]!=0){
                cout << "#";
            }else if (arr[r][c]%2){
                cout << "@";
            }else if (arr[r][c]==0){
                cout << "!";
            }
            
        }
        cout << endl;
    }

    return 0;
}
