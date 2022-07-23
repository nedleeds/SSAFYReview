#include <iostream>
using namespace std;

int main(){
    int arr[2][3];

    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            cin >> arr[r][c];
        }
    }

    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c] == 0){
                cout << '#';
            }else{
                cout << arr[r][c];
            }
        }
        cout << endl;
    }

    return 0;
}