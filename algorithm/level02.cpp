#include <iostream>
#include <string>
using namespace std;

int main(){

    int arr[5][4];

    for (int r=0; r<5; r++){
        for (int c=0; c<4; c++){
            cin >> arr[r][c];
        }
    }

    for (int r=0; r<5; r++){
        int s = 0;
        for (int c=0; c<4; c++){
            s += arr[r][c];
        }
        cout << s << " ";
    }
    cout << endl;

    return 0;
}