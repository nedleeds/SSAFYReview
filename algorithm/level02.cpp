#include <iostream>
using namespace std;

int main(){
    char arr[3][5] = {
        {'F', 'R', 'Q', 'W', 'T'},
        {'G', 'A', 'S', 'Y', 'Q'},
        {'A', 'S', 'A', 'D', 'B'},
    };

    int n;
    cin >> n;

    for (int r=0; r<3; r++){
        cout << arr[r][n];
    }
    cout << endl;

    return 0;
}