#include <iostream>
#include <string>
using namespace std;


int main(){

    char arr[5];

    for (int i=0; i<5; i++){
        cin >> arr[i];
    }

    for (int r=0; r<5; r++){
        for (int c=r; c<5; c++){
            cout << arr[c] << " ";
        }
        cout << endl;
    }

    return 0;
}