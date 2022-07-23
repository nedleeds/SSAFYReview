#include <iostream>
#include <string>
using namespace std;

int main(){
    char arr[2][6] = {
        {'4', '5', '7', '1', '3', '2'},
        {'D', 'F', 'Q', 'W', 'G', 'Z'}
    };

    char n;
    cin >> n;

    
    for (int c=0; c<6; c++){
        if (arr[0][c] == n){
            cout << arr[1][c] << endl;
        }
    }

    
    return 0;
}