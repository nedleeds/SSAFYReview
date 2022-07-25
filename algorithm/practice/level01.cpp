#include <iostream>
using namespace std;


int main(){
    char arr[3][6];
    char x, y;

    cin >> x >> y;

    for (int r=0; r<3; r++){
        for (int c=0; c<6; c++){
            if (c<4){
                arr[r][c] = x;
            }else{
                arr[r][c] = y;
            }
        }
    }

    for (int r=0; r<3; r++){
        for (int c=0; c<6; c++){
            cout << arr[r][c];
        }
        cout << endl;
    }

    return 0;
}
