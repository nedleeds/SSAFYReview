#include <iostream>
using namespace std;

int main(){
    char x, y;
    cin >> x >> y;

    for (int i=0; i<4; i++){
        for (int j=x; j<=y; j++){
            cout << char(j) << " ";
        }
        cout << endl;
    }

    return 0;
}