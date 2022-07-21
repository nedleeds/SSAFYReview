#include <iostream>
using namespace std;


int main(){
    char a, b;
    int n;

    cin >> a >> b >> n;

    for (int j=0; j<n; j++){
        for (char i=a; i<=b; i++){
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
