#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[3][4]={0};
    int i = 1, x;

    for (int r=2; r>=0; r--){
        for (int c=3; c>=0; c--){
            arr[r][c] = i++;
        }
    }

    cin >> x;
    for (int c=0; c<4; c++){
        arr[x-1][c] = 7;
    }
    
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    

    return 0;
}