#include <iostream>
#include <string>
using namespace std;

char arr[4][3] = {
    {'D', 'A', 'D'},
    {'Q', 'W', 'Q'},
    {'A', 'S', 'D'},
    {'A', 'S', 'D'},
};

int main(){
    char x;
    int cnt=0;

    cin >> x;

    for (int r=0; r<4; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c]==x){
                cout << "존재" << endl;
                return 0;
            }
        }
    }
    cout << "없음" << endl;
    return 0;
}