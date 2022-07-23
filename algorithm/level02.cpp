#include <iostream>
#include <string>
using namespace std;

int main(){
    int x;

    cin >> x;

    for (int r=0; r<4; r++){
        for (int c=0; c<4; c++){
            cout << x ;
        }
        cout << endl;
        x--;
    }
    
    return 0;
}