#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    for (int j=0; j<c; j++){
        for (int i=0; i<b; i++){
            cout << a+i << " ";
        }
        cout << endl;
    }

    return 0;
}