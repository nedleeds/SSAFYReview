#include <iostream>
using namespace std;

int main(){
    int arr[4][4], i=1;

    for (int c=0; c<4; c++){
        for (int r=0; r<4; r++){
            arr[r][c] = (i*2);
            i++;
        }
    }

    for (int r=0; r<4; r++){
        for (int c=0; c<4; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
