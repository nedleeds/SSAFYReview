#include <iostream>

using namespace std;

int main()
{
    int a, arr[3][3];
    
    cin >> a;
    
    if (a%5 == 1){
        arr[0][0] = 9;
        arr[0][1] = 6;
        arr[0][2] = 9;
        arr[1][0] = 8;
        arr[1][1] = 5;
        arr[1][2] = 2;
        arr[2][0] = 7;
        arr[2][1] = 4;
        arr[2][2] = 1;
    }else if(a%5 == 2){
        arr[0][0] = 7;
        arr[0][1] = 8;
        arr[0][2] = 9;
        arr[1][0] = 4;
        arr[1][1] = 5;
        arr[1][2] = 6;
        arr[2][0] = 1;
        arr[2][1] = 2;
        arr[2][2] = 3;
    }else{
        arr[0][0] = 10;
        arr[0][1] = 13;
        arr[0][2] = 16;
        arr[1][0] = 11;
        arr[1][1] = 14;
        arr[1][2] = 17;
        arr[2][0] = 12;
        arr[2][1] = 15;
        arr[2][2] = 18;
    }
    
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}