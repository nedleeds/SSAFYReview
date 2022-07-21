#include <iostream>
using namespace std;

int main(){
    char arr[3][5], a;
    
    cin >> a;

    for (int i=0; i<3; i++){
        for (int j=0; j<5; j++){
            arr[i][j] = a;
            a++;
        }
    }

    cout << char(arr[2][2]+('a'-'A')) << endl;

    return 0;
}
