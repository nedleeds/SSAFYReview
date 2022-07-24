#include <iostream>
#include <string>
using namespace std;


int main(){

    int waffle[3][3];
    int s = 0;

    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            cin >> waffle[r][c];
        }
    }
    for (int r=0; r<3; r++){
        for (int c=0; c<r+1; c++){
            s += waffle[r][c];
        }
    }

    cout << s << endl;

    return 0;
}