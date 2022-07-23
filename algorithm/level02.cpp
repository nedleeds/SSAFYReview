#include <iostream>
using namespace std;
int main(){
    int in[3];
    int arr[3][4];

    cin >> in[0] >> in[1] >> in[2];
    
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            arr[r][c] = in[r]+c;
        }
    }
    
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
