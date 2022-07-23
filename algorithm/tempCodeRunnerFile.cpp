#include <iostream>
using namespace std;

int main(){
    int r;
    char x, arr[5][5]={'0'};
    
    cin >> r >> x;

    for (int c=4; c>=0; c--){
        arr[r-1][c] = x++;
    }

    for (int r=0; r<5; r++){
        for (int c=0; c<5; c++){
            cout << arr[r][c];
        }
        cout << endl;
    }

    return 0;
}