#include <iostream>

using namespace std;

int main(){
    int n=1;
    int arr[4][4]={0,};
    
    for (int c=3; c>=0; c--){
        for (int r=0; r<4; r++){
            arr[r][c] = n;
            n++;
        }
    }
    
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout << arr[i][j] << " " ;
        }
        cout << endl;
    }

    return 0;
}
