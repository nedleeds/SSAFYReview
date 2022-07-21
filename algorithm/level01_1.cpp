#include <iostream>
using namespace std;

int main(){
    int arr[3][2], a;
    
    for (int r=0; r<3; r++){
        for (int c=0; c<2; c++){
            cin >> a;
            arr[r][c] = a + 2;
        }
    }
    for (int r=0; r<3; r++){
        for (int c=0; c<2; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
