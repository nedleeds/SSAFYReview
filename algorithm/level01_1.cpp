#include <iostream>
using namespace std;


int main(){
    int a, b, c;
    cin >> a >> b >> c;

    for (int j=0; j<c; j++){
        for (int i=a; i<=b; i++){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}