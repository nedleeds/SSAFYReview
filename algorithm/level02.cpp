#include <iostream>

using namespace std;

int main(){
    int col;
    int x = 1;
    int arr[3][4]={0};
    
    cin >> col; 
    
    for (int r=2; r>=0; r--){
        for (int c=3; c>-1; c--){
            // cout << r << c << endl;
            arr[r][c] = x++;
            if (c==col){
                arr[r][c] = 0;
            }
        }
    }
    
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
