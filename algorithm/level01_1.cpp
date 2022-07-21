#include <iostream>
using namespace std;

int main(){
    char a;
    char arr[4][4];

    cin >> a;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            arr[i][j] = a;
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
