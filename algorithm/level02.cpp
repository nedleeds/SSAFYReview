#include <iostream>
#include <string>
using namespace std;

void find(char *c_, char arr[3][3]){
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c] == *c_){
                cout << r << "," << c << endl;
            }
        }
    }
}

int main(){
    char arr[3][3] = {
        {'A', 'D', 'F'},
        {'Q', 'W', 'E'},
        {'Z', 'X', 'C'}
    };

    char c;
    cin >> c;

    find(&c, arr);

    return 0;
}