#include <iostream>
using namespace std;


int main(){
    int arr[3][3] = {0,};
    int r, c, v;

    cin >> r >> c >> v;

    arr[r][c] = v;

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
