#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[3][3]={0}, x;

    cin >> x;
    for (int r=0; r<3; r++){
        for (int c=2-r; c<3; c++){
            arr[r][c] = x++;
        }
    }

    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            cout << arr[r][c];
        }
        cout << endl;
    }

    return 0;
}